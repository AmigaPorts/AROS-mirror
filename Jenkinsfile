def notify(status){
	emailext (
		body: '$DEFAULT_CONTENT',
		recipientProviders: [
			[$class: 'CulpritsRecipientProvider'],
			[$class: 'DevelopersRecipientProvider'],
			[$class: 'RequesterRecipientProvider']
		],
		replyTo: '$DEFAULT_REPLYTO',
		subject: '$DEFAULT_SUBJECT',
		to: '$DEFAULT_RECIPIENTS'
	)
}

@NonCPS
def killall_jobs() {
	def jobname = env.JOB_NAME
	def buildnum = env.BUILD_NUMBER.toInteger()
	def killnums = ""
	def job = Jenkins.instance.getItemByFullName(jobname)
	def fixed_job_name = env.JOB_NAME.replace('%2F','/')

	for (build in job.builds) {
		if (!build.isBuilding()) { continue; }
		if (buildnum == build.getNumber().toInteger()) { continue; println "equals" }
		if (buildnum < build.getNumber().toInteger()) { continue; println "newer" }

		echo "Kill task = ${build}"

		killnums += "#" + build.getNumber().toInteger() + ", "

		build.doStop();
	}

	if (killnums != "") {
		slackSend color: "danger", channel: "#jenkins", message: "Killing task(s) ${fixed_job_name} ${killnums} in favor of #${buildnum}, ignore following failed builds for ${killnums}"
	}
	echo "Done killing"
}

def buildStep(ext, iconset = 'default', binutilsver = '2.32', gccver = '9.1.0', nativetarget = true, contrib = 'contrib', configureextras = '', sfx = '', buildtype = 'nightly') {
	def fixed_job_name = env.JOB_NAME.replace('%2F','/')
	def commondir = env.WORKSPACE + '/../' + env.JOB_NAME.replace('%2F','/') + '/'


	stage("Building ${ext}${sfx} with gcc ${gccver} and binutils ${binutilsver}...") {
		properties([pipelineTriggers([githubPush()])])
		if (env.CHANGE_ID) {
			echo 'Trying to build pull request'
		}

		def dockerImageRef = docker.image("amigadev/docker-base")
		dockerImageRef.pull()

		dockerImageRef.inside("-u 0:0 -u root -w /tmp/work -v ${commondir}/tools-${ext}${sfx}-${gccver}-${binutilsver}:/tools -v ${commondir}/externalsources-${ext}${sfx}-${gccver}-${binutilsver}:/externalsources") {
			try{
				sh "mkdir -p /tmp/work"

				checkout scm

				if (!env.CHANGE_ID) {
					sh "rm -rfv publishing/deploy/*"
					sh "mkdir -p publishing/deploy/aros"
				}

				slackSend color: "good", channel: "#jenkins", message: "Starting ${ext} build target..."

				freshUpRoot(ext, binutilsver, gccver, sfx)

				sh "cd /tmp/work && ${env.WORKSPACE}/AROS/configure --target=${ext} ${configureextras} --enable-ccache --with-iconset=${iconset} --enable-build-type=${buildtype} --with-binutils-version=${binutilsver} --with-gcc-version=${gccver} --with-aros-toolchain-install=/tools --with-portssources=/externalsources"

				sh "cd /tmp/work && make -j8"

				if (!nativetarget) {
					sh "cd /tmp/work && make -j8 default-x11keymaptable"
				}

				postCoreBuild(ext)

				sh "cd /tmp/work && make -j8 ${contrib}"

				sh "cd /tmp/work && make distfiles"

				if (!env.CHANGE_ID) {
					sh "mkdir -p ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/"

					sh "echo '${env.BUILD_NUMBER}|${env.BUILD_URL}' > ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/BUILD"

					sh "cp -pRL ${env.WORKSPACE}/AROS/LICENSE ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/"
					sh "cp -pRL ${env.WORKSPACE}/AROS/ACKNOWLEDGEMENTS ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/"

					if (nativetarget) {
						sh "cp -fvr /tmp/work/distfiles/* ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/"

						//sh "rm -rfv ${env.WORKSPACE}/publishing/deploy/aros/${ext}-${gccver}-${binutilsver}/*.elf" // Can't remember what this is good for...
					} else {
						sh "cp -fvr /tmp/work/bin/${ext}/AROS ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/"
						sh "cd ${env.WORKSPACE}/publishing/deploy/aros/${ext}-${gccver}-${binutilsver}/ && tar -Jcvvf ${ext}${sfx}-hosted.tar.xz *"
						sh "rm -fvr ${env.WORKSPACE}/publishing/deploy/aros/${ext}${sfx}-${gccver}-${binutilsver}/AROS"
					}
				}
				stash includes: "publishing/deploy/aros/**", name: "${ext}${sfx}-${gccver}-${binutilsver}"
				slackSend color: "good", channel: "#jenkins", message: "Build ${fixed_job_name} #${env.BUILD_NUMBER} Target: ${ext}${sfx} GCC: ${gccver} Binutils: ${binutilsver} successful!"

				sh "rm -rf ${env.WORKSPACE}/*"
			} catch(err) {
				sh "rm -rf ${env.WORKSPACE}/*"
				//sh "rm -rf /tmp/work"
				//sh "rm -rf /externalsources/*"
				slackSend color: "danger", channel: "#jenkins", message: "Build Failed: ${fixed_job_name} #${env.BUILD_NUMBER} Target: ${ext}${sfx} GCC: ${gccver} (<${env.BUILD_URL}|Open>)"
				currentBuild.result = 'FAILURE'
				notify('Build failed')
				//throw err
			}
		}
	}
}

