/*
 *  Source machine generated by GadToolsBox V1.4
 *  which is (c) Copyright 1991,92 Jaba Development
 */

#include "shuffle.h"

struct Screen         *Scr = NULL;
UBYTE                 *PubScreenName = "Workbench";
APTR                   VisualInfo = NULL;
struct Window         *Project0Wnd = NULL;
struct Gadget         *Project0GList = NULL;
struct IntuiMessage    Project0Msg;
struct Menu           *Project0Menus = NULL;
struct Gadget         *Project0Gadgets[5];
UWORD                  Project0Left = 10;
UWORD                  Project0Top = 15;
UWORD                  Project0Width = 368;
UWORD                  Project0Height = 63;
UBYTE                 *Project0Wdt = (UBYTE *)"Shuffle V1.1";
struct TextAttr       *Font, Attr;
UWORD                  FontX, FontY;
UWORD                  OffX, OffY;

UBYTE *tiles0Labels[NUMTILES + 1] = {
	(UBYTE *)"8 X 8",
	(UBYTE *)"16 X 8",
	(UBYTE *)"16 X 16",
	(UBYTE *)"4 X 4",
	(UBYTE *)"8 X 4",
	NULL };

UBYTE *shuffle0Labels[NUMSHUFFLES + 1] = {
	(UBYTE *)"100",
	(UBYTE *)"80",
	(UBYTE *)"60",
	(UBYTE *)"40",
	(UBYTE *)"20",
 (UBYTE *)"5",
 (UBYTE *)"3",
 NULL
 };

UBYTE *mode0Labels[] = {
	(UBYTE *)"Move Tiles",
	(UBYTE *)"Move Gap",
	NULL };


struct NewMenu Project0NewMenu[] = {
	NM_TITLE, (STRPTR)"Project", NULL, 0, NULL, NULL,
	NM_ITEM, (STRPTR)"Load...", (STRPTR)"L", 0, 0L, (APTR)Project0loadconfig,
	NM_ITEM, (STRPTR)"Save", (STRPTR)"C", 0, 0L, (APTR)Project0saveconfig,
 NM_ITEM, (STRPTR)"Save as...", (STRPTR)"S", 0, 0L, (APTR)Project0saveasconfig,
	NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL,
	NM_ITEM, (STRPTR)"Save as default", (STRPTR)"D", 0, 0L, (APTR)Project0savedefault,
	NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL,
	NM_ITEM, (STRPTR)"About...", (STRPTR)"A", 0, 0L, (APTR)Project0about,
	NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL,
	NM_ITEM, (STRPTR)"Quit", (STRPTR)"Q", 0, 0L, (APTR)Project0quit,
 NM_TITLE, (STRPTR)"Options", NULL, 0, NULL, NULL,
 NM_ITEM, (STRPTR)"Write Icons", (STRPTR)"I",CHECKIT | MENUTOGGLE | CHECKED , 0L, (APTR)Project0Icon,
	NM_END, NULL, NULL, 0, 0L, NULL };

UWORD Project0GTypes[] = {
	BUTTON_KIND,
	CYCLE_KIND,
	CYCLE_KIND,
	CHECKBOX_KIND,
	CYCLE_KIND
};

struct NewGadget Project0NGad[] = {
	14, 4, 346, 14, (UBYTE *)"_Start", NULL, GD_start, PLACETEXT_IN, NULL, (APTR)startClicked,
	14, 24, 136, 15, (UBYTE *)"_Tiles", NULL, GD_tiles, PLACETEXT_RIGHT, NULL, (APTR)tilesClicked,
	278, 24, 82, 15, (UBYTE *)"Shu_ffle", NULL, GD_shuffle, PLACETEXT_LEFT, NULL, (APTR)shuffleClicked,
	278, 44, 26, 11, (UBYTE *)"_Numbers", NULL, GD_numbers, PLACETEXT_LEFT, NULL, (APTR)numbersClicked,
	14, 41, 136, 15, (UBYTE *)"_Mode", NULL, GD_mode, PLACETEXT_RIGHT, NULL, (APTR)modeClicked
};

ULONG Project0GTags[] = {
	(GT_Underscore), '_', (TAG_DONE),
	(GTCY_Labels), (ULONG)&tiles0Labels[ 0 ], (GT_Underscore), '_', (TAG_DONE),
	(GTCY_Labels), (ULONG)&shuffle0Labels[ 0 ], (GT_Underscore), '_', (TAG_DONE),
	(GTCB_Checked), TRUE, (GT_Underscore), '_', (TAG_DONE),
	(GTCY_Labels), (ULONG)&mode0Labels[ 0 ], (GT_Underscore), '_', (TAG_DONE)
};


static UWORD ComputeX( UWORD value )
{
	return(( UWORD )((( FontX * value ) + 4 ) / 8 ));
}

static UWORD ComputeY( UWORD value )
{
	return(( UWORD )((( FontY * value ) + 4 ) / 8 ));
}

static void ComputeFont( UWORD width, UWORD height )
{
	Font = &Attr;
	Font->ta_Name = (STRPTR)GfxBase->DefaultFont->tf_Message.mn_Node.ln_Name;
	Font->ta_YSize = FontY = GfxBase->DefaultFont->tf_YSize;
	FontX = GfxBase->DefaultFont->tf_XSize;

	OffX = Scr->WBorLeft;
	OffY = Scr->RastPort.TxHeight + Scr->WBorTop + 1;

	if ( width && height ) {
		if (( ComputeX( width ) + OffX + Scr->WBorRight ) > Scr->Width )
			goto UseTopaz;
		if (( ComputeY( height ) + OffY + Scr->WBorBottom ) > Scr->Height )
			goto UseTopaz;
	}
	return;

UseTopaz:
	Font->ta_Name = (STRPTR)"topaz.font";
	FontX = FontY = Font->ta_YSize = 8;
}

