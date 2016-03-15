#ifndef IDENTIFY_INTERFACE_DEF_H
#define IDENTIFY_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 51.8.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif


struct IdentifyIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct IdentifyIFace *Self);
	ULONG APICALL (*Release)(struct IdentifyIFace *Self);
	void APICALL (*Expunge)(struct IdentifyIFace *Self);
	struct Interface * APICALL (*Clone)(struct IdentifyIFace *Self);
	LONG APICALL (*IdExpansion)(struct IdentifyIFace *Self, struct TagItem * TagList);
	LONG APICALL (*IdExpansionTags)(struct IdentifyIFace *Self, ...);
	STRPTR APICALL (*IdHardware)(struct IdentifyIFace *Self, ULONG Type, struct TagItem * TagList);
	STRPTR APICALL (*IdHardwareTags)(struct IdentifyIFace *Self, ULONG Type, ...);
	LONG APICALL (*IdAlert)(struct IdentifyIFace *Self, ULONG ID, struct TagItem * TagList);
	LONG APICALL (*IdAlertTags)(struct IdentifyIFace *Self, ULONG ID, ...);
	LONG APICALL (*IdFunction)(struct IdentifyIFace *Self, STRPTR LibName, LONG Offset, struct TagItem * TagList);
	LONG APICALL (*IdFunctionTags)(struct IdentifyIFace *Self, STRPTR LibName, LONG Offset, ...);
	IPTR APICALL (*IdHardwareNum)(struct IdentifyIFace *Self, ULONG Type, struct TagItem * TagList);
	ULONG APICALL (*IdHardwareNumTags)(struct IdentifyIFace *Self, ULONG Type, ...);
	void APICALL (*IdHardwareUpdate)(struct IdentifyIFace *Self);
	ULONG APICALL (*IdFormatString)(struct IdentifyIFace *Self, STRPTR String, STRPTR Buffer, ULONG Length, struct TagItem * Tags);
	ULONG APICALL (*IdFormatStringTags)(struct IdentifyIFace *Self, STRPTR String, STRPTR Buffer, ULONG Length, ...);
	ULONG APICALL (*IdEstimateFormatSize)(struct IdentifyIFace *Self, STRPTR String, struct TagItem * Tags);
	ULONG APICALL (*IdEstimateFormatSizeTags)(struct IdentifyIFace *Self, STRPTR String, ...);
};

#endif /* IDENTIFY_INTERFACE_DEF_H */