def freshUpRoot(ext, binutilsver, gccver, sfx) {
	def commondir = env.WORKSPACE + '/../' + env.JOB_NAME.replace('%2F','/') + '/'
	sh "rm -rfv /tmp/work/distfiles/*"
	// uncomment the following section to remove the whole toolchain and build:
	// sh "rm -rfv /tools/*"
}

def postCoreBuild(ext) {
	sh "cp -fvr ${env.WORKSPACE}/contrib ${env.WORKSPACE}/AROS/"
	sh "cp -fvr ${env.WORKSPACE}/ports ${env.WORKSPACE}/AROS/"
}

node('master') {
	killall_jobs()
	def fixed_job_name = env.JOB_NAME.replace('%2F','/')
	slackSend color: "good", channel: "#jenkins", message: "Build Started: ${fixed_job_name} #${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
	parallel (
		'Build Amiga 68000 version - GCC 6.5.0 - Binutils 2.32': {
			node {
				buildStep('amiga-m68k', 'Gorilla', '2.32', '6.5.0', true, 'contrib-installerlg', '--with-aros-prefs=classic --with-serial-debug')
			}
		},
		'Build Vampire version - GCC 6.5.0 - Binutils 2.32': {
			node {
				buildStep('amiga-m68k', 'Gorilla', '2.32', '6.5.0', true, 'contrib-installerlg', '--with-aros-prefs=classic', '-vampire')
			}
		},
		'Build Amiga 68020 version - GCC 10 - Binutils 2.32': {
			node {
				buildStep('amiga-m68k', 'Gorilla', '2.32', '10-20200110', true, 'contrib-installerlg', '--with-aros-prefs=classic --with-cpu=68020','-68020')
			}
		},
		'Build Amiga 68020 HF version - GCC 10 - Binutils 2.32': {
			node {
				buildStep('amiga-m68k', 'Gorilla', '2.32', '10-20200110', true, 'contrib-installerlg', '--with-aros-prefs=classic --with-cpu=68040 --with-optimization="-O2 -mhard-float -fomit-frame-pointer"','-68040-O2-hard-float', 'release')
			}
		},
		'Build Amiga 68060 version - GCC 10 - Binutils 2.32': {
			node {
				buildStep('amiga-m68k', 'Gorilla', '2.32', '10-20200110', true, 'contrib-installerlg', '--with-aros-prefs=classic --with-cpu=68060','-68060')
			}
		},
		/*,
		'Build Linux Hosted x86_64 version - GCC 9.1.0 - Binutils 2.32': {
			node {
				buildStep('linux-x86_64', 'GorillaSmall', '2.32', '9.1.0', false, 'contrib-installerlg')
			}
		}*/
	)

	stage("Publishing") {
		sh "rm -rfv publishing/"

		try {
			// ${ext}${sfx}-${gccver}-${binutilsver}
			unstash "amiga-m68k-6.5.0-2.32"
		} catch(err) {
			notify('Stash not found')
		}
		
		try {
			unstash "amiga-m68k-vampire-6.5.0-2.32"
		} catch(err) {
			notify('Stash not found')
		}
		
		try {
			unstash "amiga-m68k-68020-10-20200110-2.32"
		} catch(err) {
			notify('Stash not found')
		}
		
		try {
			unstash "amiga-m68k-68040-O2-hard-float-10-20200110-2.32"
		} catch(err) {
			notify('Stash not found')
		}
		
		try {
			unstash "amiga-m68k-68060-10-20200110-2.32"
		} catch(err) {
			notify('Stash not found')
		}

		if (env.TAG_NAME) {
			sh "echo $TAG_NAME > publishing/deploy/STABLE"
			sh "ssh $DEPLOYHOST mkdir -p public_html/downloads/releases/aros/$TAG_NAME"
			sh "scp -r publishing/deploy/aros/* $DEPLOYHOST:~/public_html/downloads/releases/aros/$TAG_NAME/"
			sh "scp publishing/deploy/STABLE $DEPLOYHOST:~/public_html/downloads/releases/aros/"
		} else if (env.BRANCH_NAME.equals('ABI_V1')) {
			def deploy_url = sh (
				script: 'echo "nightly/aros/`date +\'%Y\'`/`date +\'%m\'`/`date +\'%d\'`/"',
				returnStdout: true
			).trim()
			sh "date +'%Y-%m-%d %H:%M:%S' > publishing/deploy/BUILDTIME"
			sh "ssh $DEPLOYHOST mkdir -p public_html/downloads/nightly/aros/`date +'%Y'`/`date +'%m'`/`date +'%d'`/"
			sh "scp -r publishing/deploy/aros/* $DEPLOYHOST:~/public_html/downloads/nightly/aros/`date +'%Y'`/`date +'%m'`/`date +'%d'`/"
			sh "scp publishing/deploy/BUILDTIME $DEPLOYHOST:~/public_html/downloads/nightly/aros/"

			slackSend color: "good", channel: "#aros", message: "New ${fixed_job_name} build #${env.BUILD_NUMBER} to web (<https://dl.amigadev.com/${deploy_url}|https://dl.amigadev.com/${deploy_url}>)"
			ircNotify targets: "#aros_caffeine", customMessage: "New ${fixed_job_name} build #${env.BUILD_NUMBER} to web: https://dl.amigadev.com/${deploy_url}"
		} else if (env.BRANCH_NAME.equals('ABI_V1_experimental')) {
			def deploy_url = sh (
				script: 'echo "nightly/aros-experimental/`date +\'%Y\'`/`date +\'%m\'`/`date +\'%d\'`/"',
				returnStdout: true
			).trim()
			sh "date +'%Y-%m-%d %H:%M:%S' > publishing/deploy/BUILDTIME"
			sh "ssh $DEPLOYHOST mkdir -p public_html/downloads/nightly/aros-experimental/`date +'%Y'`/`date +'%m'`/`date +'%d'`/"
			sh "scp -r publishing/deploy/aros/* $DEPLOYHOST:~/public_html/downloads/nightly/aros-experimental/`date +'%Y'`/`date +'%m'`/`date +'%d'`/"
			sh "scp publishing/deploy/BUILDTIME $DEPLOYHOST:~/public_html/downloads/nightly/aros-experimental/"

			slackSend color: "good", channel: "#jenkins", message: "Deploying ${fixed_job_name} #${env.BUILD_NUMBER} to web (<https://dl.amigadev.com/${deploy_url}|https://dl.amigadev.com/${deploy_url}>)"
			ircNotify targets: "#aros_caffeine", customMessage: "New ${fixed_job_name} build #${env.BUILD_NUMBER} to web: https://dl.amigadev.com/${deploy_url}"
		}
	}
}
