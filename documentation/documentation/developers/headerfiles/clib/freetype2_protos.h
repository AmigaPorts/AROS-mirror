#ifndef CLIB_FREETYPE2_PROTOS_H
#define CLIB_FREETYPE2_PROTOS_H

/*
    *** Automatically generated from '/home/mazze/projects/aros-src/workbench/libs/freetype/src/freetype2.conf'. Edits will be lost. ***
    Copyright � 1995-2010, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


#include <diskfont/glyph.h>
#include <utility/tagitem.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_IMAGE_H
#include FT_SYSTEM_H
#include FT_TYPES_H
#include FT_CACHE_H
#include FT_CACHE_IMAGE_H
#include FT_CACHE_SMALL_BITMAPS_H
#include FT_CACHE_CHARMAP_H
#include FT_TRIGONOMETRY_H
#include FT_MODULE_H
#include FT_LIST_H
#include FT_TRUETYPE_TABLES_H


__BEGIN_DECLS

AROS_LP0(struct GlyphEngine *, OpenEngine,
         LIBBASETYPEPTR, FreeType2Base, 5, FreeType2
);
AROS_LP1(void, CloseEngine,
         AROS_LPA(struct GlyphEngine *, ge, A0),
         LIBBASETYPEPTR, FreeType2Base, 6, FreeType2
);
AROS_LP2(ULONG, SetInfoA,
         AROS_LPA(struct GlyphEngine *, ge, A0),
         AROS_LPA(struct TagItem *, tags, A1),
         LIBBASETYPEPTR, FreeType2Base, 7, FreeType2
);
AROS_LP2(ULONG, ObtainInfoA,
         AROS_LPA(struct GlyphEngine *, ge, A0),
         AROS_LPA(struct TagItem *, tags, A1),
         LIBBASETYPEPTR, FreeType2Base, 8, FreeType2
);
AROS_LP2(ULONG, ReleaseInfoA,
         AROS_LPA(struct GlyphEngine *, ge, A0),
         AROS_LPA(struct TagItem *, tags, A1),
         LIBBASETYPEPTR, FreeType2Base, 9, FreeType2
);
FT_Error FT_Init_FreeType(FT_Library *alibrary);
FT_Error FT_Done_FreeType(FT_Library library);
void FT_Library_Version(FT_Library library, FT_Int *amajor, FT_Int *aminor, FT_Int *apatch);
FT_Error FT_New_Face(FT_Library library, const char *pathname, FT_Long face_index, FT_Face *aface);
FT_Error FT_Done_Face(FT_Face face);
FT_Error FT_New_Memory_Face(FT_Library library, const FT_Byte *file_base, FT_Long file_size, FT_Long face_index, FT_Face *aface);
FT_Error FT_Open_Face(FT_Library library, const FT_Open_Args *args, FT_Long face_index, FT_Face *aface);
FT_Error FT_Attach_File(FT_Face face, const char *filepathname);
FT_Error FT_Attach_Stream(FT_Face face, FT_Open_Args *parameters);
FT_Error FT_Set_Char_Size(FT_Face face, FT_F26Dot6 char_width, FT_F26Dot6 char_height, FT_UInt horz_resolution, FT_UInt vert_resolution);
FT_Error FT_Set_Pixel_Sizes(FT_Face face, FT_UInt pixel_width, FT_UInt pixel_height);
void FT_Set_Transform(FT_Face face, FT_Matrix *matrix, FT_Vector *delta);
FT_Error FT_Load_Glyph(FT_Face face, FT_UInt glyph_index, FT_Int32 load_flags);
FT_UInt FT_Get_Char_Index(FT_Face face, FT_ULong charcode);
FT_UInt FT_Get_Name_Index(FT_Face face, FT_String *glyph_name);
FT_Error FT_Load_Char(FT_Face face, FT_ULong char_code, FT_Int32 load_flags);
FT_Error FT_Render_Glyph(FT_GlyphSlot slot, FT_Render_Mode render_mode);
FT_Error FT_Get_Kerning(FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector *akerning);
FT_Error FT_Get_Glyph_Name(FT_Face face, FT_UInt glyph_index, FT_Pointer buffer, FT_UInt buffer_max);
const char * FT_Get_Postscript_Name(FT_Face face);
FT_Error FT_Select_Charmap(FT_Face face, FT_Encoding encoding);
FT_Error FT_Set_Charmap(FT_Face face, FT_CharMap charmap);
FT_ULong FT_Get_First_Char(FT_Face face, FT_UInt *agindex);
FT_ULong FT_Get_Next_Char(FT_Face face, FT_ULong charcode, FT_UInt *agindex);
FT_Error FT_Get_Glyph(FT_GlyphSlot slot, FT_Glyph *aglyph);
FT_Error FT_Glyph_Copy(FT_Glyph source, FT_Glyph *target);
FT_Error FT_Glyph_Transform(FT_Glyph glyph, FT_Matrix *matrix, FT_Vector *delta);
void FT_Glyph_Get_CBox(FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox *acbox);
FT_Error FT_Glyph_To_Bitmap(FT_Glyph *the_glyph, FT_Render_Mode render_mode, FT_Vector *origin, FT_Bool destroy);
void FT_Done_Glyph(FT_Glyph glyph);
FT_Error FT_New_Size(FT_Face face, FT_Size *asize);
FT_Error FT_Done_Size(FT_Size size);
FT_Error FT_Activate_Size(FT_Size size);
FT_Error FTC_Manager_New(FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager *amanager);
FT_Error FTC_Manager_Lookup_Face(FTC_Manager manager, FTC_FaceID face_id, FT_Face *aface);
FT_Error FTC_Manager_Lookup_Size(FTC_Manager manager, FTC_Font font, FT_Face *aface, FT_Size *asize);
void FTC_Node_Unref(FTC_Node node, FTC_Manager manager);
FT_Error FTC_ImageCache_New(FTC_Manager manager, FTC_ImageCache *acache);
FT_Error FTC_ImageCache_Lookup(FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph *aglyph, FTC_Node *anode);
FT_Error FTC_SBitCache_New(FTC_Manager manager, FTC_SBitCache *acache);
FT_Error FTC_SBitCache_Lookup(FTC_SBitCache cache, FTC_ImageType type, FT_UInt gindex, FTC_SBit *ansbit, FTC_Node *anode);
void FTC_Manager_Done(FTC_Manager manager);
void FTC_Manager_Reset(FTC_Manager manager);
FT_Error FTC_CMapCache_New(FTC_Manager manager, FTC_CMapCache *acache);
FT_UInt FTC_CMapCache_Lookup(FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code);
FT_Long FT_MulDiv(FT_Long a, FT_Long b, FT_Long c);
FT_Long FT_MulFix(FT_Long a, FT_Long b);
FT_Long FT_DivFix(FT_Long a, FT_Long b);
FT_Fixed FT_RoundFix(FT_Fixed a);
FT_Fixed FT_CeilFix(FT_Fixed a);
FT_Fixed FT_FloorFix(FT_Fixed a);
void FT_Vector_Transform(FT_Vector *vector, const FT_Matrix *matrix);
void FT_Matrix_Multiply(const FT_Matrix *a, FT_Matrix *b);
FT_Error FT_Matrix_Invert(FT_Matrix *matrix);
FT_Fixed FT_Sin(FT_Angle angle);
FT_Fixed FT_Cos(FT_Angle angle);
FT_Fixed FT_Tan(FT_Angle angle);
FT_Angle FT_Atan2(FT_Fixed dx, FT_Fixed dy);
FT_Angle FT_Angle_Diff(FT_Angle angle1, FT_Angle angle2);
void FT_Vector_Unit(FT_Vector *vec, FT_Angle angle);
void FT_Vector_Rotate(FT_Vector *vec, FT_Angle angle);
FT_Fixed FT_Vector_Length(FT_Vector *vec);
void FT_Vector_Polarize(FT_Vector *vec, FT_Fixed *length, FT_Angle *angle);
void FT_Vector_From_Polar(FT_Vector *vec, FT_Fixed length, FT_Angle angle);
void FT_List_Add(FT_List list, FT_ListNode node);
void FT_List_Insert(FT_List list, FT_ListNode node);
FT_ListNode FT_List_Find(FT_List list, void *data);
void FT_List_Remove(FT_List list, FT_ListNode node);
void FT_List_Up(FT_List list, FT_ListNode node);
FT_Error FT_List_Iterate(FT_List list, FT_List_Iterator iterator, void *user);
void FT_List_Finalize(FT_List list, FT_List_Destructor destroy, FT_Memory memory, void *user);
FT_Error FT_Outline_New(FT_Library library, FT_UInt numPoints, FT_Int numContours, FT_Outline *anoutline);
FT_Error FT_Outline_New_Internal(FT_Memory memory, FT_UInt numPoints, FT_Int numContours, FT_Outline *anoutline);
FT_Error FT_Outline_Done(FT_Library library, FT_Outline *outline);
FT_Error FT_Outline_Done_Internal(FT_Memory memory, FT_Outline *outline);
FT_Error FT_Outline_Copy(FT_Outline *source, FT_Outline *target);
void FT_Outline_Translate(FT_Outline *outline, FT_Pos xOffset, FT_Pos yOffset);
void FT_Outline_Transform(FT_Outline *outline, FT_Matrix *matrix);
void FT_Outline_Reverse(FT_Outline *outline);
FT_Error FT_Outline_Check(FT_Outline *outline);
void FT_Outline_Get_CBox(FT_Outline *outline, FT_BBox *acbox);
FT_Error FT_Outline_Get_BBox(FT_Outline *outline, FT_BBox *abbox);
FT_Error FT_Outline_Get_Bitmap(FT_Library library, FT_Outline *outline, FT_Bitmap *abitmap);
FT_Error FT_Outline_Render(FT_Library library, FT_Outline *outline, FT_Raster_Params *params);
FT_Error FT_Outline_Decompose(FT_Outline *outline, const FT_Outline_Funcs *func_interface, void *user);
FT_Error FT_Add_Module(FT_Library library, const FT_Module_Class *clazz);
FT_Module FT_Get_Module(FT_Library library, const char *module_name);
FT_Error FT_Remove_Module(FT_Library library, FT_Module module);
FT_Error FT_New_Library(FT_Memory memory, FT_Library *alibrary);
FT_Error FT_Done_Library(FT_Library library);
void FT_Set_Debug_Hook(FT_Library library, FT_UInt hook_index, FT_DebugHook_Func debug_hook);
void FT_Add_Default_Modules(FT_Library library);
FT_Renderer FT_Get_Renderer(FT_Library library, FT_Glyph_Format format);
FT_Error FT_Set_Renderer(FT_Library library, FT_Renderer renderer, FT_UInt num_params, FT_Parameter *parameters);
FT_Error FT_Stream_OpenGzip(FT_Stream stream, FT_Stream source);
void * FT_Get_Sfnt_Table(FT_Face face, FT_Sfnt_Tag tag);

__END_DECLS

#endif /* CLIB_FREETYPE2_PROTOS_H */