int SetupScreen( void )
{
	if ( ! ( Scr = LockPubScreen( PubScreenName )))
		return( 1L );

	ComputeFont( 0, 0 );

	if ( ! ( VisualInfo = GetVisualInfo( Scr, TAG_DONE )))
		return( 2L );
      
	if ( ! ( info.dri = GetScreenDrawInfo( Scr )))
		return( 3L );
 
	return( 0L );
}

void CloseDownScreen( void )
{
     if(info.dri)
     {
      FreeScreenDrawInfo(Scr,info.dri);
      info.dri = NULL;
     }
	if ( VisualInfo ) {
		FreeVisualInfo( VisualInfo );
		VisualInfo = NULL;
	}

	if ( Scr        ) {
		UnlockPubScreen( NULL, Scr );
		Scr = NULL;
	}
}

int HandleProject0IDCMP( void )
{
	struct IntuiMessage	*m;
 struct MenuItem		*n;
	int			(*func)(void);
	int			running = TRUE;

	while( m = GT_GetIMsg( Project0Wnd->UserPort )) {

		CopyMem(( char * )m, ( char * )&Project0Msg, (long)sizeof( struct IntuiMessage ));

		GT_ReplyIMsg( m );

		switch ( Project0Msg.Class ) {

			case	IDCMP_REFRESHWINDOW:
				GT_BeginRefresh( Project0Wnd );
				GT_EndRefresh( Project0Wnd, TRUE );
				break;

			case	IDCMP_CLOSEWINDOW:
				running = Project0CloseWindow();
				break;
  
   case	IDCMP_VANILLAKEY:
				running = Project0VanillaKey();
				break;

			case	IDCMP_GADGETUP:
				func = ( void * )(( struct Gadget * )Project0Msg.IAddress )->UserData;
				running = func();
				break;
   case	IDCMP_MENUPICK:
				while( Project0Msg.Code != MENUNULL )
    {
					n = ItemAddress( Project0Menus, Project0Msg.Code );
					func = (void *)(GTMENUITEM_USERDATA( n ));
					running = func();
					Project0Msg.Code = n->NextSelect;
    }
   	break;
		}
	}
	return( running );
}

int OpenProject0Window( void )
{
	struct NewGadget	ng;
	struct Gadget	*g;
	UWORD		lc, tc;
	UWORD		wleft = Project0Left, wtop = Project0Top, ww, wh;

	ComputeFont( Project0Width, Project0Height );

	ww = ComputeX( Project0Width );
	wh = ComputeY( Project0Height );

	if (( wleft + ww + OffX + Scr->WBorRight ) > Scr->Width ) wleft = Scr->Width - ww;
	if (( wtop + wh + OffY + Scr->WBorBottom ) > Scr->Height ) wtop = Scr->Height - wh;

	if ( ! ( g = CreateContext( &Project0GList )))
		return( 1L );

	for( lc = 0, tc = 0; lc < Project0_CNT; lc++ ) {

		CopyMem((char * )&Project0NGad[ lc ], (char * )&ng, (long)sizeof( struct NewGadget ));

		ng.ng_VisualInfo = VisualInfo;
		ng.ng_TextAttr   = Font;
		ng.ng_LeftEdge   = OffX + ComputeX( ng.ng_LeftEdge );
		ng.ng_TopEdge    = OffY + ComputeY( ng.ng_TopEdge );
		ng.ng_Width      = ComputeX( ng.ng_Width );
		ng.ng_Height     = ComputeY( ng.ng_Height);

		Project0Gadgets[ lc ] = g = CreateGadgetA((ULONG)Project0GTypes[ lc ], g, &ng, ( struct TagItem * )&Project0GTags[ tc ] );

		while( Project0GTags[ tc ] ) tc += 2;
		tc++;

		if ( NOT g )
			return( 2L );
	}

	if ( ! ( Project0Menus = CreateMenus( Project0NewMenu, GTMN_FrontPen, 0L, TAG_DONE )))
		return( 3L );

	LayoutMenus( Project0Menus, VisualInfo, TAG_DONE );

	if ( ! ( Project0Wnd = OpenWindowTags( NULL,
				WA_Left,	wleft,
				WA_Top,		wtop,
				WA_Width,	ww + OffX + Scr->WBorRight,
				WA_Height,	wh + OffY + Scr->WBorBottom,
				WA_IDCMP,	IDCMP_MENUPICK|IDCMP_MOUSEBUTTONS | IDCMP_VANILLAKEY|BUTTONIDCMP|CYCLEIDCMP|IDCMP_CLOSEWINDOW|IDCMP_REFRESHWINDOW,
				WA_Flags,	WFLG_ACTIVATE|WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_CLOSEGADGET|WFLG_SMART_REFRESH,
				WA_Gadgets,	Project0GList,
				WA_Title,	Project0Wdt,
				WA_ScreenTitle,	"Shuffle V1.1 Copyright (�)1993 by CEKASOFT All Rights Reserved",
				WA_AutoAdjust,	TRUE,
				TAG_DONE )))
	return( 4L );

 SetMenuStrip( Project0Wnd, Project0Menus );
	GT_RefreshWindow( Project0Wnd, NULL );

	return( 0L );
}

void CloseProject0Window( void )
{
	if ( Project0Wnd        ) {
		CloseWindow( Project0Wnd );
		Project0Wnd = NULL;
	}

	if ( Project0GList      ) {
		FreeGadgets( Project0GList );
		Project0GList = NULL;
	}
}
