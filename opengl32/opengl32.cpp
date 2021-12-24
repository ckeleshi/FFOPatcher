#include "../common/stdinc.h"
#include "../common/patch.h"

HMODULE OpenGL32Module;
std::uintptr_t OpenGL32ModuleAddress;

FARPROC fnGlmfBeginGlsBlock;
FARPROC fnGlmfCloseMetaFile;
FARPROC fnGlmfEndGlsBlock;
FARPROC fnGlmfEndPlayback;
FARPROC fnGlmfInitPlayback;
FARPROC fnGlmfPlayGlsRecord;
FARPROC fnglAccum;
FARPROC fnglAlphaFunc;
FARPROC fnglAreTexturesResident;
FARPROC fnglArrayElement;
FARPROC fnglBegin;
FARPROC fnglBindTexture;
FARPROC fnglBitmap;
FARPROC fnglBlendFunc;
FARPROC fnglCallList;
FARPROC fnglCallLists;
FARPROC fnglClear;
FARPROC fnglClearAccum;
FARPROC fnglClearColor;
FARPROC fnglClearDepth;
FARPROC fnglClearIndex;
FARPROC fnglClearStencil;
FARPROC fnglClipPlane;
FARPROC fnglColor3b;
FARPROC fnglColor3bv;
FARPROC fnglColor3d;
FARPROC fnglColor3dv;
FARPROC fnglColor3f;
FARPROC fnglColor3fv;
FARPROC fnglColor3i;
FARPROC fnglColor3iv;
FARPROC fnglColor3s;
FARPROC fnglColor3sv;
FARPROC fnglColor3ub;
FARPROC fnglColor3ubv;
FARPROC fnglColor3ui;
FARPROC fnglColor3uiv;
FARPROC fnglColor3us;
FARPROC fnglColor3usv;
FARPROC fnglColor4b;
FARPROC fnglColor4bv;
FARPROC fnglColor4d;
FARPROC fnglColor4dv;
FARPROC fnglColor4f;
FARPROC fnglColor4fv;
FARPROC fnglColor4i;
FARPROC fnglColor4iv;
FARPROC fnglColor4s;
FARPROC fnglColor4sv;
FARPROC fnglColor4ub;
FARPROC fnglColor4ubv;
FARPROC fnglColor4ui;
FARPROC fnglColor4uiv;
FARPROC fnglColor4us;
FARPROC fnglColor4usv;
FARPROC fnglColorMask;
FARPROC fnglColorMaterial;
FARPROC fnglColorPointer;
FARPROC fnglCopyPixels;
FARPROC fnglCopyTexImage1D;
FARPROC fnglCopyTexImage2D;
FARPROC fnglCopyTexSubImage1D;
FARPROC fnglCopyTexSubImage2D;
FARPROC fnglCullFace;
FARPROC fnglDebugEntry;
FARPROC fnglDeleteLists;
FARPROC fnglDeleteTextures;
FARPROC fnglDepthFunc;
FARPROC fnglDepthMask;
FARPROC fnglDepthRange;
FARPROC fnglDisable;
FARPROC fnglDisableClientState;
FARPROC fnglDrawArrays;
FARPROC fnglDrawBuffer;
FARPROC fnglDrawElements;
FARPROC fnglDrawPixels;
FARPROC fnglEdgeFlag;
FARPROC fnglEdgeFlagPointer;
FARPROC fnglEdgeFlagv;
FARPROC fnglEnable;
FARPROC fnglEnableClientState;
FARPROC fnglEnd;
FARPROC fnglEndList;
FARPROC fnglEvalCoord1d;
FARPROC fnglEvalCoord1dv;
FARPROC fnglEvalCoord1f;
FARPROC fnglEvalCoord1fv;
FARPROC fnglEvalCoord2d;
FARPROC fnglEvalCoord2dv;
FARPROC fnglEvalCoord2f;
FARPROC fnglEvalCoord2fv;
FARPROC fnglEvalMesh1;
FARPROC fnglEvalMesh2;
FARPROC fnglEvalPoint1;
FARPROC fnglEvalPoint2;
FARPROC fnglFeedbackBuffer;
FARPROC fnglFinish;
FARPROC fnglFlush;
FARPROC fnglFogf;
FARPROC fnglFogfv;
FARPROC fnglFogi;
FARPROC fnglFogiv;
FARPROC fnglFrontFace;
FARPROC fnglFrustum;
FARPROC fnglGenLists;
FARPROC fnglGenTextures;
FARPROC fnglGetBooleanv;
FARPROC fnglGetClipPlane;
FARPROC fnglGetDoublev;
FARPROC fnglGetError;
FARPROC fnglGetFloatv;
FARPROC fnglGetIntegerv;
FARPROC fnglGetLightfv;
FARPROC fnglGetLightiv;
FARPROC fnglGetMapdv;
FARPROC fnglGetMapfv;
FARPROC fnglGetMapiv;
FARPROC fnglGetMaterialfv;
FARPROC fnglGetMaterialiv;
FARPROC fnglGetPixelMapfv;
FARPROC fnglGetPixelMapuiv;
FARPROC fnglGetPixelMapusv;
FARPROC fnglGetPointerv;
FARPROC fnglGetPolygonStipple;
FARPROC fnglGetString;
FARPROC fnglGetTexEnvfv;
FARPROC fnglGetTexEnviv;
FARPROC fnglGetTexGendv;
FARPROC fnglGetTexGenfv;
FARPROC fnglGetTexGeniv;
FARPROC fnglGetTexImage;
FARPROC fnglGetTexLevelParameterfv;
FARPROC fnglGetTexLevelParameteriv;
FARPROC fnglGetTexParameterfv;
FARPROC fnglGetTexParameteriv;
FARPROC fnglHint;
FARPROC fnglIndexMask;
FARPROC fnglIndexPointer;
FARPROC fnglIndexd;
FARPROC fnglIndexdv;
FARPROC fnglIndexf;
FARPROC fnglIndexfv;
FARPROC fnglIndexi;
FARPROC fnglIndexiv;
FARPROC fnglIndexs;
FARPROC fnglIndexsv;
FARPROC fnglIndexub;
FARPROC fnglIndexubv;
FARPROC fnglInitNames;
FARPROC fnglInterleavedArrays;
FARPROC fnglIsEnabled;
FARPROC fnglIsList;
FARPROC fnglIsTexture;
FARPROC fnglLightModelf;
FARPROC fnglLightModelfv;
FARPROC fnglLightModeli;
FARPROC fnglLightModeliv;
FARPROC fnglLightf;
FARPROC fnglLightfv;
FARPROC fnglLighti;
FARPROC fnglLightiv;
FARPROC fnglLineStipple;
FARPROC fnglLineWidth;
FARPROC fnglListBase;
FARPROC fnglLoadIdentity;
FARPROC fnglLoadMatrixd;
FARPROC fnglLoadMatrixf;
FARPROC fnglLoadName;
FARPROC fnglLogicOp;
FARPROC fnglMap1d;
FARPROC fnglMap1f;
FARPROC fnglMap2d;
FARPROC fnglMap2f;
FARPROC fnglMapGrid1d;
FARPROC fnglMapGrid1f;
FARPROC fnglMapGrid2d;
FARPROC fnglMapGrid2f;
FARPROC fnglMaterialf;
FARPROC fnglMaterialfv;
FARPROC fnglMateriali;
FARPROC fnglMaterialiv;
FARPROC fnglMatrixMode;
FARPROC fnglMultMatrixd;
FARPROC fnglMultMatrixf;
FARPROC fnglNewList;
FARPROC fnglNormal3b;
FARPROC fnglNormal3bv;
FARPROC fnglNormal3d;
FARPROC fnglNormal3dv;
FARPROC fnglNormal3f;
FARPROC fnglNormal3fv;
FARPROC fnglNormal3i;
FARPROC fnglNormal3iv;
FARPROC fnglNormal3s;
FARPROC fnglNormal3sv;
FARPROC fnglNormalPointer;
FARPROC fnglOrtho;
FARPROC fnglPassThrough;
FARPROC fnglPixelMapfv;
FARPROC fnglPixelMapuiv;
FARPROC fnglPixelMapusv;
FARPROC fnglPixelStoref;
FARPROC fnglPixelStorei;
FARPROC fnglPixelTransferf;
FARPROC fnglPixelTransferi;
FARPROC fnglPixelZoom;
FARPROC fnglPointSize;
FARPROC fnglPolygonMode;
FARPROC fnglPolygonOffset;
FARPROC fnglPolygonStipple;
FARPROC fnglPopAttrib;
FARPROC fnglPopClientAttrib;
FARPROC fnglPopMatrix;
FARPROC fnglPopName;
FARPROC fnglPrioritizeTextures;
FARPROC fnglPushAttrib;
FARPROC fnglPushClientAttrib;
FARPROC fnglPushMatrix;
FARPROC fnglPushName;
FARPROC fnglRasterPos2d;
FARPROC fnglRasterPos2dv;
FARPROC fnglRasterPos2f;
FARPROC fnglRasterPos2fv;
FARPROC fnglRasterPos2i;
FARPROC fnglRasterPos2iv;
FARPROC fnglRasterPos2s;
FARPROC fnglRasterPos2sv;
FARPROC fnglRasterPos3d;
FARPROC fnglRasterPos3dv;
FARPROC fnglRasterPos3f;
FARPROC fnglRasterPos3fv;
FARPROC fnglRasterPos3i;
FARPROC fnglRasterPos3iv;
FARPROC fnglRasterPos3s;
FARPROC fnglRasterPos3sv;
FARPROC fnglRasterPos4d;
FARPROC fnglRasterPos4dv;
FARPROC fnglRasterPos4f;
FARPROC fnglRasterPos4fv;
FARPROC fnglRasterPos4i;
FARPROC fnglRasterPos4iv;
FARPROC fnglRasterPos4s;
FARPROC fnglRasterPos4sv;
FARPROC fnglReadBuffer;
FARPROC fnglReadPixels;
FARPROC fnglRectd;
FARPROC fnglRectdv;
FARPROC fnglRectf;
FARPROC fnglRectfv;
FARPROC fnglRecti;
FARPROC fnglRectiv;
FARPROC fnglRects;
FARPROC fnglRectsv;
FARPROC fnglRenderMode;
FARPROC fnglRotated;
FARPROC fnglRotatef;
FARPROC fnglScaled;
FARPROC fnglScalef;
FARPROC fnglScissor;
FARPROC fnglSelectBuffer;
FARPROC fnglShadeModel;
FARPROC fnglStencilFunc;
FARPROC fnglStencilMask;
FARPROC fnglStencilOp;
FARPROC fnglTexCoord1d;
FARPROC fnglTexCoord1dv;
FARPROC fnglTexCoord1f;
FARPROC fnglTexCoord1fv;
FARPROC fnglTexCoord1i;
FARPROC fnglTexCoord1iv;
FARPROC fnglTexCoord1s;
FARPROC fnglTexCoord1sv;
FARPROC fnglTexCoord2d;
FARPROC fnglTexCoord2dv;
FARPROC fnglTexCoord2f;
FARPROC fnglTexCoord2fv;
FARPROC fnglTexCoord2i;
FARPROC fnglTexCoord2iv;
FARPROC fnglTexCoord2s;
FARPROC fnglTexCoord2sv;
FARPROC fnglTexCoord3d;
FARPROC fnglTexCoord3dv;
FARPROC fnglTexCoord3f;
FARPROC fnglTexCoord3fv;
FARPROC fnglTexCoord3i;
FARPROC fnglTexCoord3iv;
FARPROC fnglTexCoord3s;
FARPROC fnglTexCoord3sv;
FARPROC fnglTexCoord4d;
FARPROC fnglTexCoord4dv;
FARPROC fnglTexCoord4f;
FARPROC fnglTexCoord4fv;
FARPROC fnglTexCoord4i;
FARPROC fnglTexCoord4iv;
FARPROC fnglTexCoord4s;
FARPROC fnglTexCoord4sv;
FARPROC fnglTexCoordPointer;
FARPROC fnglTexEnvf;
FARPROC fnglTexEnvfv;
FARPROC fnglTexEnvi;
FARPROC fnglTexEnviv;
FARPROC fnglTexGend;
FARPROC fnglTexGendv;
FARPROC fnglTexGenf;
FARPROC fnglTexGenfv;
FARPROC fnglTexGeni;
FARPROC fnglTexGeniv;
FARPROC fnglTexImage1D;
FARPROC fnglTexImage2D;
FARPROC fnglTexParameterf;
FARPROC fnglTexParameterfv;
FARPROC fnglTexParameteri;
FARPROC fnglTexParameteriv;
FARPROC fnglTexSubImage1D;
FARPROC fnglTexSubImage2D;
FARPROC fnglTranslated;
FARPROC fnglTranslatef;
FARPROC fnglVertex2d;
FARPROC fnglVertex2dv;
FARPROC fnglVertex2f;
FARPROC fnglVertex2fv;
FARPROC fnglVertex2i;
FARPROC fnglVertex2iv;
FARPROC fnglVertex2s;
FARPROC fnglVertex2sv;
FARPROC fnglVertex3d;
FARPROC fnglVertex3dv;
FARPROC fnglVertex3f;
FARPROC fnglVertex3fv;
FARPROC fnglVertex3i;
FARPROC fnglVertex3iv;
FARPROC fnglVertex3s;
FARPROC fnglVertex3sv;
FARPROC fnglVertex4d;
FARPROC fnglVertex4dv;
FARPROC fnglVertex4f;
FARPROC fnglVertex4fv;
FARPROC fnglVertex4i;
FARPROC fnglVertex4iv;
FARPROC fnglVertex4s;
FARPROC fnglVertex4sv;
FARPROC fnglVertexPointer;
FARPROC fnglViewport;
FARPROC fnwglChoosePixelFormat;
FARPROC fnwglCopyContext;
FARPROC fnwglCreateContext;
FARPROC fnwglCreateLayerContext;
FARPROC fnwglDeleteContext;
FARPROC fnwglDescribeLayerPlane;
FARPROC fnwglDescribePixelFormat;
FARPROC fnwglGetCurrentContext;
FARPROC fnwglGetCurrentDC;
FARPROC fnwglGetDefaultProcAddress;
FARPROC fnwglGetLayerPaletteEntries;
FARPROC fnwglGetPixelFormat;
FARPROC fnwglGetProcAddress;
FARPROC fnwglMakeCurrent;
FARPROC fnwglRealizeLayerPalette;
FARPROC fnwglSetLayerPaletteEntries;
FARPROC fnwglSetPixelFormat;
FARPROC fnwglShareLists;
FARPROC fnwglSwapBuffers;
FARPROC fnwglSwapLayerBuffers;
FARPROC fnwglSwapMultipleBuffers;
FARPROC fnwglUseFontBitmapsA;
FARPROC fnwglUseFontBitmapsW;
FARPROC fnwglUseFontOutlinesA;
FARPROC fnwglUseFontOutlinesW;

__declspec(naked) void GlmfBeginGlsBlock_stub() { __asm jmp fnGlmfBeginGlsBlock }
__declspec(naked) void GlmfCloseMetaFile_stub() { __asm jmp fnGlmfCloseMetaFile }
__declspec(naked) void GlmfEndGlsBlock_stub() { __asm jmp fnGlmfEndGlsBlock }
__declspec(naked) void GlmfEndPlayback_stub() { __asm jmp fnGlmfEndPlayback }
__declspec(naked) void GlmfInitPlayback_stub() { __asm jmp fnGlmfInitPlayback }
__declspec(naked) void GlmfPlayGlsRecord_stub() { __asm jmp fnGlmfPlayGlsRecord }
__declspec(naked) void glAccum_stub() { __asm jmp fnglAccum }
__declspec(naked) void glAlphaFunc_stub() { __asm jmp fnglAlphaFunc }
__declspec(naked) void glAreTexturesResident_stub() { __asm jmp fnglAreTexturesResident }
__declspec(naked) void glArrayElement_stub() { __asm jmp fnglArrayElement }
__declspec(naked) void glBegin_stub() { __asm jmp fnglBegin }
__declspec(naked) void glBindTexture_stub() { __asm jmp fnglBindTexture }
__declspec(naked) void glBitmap_stub() { __asm jmp fnglBitmap }
__declspec(naked) void glBlendFunc_stub() { __asm jmp fnglBlendFunc }
__declspec(naked) void glCallList_stub() { __asm jmp fnglCallList }
__declspec(naked) void glCallLists_stub() { __asm jmp fnglCallLists }
__declspec(naked) void glClear_stub() { __asm jmp fnglClear }
__declspec(naked) void glClearAccum_stub() { __asm jmp fnglClearAccum }
__declspec(naked) void glClearColor_stub() { __asm jmp fnglClearColor }
__declspec(naked) void glClearDepth_stub() { __asm jmp fnglClearDepth }
__declspec(naked) void glClearIndex_stub() { __asm jmp fnglClearIndex }
__declspec(naked) void glClearStencil_stub() { __asm jmp fnglClearStencil }
__declspec(naked) void glClipPlane_stub() { __asm jmp fnglClipPlane }
__declspec(naked) void glColor3b_stub() { __asm jmp fnglColor3b }
__declspec(naked) void glColor3bv_stub() { __asm jmp fnglColor3bv }
__declspec(naked) void glColor3d_stub() { __asm jmp fnglColor3d }
__declspec(naked) void glColor3dv_stub() { __asm jmp fnglColor3dv }
__declspec(naked) void glColor3f_stub() { __asm jmp fnglColor3f }
__declspec(naked) void glColor3fv_stub() { __asm jmp fnglColor3fv }
__declspec(naked) void glColor3i_stub() { __asm jmp fnglColor3i }
__declspec(naked) void glColor3iv_stub() { __asm jmp fnglColor3iv }
__declspec(naked) void glColor3s_stub() { __asm jmp fnglColor3s }
__declspec(naked) void glColor3sv_stub() { __asm jmp fnglColor3sv }
__declspec(naked) void glColor3ub_stub() { __asm jmp fnglColor3ub }
__declspec(naked) void glColor3ubv_stub() { __asm jmp fnglColor3ubv }
__declspec(naked) void glColor3ui_stub() { __asm jmp fnglColor3ui }
__declspec(naked) void glColor3uiv_stub() { __asm jmp fnglColor3uiv }
__declspec(naked) void glColor3us_stub() { __asm jmp fnglColor3us }
__declspec(naked) void glColor3usv_stub() { __asm jmp fnglColor3usv }
__declspec(naked) void glColor4b_stub() { __asm jmp fnglColor4b }
__declspec(naked) void glColor4bv_stub() { __asm jmp fnglColor4bv }
__declspec(naked) void glColor4d_stub() { __asm jmp fnglColor4d }
__declspec(naked) void glColor4dv_stub() { __asm jmp fnglColor4dv }
__declspec(naked) void glColor4f_stub() { __asm jmp fnglColor4f }
__declspec(naked) void glColor4fv_stub() { __asm jmp fnglColor4fv }
__declspec(naked) void glColor4i_stub() { __asm jmp fnglColor4i }
__declspec(naked) void glColor4iv_stub() { __asm jmp fnglColor4iv }
__declspec(naked) void glColor4s_stub() { __asm jmp fnglColor4s }
__declspec(naked) void glColor4sv_stub() { __asm jmp fnglColor4sv }
__declspec(naked) void glColor4ub_stub() { __asm jmp fnglColor4ub }
__declspec(naked) void glColor4ubv_stub() { __asm jmp fnglColor4ubv }
__declspec(naked) void glColor4ui_stub() { __asm jmp fnglColor4ui }
__declspec(naked) void glColor4uiv_stub() { __asm jmp fnglColor4uiv }
__declspec(naked) void glColor4us_stub() { __asm jmp fnglColor4us }
__declspec(naked) void glColor4usv_stub() { __asm jmp fnglColor4usv }
__declspec(naked) void glColorMask_stub() { __asm jmp fnglColorMask }
__declspec(naked) void glColorMaterial_stub() { __asm jmp fnglColorMaterial }
__declspec(naked) void glColorPointer_stub() { __asm jmp fnglColorPointer }
__declspec(naked) void glCopyPixels_stub() { __asm jmp fnglCopyPixels }
__declspec(naked) void glCopyTexImage1D_stub() { __asm jmp fnglCopyTexImage1D }
__declspec(naked) void glCopyTexImage2D_stub() { __asm jmp fnglCopyTexImage2D }
__declspec(naked) void glCopyTexSubImage1D_stub() { __asm jmp fnglCopyTexSubImage1D }
__declspec(naked) void glCopyTexSubImage2D_stub() { __asm jmp fnglCopyTexSubImage2D }
__declspec(naked) void glCullFace_stub() { __asm jmp fnglCullFace }
__declspec(naked) void glDebugEntry_stub() { __asm jmp fnglDebugEntry }
__declspec(naked) void glDeleteLists_stub() { __asm jmp fnglDeleteLists }
__declspec(naked) void glDeleteTextures_stub() { __asm jmp fnglDeleteTextures }
__declspec(naked) void glDepthFunc_stub() { __asm jmp fnglDepthFunc }
__declspec(naked) void glDepthMask_stub() { __asm jmp fnglDepthMask }
__declspec(naked) void glDepthRange_stub() { __asm jmp fnglDepthRange }
__declspec(naked) void glDisable_stub() { __asm jmp fnglDisable }
__declspec(naked) void glDisableClientState_stub() { __asm jmp fnglDisableClientState }
__declspec(naked) void glDrawArrays_stub() { __asm jmp fnglDrawArrays }
__declspec(naked) void glDrawBuffer_stub() { __asm jmp fnglDrawBuffer }
__declspec(naked) void glDrawElements_stub() { __asm jmp fnglDrawElements }
__declspec(naked) void glDrawPixels_stub() { __asm jmp fnglDrawPixels }
__declspec(naked) void glEdgeFlag_stub() { __asm jmp fnglEdgeFlag }
__declspec(naked) void glEdgeFlagPointer_stub() { __asm jmp fnglEdgeFlagPointer }
__declspec(naked) void glEdgeFlagv_stub() { __asm jmp fnglEdgeFlagv }
__declspec(naked) void glEnable_stub() { __asm jmp fnglEnable }
__declspec(naked) void glEnableClientState_stub() { __asm jmp fnglEnableClientState }
__declspec(naked) void glEnd_stub() { __asm jmp fnglEnd }
__declspec(naked) void glEndList_stub() { __asm jmp fnglEndList }
__declspec(naked) void glEvalCoord1d_stub() { __asm jmp fnglEvalCoord1d }
__declspec(naked) void glEvalCoord1dv_stub() { __asm jmp fnglEvalCoord1dv }
__declspec(naked) void glEvalCoord1f_stub() { __asm jmp fnglEvalCoord1f }
__declspec(naked) void glEvalCoord1fv_stub() { __asm jmp fnglEvalCoord1fv }
__declspec(naked) void glEvalCoord2d_stub() { __asm jmp fnglEvalCoord2d }
__declspec(naked) void glEvalCoord2dv_stub() { __asm jmp fnglEvalCoord2dv }
__declspec(naked) void glEvalCoord2f_stub() { __asm jmp fnglEvalCoord2f }
__declspec(naked) void glEvalCoord2fv_stub() { __asm jmp fnglEvalCoord2fv }
__declspec(naked) void glEvalMesh1_stub() { __asm jmp fnglEvalMesh1 }
__declspec(naked) void glEvalMesh2_stub() { __asm jmp fnglEvalMesh2 }
__declspec(naked) void glEvalPoint1_stub() { __asm jmp fnglEvalPoint1 }
__declspec(naked) void glEvalPoint2_stub() { __asm jmp fnglEvalPoint2 }
__declspec(naked) void glFeedbackBuffer_stub() { __asm jmp fnglFeedbackBuffer }
__declspec(naked) void glFinish_stub() { __asm jmp fnglFinish }
__declspec(naked) void glFlush_stub() { __asm jmp fnglFlush }
__declspec(naked) void glFogf_stub() { __asm jmp fnglFogf }
__declspec(naked) void glFogfv_stub() { __asm jmp fnglFogfv }
__declspec(naked) void glFogi_stub() { __asm jmp fnglFogi }
__declspec(naked) void glFogiv_stub() { __asm jmp fnglFogiv }
__declspec(naked) void glFrontFace_stub() { __asm jmp fnglFrontFace }
__declspec(naked) void glFrustum_stub() { __asm jmp fnglFrustum }
__declspec(naked) void glGenLists_stub() { __asm jmp fnglGenLists }
__declspec(naked) void glGenTextures_stub() { __asm jmp fnglGenTextures }
__declspec(naked) void glGetBooleanv_stub() { __asm jmp fnglGetBooleanv }
__declspec(naked) void glGetClipPlane_stub() { __asm jmp fnglGetClipPlane }
__declspec(naked) void glGetDoublev_stub() { __asm jmp fnglGetDoublev }
__declspec(naked) void glGetError_stub() { __asm jmp fnglGetError }
__declspec(naked) void glGetFloatv_stub() { __asm jmp fnglGetFloatv }
__declspec(naked) void glGetIntegerv_stub() { __asm jmp fnglGetIntegerv }
__declspec(naked) void glGetLightfv_stub() { __asm jmp fnglGetLightfv }
__declspec(naked) void glGetLightiv_stub() { __asm jmp fnglGetLightiv }
__declspec(naked) void glGetMapdv_stub() { __asm jmp fnglGetMapdv }
__declspec(naked) void glGetMapfv_stub() { __asm jmp fnglGetMapfv }
__declspec(naked) void glGetMapiv_stub() { __asm jmp fnglGetMapiv }
__declspec(naked) void glGetMaterialfv_stub() { __asm jmp fnglGetMaterialfv }
__declspec(naked) void glGetMaterialiv_stub() { __asm jmp fnglGetMaterialiv }
__declspec(naked) void glGetPixelMapfv_stub() { __asm jmp fnglGetPixelMapfv }
__declspec(naked) void glGetPixelMapuiv_stub() { __asm jmp fnglGetPixelMapuiv }
__declspec(naked) void glGetPixelMapusv_stub() { __asm jmp fnglGetPixelMapusv }
__declspec(naked) void glGetPointerv_stub() { __asm jmp fnglGetPointerv }
__declspec(naked) void glGetPolygonStipple_stub() { __asm jmp fnglGetPolygonStipple }
__declspec(naked) void glGetString_stub() { __asm jmp fnglGetString }
__declspec(naked) void glGetTexEnvfv_stub() { __asm jmp fnglGetTexEnvfv }
__declspec(naked) void glGetTexEnviv_stub() { __asm jmp fnglGetTexEnviv }
__declspec(naked) void glGetTexGendv_stub() { __asm jmp fnglGetTexGendv }
__declspec(naked) void glGetTexGenfv_stub() { __asm jmp fnglGetTexGenfv }
__declspec(naked) void glGetTexGeniv_stub() { __asm jmp fnglGetTexGeniv }
__declspec(naked) void glGetTexImage_stub() { __asm jmp fnglGetTexImage }
__declspec(naked) void glGetTexLevelParameterfv_stub() { __asm jmp fnglGetTexLevelParameterfv }
__declspec(naked) void glGetTexLevelParameteriv_stub() { __asm jmp fnglGetTexLevelParameteriv }
__declspec(naked) void glGetTexParameterfv_stub() { __asm jmp fnglGetTexParameterfv }
__declspec(naked) void glGetTexParameteriv_stub() { __asm jmp fnglGetTexParameteriv }
__declspec(naked) void glHint_stub() { __asm jmp fnglHint }
__declspec(naked) void glIndexMask_stub() { __asm jmp fnglIndexMask }
__declspec(naked) void glIndexPointer_stub() { __asm jmp fnglIndexPointer }
__declspec(naked) void glIndexd_stub() { __asm jmp fnglIndexd }
__declspec(naked) void glIndexdv_stub() { __asm jmp fnglIndexdv }
__declspec(naked) void glIndexf_stub() { __asm jmp fnglIndexf }
__declspec(naked) void glIndexfv_stub() { __asm jmp fnglIndexfv }
__declspec(naked) void glIndexi_stub() { __asm jmp fnglIndexi }
__declspec(naked) void glIndexiv_stub() { __asm jmp fnglIndexiv }
__declspec(naked) void glIndexs_stub() { __asm jmp fnglIndexs }
__declspec(naked) void glIndexsv_stub() { __asm jmp fnglIndexsv }
__declspec(naked) void glIndexub_stub() { __asm jmp fnglIndexub }
__declspec(naked) void glIndexubv_stub() { __asm jmp fnglIndexubv }
__declspec(naked) void glInitNames_stub() { __asm jmp fnglInitNames }
__declspec(naked) void glInterleavedArrays_stub() { __asm jmp fnglInterleavedArrays }
__declspec(naked) void glIsEnabled_stub() { __asm jmp fnglIsEnabled }
__declspec(naked) void glIsList_stub() { __asm jmp fnglIsList }
__declspec(naked) void glIsTexture_stub() { __asm jmp fnglIsTexture }
__declspec(naked) void glLightModelf_stub() { __asm jmp fnglLightModelf }
__declspec(naked) void glLightModelfv_stub() { __asm jmp fnglLightModelfv }
__declspec(naked) void glLightModeli_stub() { __asm jmp fnglLightModeli }
__declspec(naked) void glLightModeliv_stub() { __asm jmp fnglLightModeliv }
__declspec(naked) void glLightf_stub() { __asm jmp fnglLightf }
__declspec(naked) void glLightfv_stub() { __asm jmp fnglLightfv }
__declspec(naked) void glLighti_stub() { __asm jmp fnglLighti }
__declspec(naked) void glLightiv_stub() { __asm jmp fnglLightiv }
__declspec(naked) void glLineStipple_stub() { __asm jmp fnglLineStipple }
__declspec(naked) void glLineWidth_stub() { __asm jmp fnglLineWidth }
__declspec(naked) void glListBase_stub() { __asm jmp fnglListBase }
__declspec(naked) void glLoadIdentity_stub() { __asm jmp fnglLoadIdentity }
__declspec(naked) void glLoadMatrixd_stub() { __asm jmp fnglLoadMatrixd }
__declspec(naked) void glLoadMatrixf_stub() { __asm jmp fnglLoadMatrixf }
__declspec(naked) void glLoadName_stub() { __asm jmp fnglLoadName }
__declspec(naked) void glLogicOp_stub() { __asm jmp fnglLogicOp }
__declspec(naked) void glMap1d_stub() { __asm jmp fnglMap1d }
__declspec(naked) void glMap1f_stub() { __asm jmp fnglMap1f }
__declspec(naked) void glMap2d_stub() { __asm jmp fnglMap2d }
__declspec(naked) void glMap2f_stub() { __asm jmp fnglMap2f }
__declspec(naked) void glMapGrid1d_stub() { __asm jmp fnglMapGrid1d }
__declspec(naked) void glMapGrid1f_stub() { __asm jmp fnglMapGrid1f }
__declspec(naked) void glMapGrid2d_stub() { __asm jmp fnglMapGrid2d }
__declspec(naked) void glMapGrid2f_stub() { __asm jmp fnglMapGrid2f }
__declspec(naked) void glMaterialf_stub() { __asm jmp fnglMaterialf }
__declspec(naked) void glMaterialfv_stub() { __asm jmp fnglMaterialfv }
__declspec(naked) void glMateriali_stub() { __asm jmp fnglMateriali }
__declspec(naked) void glMaterialiv_stub() { __asm jmp fnglMaterialiv }
__declspec(naked) void glMatrixMode_stub() { __asm jmp fnglMatrixMode }
__declspec(naked) void glMultMatrixd_stub() { __asm jmp fnglMultMatrixd }
__declspec(naked) void glMultMatrixf_stub() { __asm jmp fnglMultMatrixf }
__declspec(naked) void glNewList_stub() { __asm jmp fnglNewList }
__declspec(naked) void glNormal3b_stub() { __asm jmp fnglNormal3b }
__declspec(naked) void glNormal3bv_stub() { __asm jmp fnglNormal3bv }
__declspec(naked) void glNormal3d_stub() { __asm jmp fnglNormal3d }
__declspec(naked) void glNormal3dv_stub() { __asm jmp fnglNormal3dv }
__declspec(naked) void glNormal3f_stub() { __asm jmp fnglNormal3f }
__declspec(naked) void glNormal3fv_stub() { __asm jmp fnglNormal3fv }
__declspec(naked) void glNormal3i_stub() { __asm jmp fnglNormal3i }
__declspec(naked) void glNormal3iv_stub() { __asm jmp fnglNormal3iv }
__declspec(naked) void glNormal3s_stub() { __asm jmp fnglNormal3s }
__declspec(naked) void glNormal3sv_stub() { __asm jmp fnglNormal3sv }
__declspec(naked) void glNormalPointer_stub() { __asm jmp fnglNormalPointer }
__declspec(naked) void glOrtho_stub() { __asm jmp fnglOrtho }
__declspec(naked) void glPassThrough_stub() { __asm jmp fnglPassThrough }
__declspec(naked) void glPixelMapfv_stub() { __asm jmp fnglPixelMapfv }
__declspec(naked) void glPixelMapuiv_stub() { __asm jmp fnglPixelMapuiv }
__declspec(naked) void glPixelMapusv_stub() { __asm jmp fnglPixelMapusv }
__declspec(naked) void glPixelStoref_stub() { __asm jmp fnglPixelStoref }
__declspec(naked) void glPixelStorei_stub() { __asm jmp fnglPixelStorei }
__declspec(naked) void glPixelTransferf_stub() { __asm jmp fnglPixelTransferf }
__declspec(naked) void glPixelTransferi_stub() { __asm jmp fnglPixelTransferi }
__declspec(naked) void glPixelZoom_stub() { __asm jmp fnglPixelZoom }
__declspec(naked) void glPointSize_stub() { __asm jmp fnglPointSize }
__declspec(naked) void glPolygonMode_stub() { __asm jmp fnglPolygonMode }
__declspec(naked) void glPolygonOffset_stub() { __asm jmp fnglPolygonOffset }
__declspec(naked) void glPolygonStipple_stub() { __asm jmp fnglPolygonStipple }
__declspec(naked) void glPopAttrib_stub() { __asm jmp fnglPopAttrib }
__declspec(naked) void glPopClientAttrib_stub() { __asm jmp fnglPopClientAttrib }
__declspec(naked) void glPopMatrix_stub() { __asm jmp fnglPopMatrix }
__declspec(naked) void glPopName_stub() { __asm jmp fnglPopName }
__declspec(naked) void glPrioritizeTextures_stub() { __asm jmp fnglPrioritizeTextures }
__declspec(naked) void glPushAttrib_stub() { __asm jmp fnglPushAttrib }
__declspec(naked) void glPushClientAttrib_stub() { __asm jmp fnglPushClientAttrib }
__declspec(naked) void glPushMatrix_stub() { __asm jmp fnglPushMatrix }
__declspec(naked) void glPushName_stub() { __asm jmp fnglPushName }
__declspec(naked) void glRasterPos2d_stub() { __asm jmp fnglRasterPos2d }
__declspec(naked) void glRasterPos2dv_stub() { __asm jmp fnglRasterPos2dv }
__declspec(naked) void glRasterPos2f_stub() { __asm jmp fnglRasterPos2f }
__declspec(naked) void glRasterPos2fv_stub() { __asm jmp fnglRasterPos2fv }
__declspec(naked) void glRasterPos2i_stub() { __asm jmp fnglRasterPos2i }
__declspec(naked) void glRasterPos2iv_stub() { __asm jmp fnglRasterPos2iv }
__declspec(naked) void glRasterPos2s_stub() { __asm jmp fnglRasterPos2s }
__declspec(naked) void glRasterPos2sv_stub() { __asm jmp fnglRasterPos2sv }
__declspec(naked) void glRasterPos3d_stub() { __asm jmp fnglRasterPos3d }
__declspec(naked) void glRasterPos3dv_stub() { __asm jmp fnglRasterPos3dv }
__declspec(naked) void glRasterPos3f_stub() { __asm jmp fnglRasterPos3f }
__declspec(naked) void glRasterPos3fv_stub() { __asm jmp fnglRasterPos3fv }
__declspec(naked) void glRasterPos3i_stub() { __asm jmp fnglRasterPos3i }
__declspec(naked) void glRasterPos3iv_stub() { __asm jmp fnglRasterPos3iv }
__declspec(naked) void glRasterPos3s_stub() { __asm jmp fnglRasterPos3s }
__declspec(naked) void glRasterPos3sv_stub() { __asm jmp fnglRasterPos3sv }
__declspec(naked) void glRasterPos4d_stub() { __asm jmp fnglRasterPos4d }
__declspec(naked) void glRasterPos4dv_stub() { __asm jmp fnglRasterPos4dv }
__declspec(naked) void glRasterPos4f_stub() { __asm jmp fnglRasterPos4f }
__declspec(naked) void glRasterPos4fv_stub() { __asm jmp fnglRasterPos4fv }
__declspec(naked) void glRasterPos4i_stub() { __asm jmp fnglRasterPos4i }
__declspec(naked) void glRasterPos4iv_stub() { __asm jmp fnglRasterPos4iv }
__declspec(naked) void glRasterPos4s_stub() { __asm jmp fnglRasterPos4s }
__declspec(naked) void glRasterPos4sv_stub() { __asm jmp fnglRasterPos4sv }
__declspec(naked) void glReadBuffer_stub() { __asm jmp fnglReadBuffer }
__declspec(naked) void glReadPixels_stub() { __asm jmp fnglReadPixels }
__declspec(naked) void glRectd_stub() { __asm jmp fnglRectd }
__declspec(naked) void glRectdv_stub() { __asm jmp fnglRectdv }
__declspec(naked) void glRectf_stub() { __asm jmp fnglRectf }
__declspec(naked) void glRectfv_stub() { __asm jmp fnglRectfv }
__declspec(naked) void glRecti_stub() { __asm jmp fnglRecti }
__declspec(naked) void glRectiv_stub() { __asm jmp fnglRectiv }
__declspec(naked) void glRects_stub() { __asm jmp fnglRects }
__declspec(naked) void glRectsv_stub() { __asm jmp fnglRectsv }
__declspec(naked) void glRenderMode_stub() { __asm jmp fnglRenderMode }
__declspec(naked) void glRotated_stub() { __asm jmp fnglRotated }
__declspec(naked) void glRotatef_stub() { __asm jmp fnglRotatef }
__declspec(naked) void glScaled_stub() { __asm jmp fnglScaled }
__declspec(naked) void glScalef_stub() { __asm jmp fnglScalef }
__declspec(naked) void glScissor_stub() { __asm jmp fnglScissor }
__declspec(naked) void glSelectBuffer_stub() { __asm jmp fnglSelectBuffer }
__declspec(naked) void glShadeModel_stub() { __asm jmp fnglShadeModel }
__declspec(naked) void glStencilFunc_stub() { __asm jmp fnglStencilFunc }
__declspec(naked) void glStencilMask_stub() { __asm jmp fnglStencilMask }
__declspec(naked) void glStencilOp_stub() { __asm jmp fnglStencilOp }
__declspec(naked) void glTexCoord1d_stub() { __asm jmp fnglTexCoord1d }
__declspec(naked) void glTexCoord1dv_stub() { __asm jmp fnglTexCoord1dv }
__declspec(naked) void glTexCoord1f_stub() { __asm jmp fnglTexCoord1f }
__declspec(naked) void glTexCoord1fv_stub() { __asm jmp fnglTexCoord1fv }
__declspec(naked) void glTexCoord1i_stub() { __asm jmp fnglTexCoord1i }
__declspec(naked) void glTexCoord1iv_stub() { __asm jmp fnglTexCoord1iv }
__declspec(naked) void glTexCoord1s_stub() { __asm jmp fnglTexCoord1s }
__declspec(naked) void glTexCoord1sv_stub() { __asm jmp fnglTexCoord1sv }
__declspec(naked) void glTexCoord2d_stub() { __asm jmp fnglTexCoord2d }
__declspec(naked) void glTexCoord2dv_stub() { __asm jmp fnglTexCoord2dv }
__declspec(naked) void glTexCoord2f_stub() { __asm jmp fnglTexCoord2f }
__declspec(naked) void glTexCoord2fv_stub() { __asm jmp fnglTexCoord2fv }
__declspec(naked) void glTexCoord2i_stub() { __asm jmp fnglTexCoord2i }
__declspec(naked) void glTexCoord2iv_stub() { __asm jmp fnglTexCoord2iv }
__declspec(naked) void glTexCoord2s_stub() { __asm jmp fnglTexCoord2s }
__declspec(naked) void glTexCoord2sv_stub() { __asm jmp fnglTexCoord2sv }
__declspec(naked) void glTexCoord3d_stub() { __asm jmp fnglTexCoord3d }
__declspec(naked) void glTexCoord3dv_stub() { __asm jmp fnglTexCoord3dv }
__declspec(naked) void glTexCoord3f_stub() { __asm jmp fnglTexCoord3f }
__declspec(naked) void glTexCoord3fv_stub() { __asm jmp fnglTexCoord3fv }
__declspec(naked) void glTexCoord3i_stub() { __asm jmp fnglTexCoord3i }
__declspec(naked) void glTexCoord3iv_stub() { __asm jmp fnglTexCoord3iv }
__declspec(naked) void glTexCoord3s_stub() { __asm jmp fnglTexCoord3s }
__declspec(naked) void glTexCoord3sv_stub() { __asm jmp fnglTexCoord3sv }
__declspec(naked) void glTexCoord4d_stub() { __asm jmp fnglTexCoord4d }
__declspec(naked) void glTexCoord4dv_stub() { __asm jmp fnglTexCoord4dv }
__declspec(naked) void glTexCoord4f_stub() { __asm jmp fnglTexCoord4f }
__declspec(naked) void glTexCoord4fv_stub() { __asm jmp fnglTexCoord4fv }
__declspec(naked) void glTexCoord4i_stub() { __asm jmp fnglTexCoord4i }
__declspec(naked) void glTexCoord4iv_stub() { __asm jmp fnglTexCoord4iv }
__declspec(naked) void glTexCoord4s_stub() { __asm jmp fnglTexCoord4s }
__declspec(naked) void glTexCoord4sv_stub() { __asm jmp fnglTexCoord4sv }
__declspec(naked) void glTexCoordPointer_stub() { __asm jmp fnglTexCoordPointer }
__declspec(naked) void glTexEnvf_stub() { __asm jmp fnglTexEnvf }
__declspec(naked) void glTexEnvfv_stub() { __asm jmp fnglTexEnvfv }
__declspec(naked) void glTexEnvi_stub() { __asm jmp fnglTexEnvi }
__declspec(naked) void glTexEnviv_stub() { __asm jmp fnglTexEnviv }
__declspec(naked) void glTexGend_stub() { __asm jmp fnglTexGend }
__declspec(naked) void glTexGendv_stub() { __asm jmp fnglTexGendv }
__declspec(naked) void glTexGenf_stub() { __asm jmp fnglTexGenf }
__declspec(naked) void glTexGenfv_stub() { __asm jmp fnglTexGenfv }
__declspec(naked) void glTexGeni_stub() { __asm jmp fnglTexGeni }
__declspec(naked) void glTexGeniv_stub() { __asm jmp fnglTexGeniv }
__declspec(naked) void glTexImage1D_stub() { __asm jmp fnglTexImage1D }
__declspec(naked) void glTexImage2D_stub() { __asm jmp fnglTexImage2D }
__declspec(naked) void glTexParameterf_stub() { __asm jmp fnglTexParameterf }
__declspec(naked) void glTexParameterfv_stub() { __asm jmp fnglTexParameterfv }
__declspec(naked) void glTexParameteri_stub() { __asm jmp fnglTexParameteri }
__declspec(naked) void glTexParameteriv_stub() { __asm jmp fnglTexParameteriv }
__declspec(naked) void glTexSubImage1D_stub() { __asm jmp fnglTexSubImage1D }
__declspec(naked) void glTexSubImage2D_stub() { __asm jmp fnglTexSubImage2D }
__declspec(naked) void glTranslated_stub() { __asm jmp fnglTranslated }
__declspec(naked) void glTranslatef_stub() { __asm jmp fnglTranslatef }
__declspec(naked) void glVertex2d_stub() { __asm jmp fnglVertex2d }
__declspec(naked) void glVertex2dv_stub() { __asm jmp fnglVertex2dv }
__declspec(naked) void glVertex2f_stub() { __asm jmp fnglVertex2f }
__declspec(naked) void glVertex2fv_stub() { __asm jmp fnglVertex2fv }
__declspec(naked) void glVertex2i_stub() { __asm jmp fnglVertex2i }
__declspec(naked) void glVertex2iv_stub() { __asm jmp fnglVertex2iv }
__declspec(naked) void glVertex2s_stub() { __asm jmp fnglVertex2s }
__declspec(naked) void glVertex2sv_stub() { __asm jmp fnglVertex2sv }
__declspec(naked) void glVertex3d_stub() { __asm jmp fnglVertex3d }
__declspec(naked) void glVertex3dv_stub() { __asm jmp fnglVertex3dv }
__declspec(naked) void glVertex3f_stub() { __asm jmp fnglVertex3f }
__declspec(naked) void glVertex3fv_stub() { __asm jmp fnglVertex3fv }
__declspec(naked) void glVertex3i_stub() { __asm jmp fnglVertex3i }
__declspec(naked) void glVertex3iv_stub() { __asm jmp fnglVertex3iv }
__declspec(naked) void glVertex3s_stub() { __asm jmp fnglVertex3s }
__declspec(naked) void glVertex3sv_stub() { __asm jmp fnglVertex3sv }
__declspec(naked) void glVertex4d_stub() { __asm jmp fnglVertex4d }
__declspec(naked) void glVertex4dv_stub() { __asm jmp fnglVertex4dv }
__declspec(naked) void glVertex4f_stub() { __asm jmp fnglVertex4f }
__declspec(naked) void glVertex4fv_stub() { __asm jmp fnglVertex4fv }
__declspec(naked) void glVertex4i_stub() { __asm jmp fnglVertex4i }
__declspec(naked) void glVertex4iv_stub() { __asm jmp fnglVertex4iv }
__declspec(naked) void glVertex4s_stub() { __asm jmp fnglVertex4s }
__declspec(naked) void glVertex4sv_stub() { __asm jmp fnglVertex4sv }
__declspec(naked) void glVertexPointer_stub() { __asm jmp fnglVertexPointer }
__declspec(naked) void glViewport_stub() { __asm jmp fnglViewport }
__declspec(naked) void wglChoosePixelFormat_stub() { __asm jmp fnwglChoosePixelFormat }
__declspec(naked) void wglCopyContext_stub() { __asm jmp fnwglCopyContext }
__declspec(naked) void wglCreateContext_stub() { __asm jmp fnwglCreateContext }
__declspec(naked) void wglCreateLayerContext_stub() { __asm jmp fnwglCreateLayerContext }
__declspec(naked) void wglDeleteContext_stub() { __asm jmp fnwglDeleteContext }
__declspec(naked) void wglDescribeLayerPlane_stub() { __asm jmp fnwglDescribeLayerPlane }
__declspec(naked) void wglDescribePixelFormat_stub() { __asm jmp fnwglDescribePixelFormat }
__declspec(naked) void wglGetCurrentContext_stub() { __asm jmp fnwglGetCurrentContext }
__declspec(naked) void wglGetCurrentDC_stub() { __asm jmp fnwglGetCurrentDC }
__declspec(naked) void wglGetDefaultProcAddress_stub() { __asm jmp fnwglGetDefaultProcAddress }
__declspec(naked) void wglGetLayerPaletteEntries_stub() { __asm jmp fnwglGetLayerPaletteEntries }
__declspec(naked) void wglGetPixelFormat_stub() { __asm jmp fnwglGetPixelFormat }
__declspec(naked) void wglGetProcAddress_stub() { __asm jmp fnwglGetProcAddress }
__declspec(naked) void wglMakeCurrent_stub() { __asm jmp fnwglMakeCurrent }
__declspec(naked) void wglRealizeLayerPalette_stub() { __asm jmp fnwglRealizeLayerPalette }
__declspec(naked) void wglSetLayerPaletteEntries_stub() { __asm jmp fnwglSetLayerPaletteEntries }
__declspec(naked) void wglSetPixelFormat_stub() { __asm jmp fnwglSetPixelFormat }
__declspec(naked) void wglShareLists_stub() { __asm jmp fnwglShareLists }
__declspec(naked) void wglSwapBuffers_stub() { __asm jmp fnwglSwapBuffers }
__declspec(naked) void wglSwapLayerBuffers_stub() { __asm jmp fnwglSwapLayerBuffers }
__declspec(naked) void wglSwapMultipleBuffers_stub() { __asm jmp fnwglSwapMultipleBuffers }
__declspec(naked) void wglUseFontBitmapsA_stub() { __asm jmp fnwglUseFontBitmapsA }
__declspec(naked) void wglUseFontBitmapsW_stub() { __asm jmp fnwglUseFontBitmapsW }
__declspec(naked) void wglUseFontOutlinesA_stub() { __asm jmp fnwglUseFontOutlinesA }
__declspec(naked) void wglUseFontOutlinesW_stub() { __asm jmp fnwglUseFontOutlinesW }

void LoadOpenGL32()
{
    WCHAR* szSystemPath = nullptr;

    SHGetKnownFolderPath(FOLDERID_System, 0, NULL, &szSystemPath);

    std::wstring wstr = szSystemPath;

    CoTaskMemFree(szSystemPath);

    OpenGL32Module = LoadLibraryW((wstr + L"\\opengl32.dll").c_str());
    OpenGL32ModuleAddress = reinterpret_cast<std::uintptr_t>(OpenGL32Module);

    fnGlmfBeginGlsBlock = GetProcAddress(OpenGL32Module, "GlmfBeginGlsBlock");
    fnGlmfCloseMetaFile = GetProcAddress(OpenGL32Module, "GlmfCloseMetaFile");
    fnGlmfEndGlsBlock = GetProcAddress(OpenGL32Module, "GlmfEndGlsBlock");
    fnGlmfEndPlayback = GetProcAddress(OpenGL32Module, "GlmfEndPlayback");
    fnGlmfInitPlayback = GetProcAddress(OpenGL32Module, "GlmfInitPlayback");
    fnGlmfPlayGlsRecord = GetProcAddress(OpenGL32Module, "GlmfPlayGlsRecord");
    fnglAccum = GetProcAddress(OpenGL32Module, "glAccum");
    fnglAlphaFunc = GetProcAddress(OpenGL32Module, "glAlphaFunc");
    fnglAreTexturesResident = GetProcAddress(OpenGL32Module, "glAreTexturesResident");
    fnglArrayElement = GetProcAddress(OpenGL32Module, "glArrayElement");
    fnglBegin = GetProcAddress(OpenGL32Module, "glBegin");
    fnglBindTexture = GetProcAddress(OpenGL32Module, "glBindTexture");
    fnglBitmap = GetProcAddress(OpenGL32Module, "glBitmap");
    fnglBlendFunc = GetProcAddress(OpenGL32Module, "glBlendFunc");
    fnglCallList = GetProcAddress(OpenGL32Module, "glCallList");
    fnglCallLists = GetProcAddress(OpenGL32Module, "glCallLists");
    fnglClear = GetProcAddress(OpenGL32Module, "glClear");
    fnglClearAccum = GetProcAddress(OpenGL32Module, "glClearAccum");
    fnglClearColor = GetProcAddress(OpenGL32Module, "glClearColor");
    fnglClearDepth = GetProcAddress(OpenGL32Module, "glClearDepth");
    fnglClearIndex = GetProcAddress(OpenGL32Module, "glClearIndex");
    fnglClearStencil = GetProcAddress(OpenGL32Module, "glClearStencil");
    fnglClipPlane = GetProcAddress(OpenGL32Module, "glClipPlane");
    fnglColor3b = GetProcAddress(OpenGL32Module, "glColor3b");
    fnglColor3bv = GetProcAddress(OpenGL32Module, "glColor3bv");
    fnglColor3d = GetProcAddress(OpenGL32Module, "glColor3d");
    fnglColor3dv = GetProcAddress(OpenGL32Module, "glColor3dv");
    fnglColor3f = GetProcAddress(OpenGL32Module, "glColor3f");
    fnglColor3fv = GetProcAddress(OpenGL32Module, "glColor3fv");
    fnglColor3i = GetProcAddress(OpenGL32Module, "glColor3i");
    fnglColor3iv = GetProcAddress(OpenGL32Module, "glColor3iv");
    fnglColor3s = GetProcAddress(OpenGL32Module, "glColor3s");
    fnglColor3sv = GetProcAddress(OpenGL32Module, "glColor3sv");
    fnglColor3ub = GetProcAddress(OpenGL32Module, "glColor3ub");
    fnglColor3ubv = GetProcAddress(OpenGL32Module, "glColor3ubv");
    fnglColor3ui = GetProcAddress(OpenGL32Module, "glColor3ui");
    fnglColor3uiv = GetProcAddress(OpenGL32Module, "glColor3uiv");
    fnglColor3us = GetProcAddress(OpenGL32Module, "glColor3us");
    fnglColor3usv = GetProcAddress(OpenGL32Module, "glColor3usv");
    fnglColor4b = GetProcAddress(OpenGL32Module, "glColor4b");
    fnglColor4bv = GetProcAddress(OpenGL32Module, "glColor4bv");
    fnglColor4d = GetProcAddress(OpenGL32Module, "glColor4d");
    fnglColor4dv = GetProcAddress(OpenGL32Module, "glColor4dv");
    fnglColor4f = GetProcAddress(OpenGL32Module, "glColor4f");
    fnglColor4fv = GetProcAddress(OpenGL32Module, "glColor4fv");
    fnglColor4i = GetProcAddress(OpenGL32Module, "glColor4i");
    fnglColor4iv = GetProcAddress(OpenGL32Module, "glColor4iv");
    fnglColor4s = GetProcAddress(OpenGL32Module, "glColor4s");
    fnglColor4sv = GetProcAddress(OpenGL32Module, "glColor4sv");
    fnglColor4ub = GetProcAddress(OpenGL32Module, "glColor4ub");
    fnglColor4ubv = GetProcAddress(OpenGL32Module, "glColor4ubv");
    fnglColor4ui = GetProcAddress(OpenGL32Module, "glColor4ui");
    fnglColor4uiv = GetProcAddress(OpenGL32Module, "glColor4uiv");
    fnglColor4us = GetProcAddress(OpenGL32Module, "glColor4us");
    fnglColor4usv = GetProcAddress(OpenGL32Module, "glColor4usv");
    fnglColorMask = GetProcAddress(OpenGL32Module, "glColorMask");
    fnglColorMaterial = GetProcAddress(OpenGL32Module, "glColorMaterial");
    fnglColorPointer = GetProcAddress(OpenGL32Module, "glColorPointer");
    fnglCopyPixels = GetProcAddress(OpenGL32Module, "glCopyPixels");
    fnglCopyTexImage1D = GetProcAddress(OpenGL32Module, "glCopyTexImage1D");
    fnglCopyTexImage2D = GetProcAddress(OpenGL32Module, "glCopyTexImage2D");
    fnglCopyTexSubImage1D = GetProcAddress(OpenGL32Module, "glCopyTexSubImage1D");
    fnglCopyTexSubImage2D = GetProcAddress(OpenGL32Module, "glCopyTexSubImage2D");
    fnglCullFace = GetProcAddress(OpenGL32Module, "glCullFace");
    fnglDebugEntry = GetProcAddress(OpenGL32Module, "glDebugEntry");
    fnglDeleteLists = GetProcAddress(OpenGL32Module, "glDeleteLists");
    fnglDeleteTextures = GetProcAddress(OpenGL32Module, "glDeleteTextures");
    fnglDepthFunc = GetProcAddress(OpenGL32Module, "glDepthFunc");
    fnglDepthMask = GetProcAddress(OpenGL32Module, "glDepthMask");
    fnglDepthRange = GetProcAddress(OpenGL32Module, "glDepthRange");
    fnglDisable = GetProcAddress(OpenGL32Module, "glDisable");
    fnglDisableClientState = GetProcAddress(OpenGL32Module, "glDisableClientState");
    fnglDrawArrays = GetProcAddress(OpenGL32Module, "glDrawArrays");
    fnglDrawBuffer = GetProcAddress(OpenGL32Module, "glDrawBuffer");
    fnglDrawElements = GetProcAddress(OpenGL32Module, "glDrawElements");
    fnglDrawPixels = GetProcAddress(OpenGL32Module, "glDrawPixels");
    fnglEdgeFlag = GetProcAddress(OpenGL32Module, "glEdgeFlag");
    fnglEdgeFlagPointer = GetProcAddress(OpenGL32Module, "glEdgeFlagPointer");
    fnglEdgeFlagv = GetProcAddress(OpenGL32Module, "glEdgeFlagv");
    fnglEnable = GetProcAddress(OpenGL32Module, "glEnable");
    fnglEnableClientState = GetProcAddress(OpenGL32Module, "glEnableClientState");
    fnglEnd = GetProcAddress(OpenGL32Module, "glEnd");
    fnglEndList = GetProcAddress(OpenGL32Module, "glEndList");
    fnglEvalCoord1d = GetProcAddress(OpenGL32Module, "glEvalCoord1d");
    fnglEvalCoord1dv = GetProcAddress(OpenGL32Module, "glEvalCoord1dv");
    fnglEvalCoord1f = GetProcAddress(OpenGL32Module, "glEvalCoord1f");
    fnglEvalCoord1fv = GetProcAddress(OpenGL32Module, "glEvalCoord1fv");
    fnglEvalCoord2d = GetProcAddress(OpenGL32Module, "glEvalCoord2d");
    fnglEvalCoord2dv = GetProcAddress(OpenGL32Module, "glEvalCoord2dv");
    fnglEvalCoord2f = GetProcAddress(OpenGL32Module, "glEvalCoord2f");
    fnglEvalCoord2fv = GetProcAddress(OpenGL32Module, "glEvalCoord2fv");
    fnglEvalMesh1 = GetProcAddress(OpenGL32Module, "glEvalMesh1");
    fnglEvalMesh2 = GetProcAddress(OpenGL32Module, "glEvalMesh2");
    fnglEvalPoint1 = GetProcAddress(OpenGL32Module, "glEvalPoint1");
    fnglEvalPoint2 = GetProcAddress(OpenGL32Module, "glEvalPoint2");
    fnglFeedbackBuffer = GetProcAddress(OpenGL32Module, "glFeedbackBuffer");
    fnglFinish = GetProcAddress(OpenGL32Module, "glFinish");
    fnglFlush = GetProcAddress(OpenGL32Module, "glFlush");
    fnglFogf = GetProcAddress(OpenGL32Module, "glFogf");
    fnglFogfv = GetProcAddress(OpenGL32Module, "glFogfv");
    fnglFogi = GetProcAddress(OpenGL32Module, "glFogi");
    fnglFogiv = GetProcAddress(OpenGL32Module, "glFogiv");
    fnglFrontFace = GetProcAddress(OpenGL32Module, "glFrontFace");
    fnglFrustum = GetProcAddress(OpenGL32Module, "glFrustum");
    fnglGenLists = GetProcAddress(OpenGL32Module, "glGenLists");
    fnglGenTextures = GetProcAddress(OpenGL32Module, "glGenTextures");
    fnglGetBooleanv = GetProcAddress(OpenGL32Module, "glGetBooleanv");
    fnglGetClipPlane = GetProcAddress(OpenGL32Module, "glGetClipPlane");
    fnglGetDoublev = GetProcAddress(OpenGL32Module, "glGetDoublev");
    fnglGetError = GetProcAddress(OpenGL32Module, "glGetError");
    fnglGetFloatv = GetProcAddress(OpenGL32Module, "glGetFloatv");
    fnglGetIntegerv = GetProcAddress(OpenGL32Module, "glGetIntegerv");
    fnglGetLightfv = GetProcAddress(OpenGL32Module, "glGetLightfv");
    fnglGetLightiv = GetProcAddress(OpenGL32Module, "glGetLightiv");
    fnglGetMapdv = GetProcAddress(OpenGL32Module, "glGetMapdv");
    fnglGetMapfv = GetProcAddress(OpenGL32Module, "glGetMapfv");
    fnglGetMapiv = GetProcAddress(OpenGL32Module, "glGetMapiv");
    fnglGetMaterialfv = GetProcAddress(OpenGL32Module, "glGetMaterialfv");
    fnglGetMaterialiv = GetProcAddress(OpenGL32Module, "glGetMaterialiv");
    fnglGetPixelMapfv = GetProcAddress(OpenGL32Module, "glGetPixelMapfv");
    fnglGetPixelMapuiv = GetProcAddress(OpenGL32Module, "glGetPixelMapuiv");
    fnglGetPixelMapusv = GetProcAddress(OpenGL32Module, "glGetPixelMapusv");
    fnglGetPointerv = GetProcAddress(OpenGL32Module, "glGetPointerv");
    fnglGetPolygonStipple = GetProcAddress(OpenGL32Module, "glGetPolygonStipple");
    fnglGetString = GetProcAddress(OpenGL32Module, "glGetString");
    fnglGetTexEnvfv = GetProcAddress(OpenGL32Module, "glGetTexEnvfv");
    fnglGetTexEnviv = GetProcAddress(OpenGL32Module, "glGetTexEnviv");
    fnglGetTexGendv = GetProcAddress(OpenGL32Module, "glGetTexGendv");
    fnglGetTexGenfv = GetProcAddress(OpenGL32Module, "glGetTexGenfv");
    fnglGetTexGeniv = GetProcAddress(OpenGL32Module, "glGetTexGeniv");
    fnglGetTexImage = GetProcAddress(OpenGL32Module, "glGetTexImage");
    fnglGetTexLevelParameterfv = GetProcAddress(OpenGL32Module, "glGetTexLevelParameterfv");
    fnglGetTexLevelParameteriv = GetProcAddress(OpenGL32Module, "glGetTexLevelParameteriv");
    fnglGetTexParameterfv = GetProcAddress(OpenGL32Module, "glGetTexParameterfv");
    fnglGetTexParameteriv = GetProcAddress(OpenGL32Module, "glGetTexParameteriv");
    fnglHint = GetProcAddress(OpenGL32Module, "glHint");
    fnglIndexMask = GetProcAddress(OpenGL32Module, "glIndexMask");
    fnglIndexPointer = GetProcAddress(OpenGL32Module, "glIndexPointer");
    fnglIndexd = GetProcAddress(OpenGL32Module, "glIndexd");
    fnglIndexdv = GetProcAddress(OpenGL32Module, "glIndexdv");
    fnglIndexf = GetProcAddress(OpenGL32Module, "glIndexf");
    fnglIndexfv = GetProcAddress(OpenGL32Module, "glIndexfv");
    fnglIndexi = GetProcAddress(OpenGL32Module, "glIndexi");
    fnglIndexiv = GetProcAddress(OpenGL32Module, "glIndexiv");
    fnglIndexs = GetProcAddress(OpenGL32Module, "glIndexs");
    fnglIndexsv = GetProcAddress(OpenGL32Module, "glIndexsv");
    fnglIndexub = GetProcAddress(OpenGL32Module, "glIndexub");
    fnglIndexubv = GetProcAddress(OpenGL32Module, "glIndexubv");
    fnglInitNames = GetProcAddress(OpenGL32Module, "glInitNames");
    fnglInterleavedArrays = GetProcAddress(OpenGL32Module, "glInterleavedArrays");
    fnglIsEnabled = GetProcAddress(OpenGL32Module, "glIsEnabled");
    fnglIsList = GetProcAddress(OpenGL32Module, "glIsList");
    fnglIsTexture = GetProcAddress(OpenGL32Module, "glIsTexture");
    fnglLightModelf = GetProcAddress(OpenGL32Module, "glLightModelf");
    fnglLightModelfv = GetProcAddress(OpenGL32Module, "glLightModelfv");
    fnglLightModeli = GetProcAddress(OpenGL32Module, "glLightModeli");
    fnglLightModeliv = GetProcAddress(OpenGL32Module, "glLightModeliv");
    fnglLightf = GetProcAddress(OpenGL32Module, "glLightf");
    fnglLightfv = GetProcAddress(OpenGL32Module, "glLightfv");
    fnglLighti = GetProcAddress(OpenGL32Module, "glLighti");
    fnglLightiv = GetProcAddress(OpenGL32Module, "glLightiv");
    fnglLineStipple = GetProcAddress(OpenGL32Module, "glLineStipple");
    fnglLineWidth = GetProcAddress(OpenGL32Module, "glLineWidth");
    fnglListBase = GetProcAddress(OpenGL32Module, "glListBase");
    fnglLoadIdentity = GetProcAddress(OpenGL32Module, "glLoadIdentity");
    fnglLoadMatrixd = GetProcAddress(OpenGL32Module, "glLoadMatrixd");
    fnglLoadMatrixf = GetProcAddress(OpenGL32Module, "glLoadMatrixf");
    fnglLoadName = GetProcAddress(OpenGL32Module, "glLoadName");
    fnglLogicOp = GetProcAddress(OpenGL32Module, "glLogicOp");
    fnglMap1d = GetProcAddress(OpenGL32Module, "glMap1d");
    fnglMap1f = GetProcAddress(OpenGL32Module, "glMap1f");
    fnglMap2d = GetProcAddress(OpenGL32Module, "glMap2d");
    fnglMap2f = GetProcAddress(OpenGL32Module, "glMap2f");
    fnglMapGrid1d = GetProcAddress(OpenGL32Module, "glMapGrid1d");
    fnglMapGrid1f = GetProcAddress(OpenGL32Module, "glMapGrid1f");
    fnglMapGrid2d = GetProcAddress(OpenGL32Module, "glMapGrid2d");
    fnglMapGrid2f = GetProcAddress(OpenGL32Module, "glMapGrid2f");
    fnglMaterialf = GetProcAddress(OpenGL32Module, "glMaterialf");
    fnglMaterialfv = GetProcAddress(OpenGL32Module, "glMaterialfv");
    fnglMateriali = GetProcAddress(OpenGL32Module, "glMateriali");
    fnglMaterialiv = GetProcAddress(OpenGL32Module, "glMaterialiv");
    fnglMatrixMode = GetProcAddress(OpenGL32Module, "glMatrixMode");
    fnglMultMatrixd = GetProcAddress(OpenGL32Module, "glMultMatrixd");
    fnglMultMatrixf = GetProcAddress(OpenGL32Module, "glMultMatrixf");
    fnglNewList = GetProcAddress(OpenGL32Module, "glNewList");
    fnglNormal3b = GetProcAddress(OpenGL32Module, "glNormal3b");
    fnglNormal3bv = GetProcAddress(OpenGL32Module, "glNormal3bv");
    fnglNormal3d = GetProcAddress(OpenGL32Module, "glNormal3d");
    fnglNormal3dv = GetProcAddress(OpenGL32Module, "glNormal3dv");
    fnglNormal3f = GetProcAddress(OpenGL32Module, "glNormal3f");
    fnglNormal3fv = GetProcAddress(OpenGL32Module, "glNormal3fv");
    fnglNormal3i = GetProcAddress(OpenGL32Module, "glNormal3i");
    fnglNormal3iv = GetProcAddress(OpenGL32Module, "glNormal3iv");
    fnglNormal3s = GetProcAddress(OpenGL32Module, "glNormal3s");
    fnglNormal3sv = GetProcAddress(OpenGL32Module, "glNormal3sv");
    fnglNormalPointer = GetProcAddress(OpenGL32Module, "glNormalPointer");
    fnglOrtho = GetProcAddress(OpenGL32Module, "glOrtho");
    fnglPassThrough = GetProcAddress(OpenGL32Module, "glPassThrough");
    fnglPixelMapfv = GetProcAddress(OpenGL32Module, "glPixelMapfv");
    fnglPixelMapuiv = GetProcAddress(OpenGL32Module, "glPixelMapuiv");
    fnglPixelMapusv = GetProcAddress(OpenGL32Module, "glPixelMapusv");
    fnglPixelStoref = GetProcAddress(OpenGL32Module, "glPixelStoref");
    fnglPixelStorei = GetProcAddress(OpenGL32Module, "glPixelStorei");
    fnglPixelTransferf = GetProcAddress(OpenGL32Module, "glPixelTransferf");
    fnglPixelTransferi = GetProcAddress(OpenGL32Module, "glPixelTransferi");
    fnglPixelZoom = GetProcAddress(OpenGL32Module, "glPixelZoom");
    fnglPointSize = GetProcAddress(OpenGL32Module, "glPointSize");
    fnglPolygonMode = GetProcAddress(OpenGL32Module, "glPolygonMode");
    fnglPolygonOffset = GetProcAddress(OpenGL32Module, "glPolygonOffset");
    fnglPolygonStipple = GetProcAddress(OpenGL32Module, "glPolygonStipple");
    fnglPopAttrib = GetProcAddress(OpenGL32Module, "glPopAttrib");
    fnglPopClientAttrib = GetProcAddress(OpenGL32Module, "glPopClientAttrib");
    fnglPopMatrix = GetProcAddress(OpenGL32Module, "glPopMatrix");
    fnglPopName = GetProcAddress(OpenGL32Module, "glPopName");
    fnglPrioritizeTextures = GetProcAddress(OpenGL32Module, "glPrioritizeTextures");
    fnglPushAttrib = GetProcAddress(OpenGL32Module, "glPushAttrib");
    fnglPushClientAttrib = GetProcAddress(OpenGL32Module, "glPushClientAttrib");
    fnglPushMatrix = GetProcAddress(OpenGL32Module, "glPushMatrix");
    fnglPushName = GetProcAddress(OpenGL32Module, "glPushName");
    fnglRasterPos2d = GetProcAddress(OpenGL32Module, "glRasterPos2d");
    fnglRasterPos2dv = GetProcAddress(OpenGL32Module, "glRasterPos2dv");
    fnglRasterPos2f = GetProcAddress(OpenGL32Module, "glRasterPos2f");
    fnglRasterPos2fv = GetProcAddress(OpenGL32Module, "glRasterPos2fv");
    fnglRasterPos2i = GetProcAddress(OpenGL32Module, "glRasterPos2i");
    fnglRasterPos2iv = GetProcAddress(OpenGL32Module, "glRasterPos2iv");
    fnglRasterPos2s = GetProcAddress(OpenGL32Module, "glRasterPos2s");
    fnglRasterPos2sv = GetProcAddress(OpenGL32Module, "glRasterPos2sv");
    fnglRasterPos3d = GetProcAddress(OpenGL32Module, "glRasterPos3d");
    fnglRasterPos3dv = GetProcAddress(OpenGL32Module, "glRasterPos3dv");
    fnglRasterPos3f = GetProcAddress(OpenGL32Module, "glRasterPos3f");
    fnglRasterPos3fv = GetProcAddress(OpenGL32Module, "glRasterPos3fv");
    fnglRasterPos3i = GetProcAddress(OpenGL32Module, "glRasterPos3i");
    fnglRasterPos3iv = GetProcAddress(OpenGL32Module, "glRasterPos3iv");
    fnglRasterPos3s = GetProcAddress(OpenGL32Module, "glRasterPos3s");
    fnglRasterPos3sv = GetProcAddress(OpenGL32Module, "glRasterPos3sv");
    fnglRasterPos4d = GetProcAddress(OpenGL32Module, "glRasterPos4d");
    fnglRasterPos4dv = GetProcAddress(OpenGL32Module, "glRasterPos4dv");
    fnglRasterPos4f = GetProcAddress(OpenGL32Module, "glRasterPos4f");
    fnglRasterPos4fv = GetProcAddress(OpenGL32Module, "glRasterPos4fv");
    fnglRasterPos4i = GetProcAddress(OpenGL32Module, "glRasterPos4i");
    fnglRasterPos4iv = GetProcAddress(OpenGL32Module, "glRasterPos4iv");
    fnglRasterPos4s = GetProcAddress(OpenGL32Module, "glRasterPos4s");
    fnglRasterPos4sv = GetProcAddress(OpenGL32Module, "glRasterPos4sv");
    fnglReadBuffer = GetProcAddress(OpenGL32Module, "glReadBuffer");
    fnglReadPixels = GetProcAddress(OpenGL32Module, "glReadPixels");
    fnglRectd = GetProcAddress(OpenGL32Module, "glRectd");
    fnglRectdv = GetProcAddress(OpenGL32Module, "glRectdv");
    fnglRectf = GetProcAddress(OpenGL32Module, "glRectf");
    fnglRectfv = GetProcAddress(OpenGL32Module, "glRectfv");
    fnglRecti = GetProcAddress(OpenGL32Module, "glRecti");
    fnglRectiv = GetProcAddress(OpenGL32Module, "glRectiv");
    fnglRects = GetProcAddress(OpenGL32Module, "glRects");
    fnglRectsv = GetProcAddress(OpenGL32Module, "glRectsv");
    fnglRenderMode = GetProcAddress(OpenGL32Module, "glRenderMode");
    fnglRotated = GetProcAddress(OpenGL32Module, "glRotated");
    fnglRotatef = GetProcAddress(OpenGL32Module, "glRotatef");
    fnglScaled = GetProcAddress(OpenGL32Module, "glScaled");
    fnglScalef = GetProcAddress(OpenGL32Module, "glScalef");
    fnglScissor = GetProcAddress(OpenGL32Module, "glScissor");
    fnglSelectBuffer = GetProcAddress(OpenGL32Module, "glSelectBuffer");
    fnglShadeModel = GetProcAddress(OpenGL32Module, "glShadeModel");
    fnglStencilFunc = GetProcAddress(OpenGL32Module, "glStencilFunc");
    fnglStencilMask = GetProcAddress(OpenGL32Module, "glStencilMask");
    fnglStencilOp = GetProcAddress(OpenGL32Module, "glStencilOp");
    fnglTexCoord1d = GetProcAddress(OpenGL32Module, "glTexCoord1d");
    fnglTexCoord1dv = GetProcAddress(OpenGL32Module, "glTexCoord1dv");
    fnglTexCoord1f = GetProcAddress(OpenGL32Module, "glTexCoord1f");
    fnglTexCoord1fv = GetProcAddress(OpenGL32Module, "glTexCoord1fv");
    fnglTexCoord1i = GetProcAddress(OpenGL32Module, "glTexCoord1i");
    fnglTexCoord1iv = GetProcAddress(OpenGL32Module, "glTexCoord1iv");
    fnglTexCoord1s = GetProcAddress(OpenGL32Module, "glTexCoord1s");
    fnglTexCoord1sv = GetProcAddress(OpenGL32Module, "glTexCoord1sv");
    fnglTexCoord2d = GetProcAddress(OpenGL32Module, "glTexCoord2d");
    fnglTexCoord2dv = GetProcAddress(OpenGL32Module, "glTexCoord2dv");
    fnglTexCoord2f = GetProcAddress(OpenGL32Module, "glTexCoord2f");
    fnglTexCoord2fv = GetProcAddress(OpenGL32Module, "glTexCoord2fv");
    fnglTexCoord2i = GetProcAddress(OpenGL32Module, "glTexCoord2i");
    fnglTexCoord2iv = GetProcAddress(OpenGL32Module, "glTexCoord2iv");
    fnglTexCoord2s = GetProcAddress(OpenGL32Module, "glTexCoord2s");
    fnglTexCoord2sv = GetProcAddress(OpenGL32Module, "glTexCoord2sv");
    fnglTexCoord3d = GetProcAddress(OpenGL32Module, "glTexCoord3d");
    fnglTexCoord3dv = GetProcAddress(OpenGL32Module, "glTexCoord3dv");
    fnglTexCoord3f = GetProcAddress(OpenGL32Module, "glTexCoord3f");
    fnglTexCoord3fv = GetProcAddress(OpenGL32Module, "glTexCoord3fv");
    fnglTexCoord3i = GetProcAddress(OpenGL32Module, "glTexCoord3i");
    fnglTexCoord3iv = GetProcAddress(OpenGL32Module, "glTexCoord3iv");
    fnglTexCoord3s = GetProcAddress(OpenGL32Module, "glTexCoord3s");
    fnglTexCoord3sv = GetProcAddress(OpenGL32Module, "glTexCoord3sv");
    fnglTexCoord4d = GetProcAddress(OpenGL32Module, "glTexCoord4d");
    fnglTexCoord4dv = GetProcAddress(OpenGL32Module, "glTexCoord4dv");
    fnglTexCoord4f = GetProcAddress(OpenGL32Module, "glTexCoord4f");
    fnglTexCoord4fv = GetProcAddress(OpenGL32Module, "glTexCoord4fv");
    fnglTexCoord4i = GetProcAddress(OpenGL32Module, "glTexCoord4i");
    fnglTexCoord4iv = GetProcAddress(OpenGL32Module, "glTexCoord4iv");
    fnglTexCoord4s = GetProcAddress(OpenGL32Module, "glTexCoord4s");
    fnglTexCoord4sv = GetProcAddress(OpenGL32Module, "glTexCoord4sv");
    fnglTexCoordPointer = GetProcAddress(OpenGL32Module, "glTexCoordPointer");
    fnglTexEnvf = GetProcAddress(OpenGL32Module, "glTexEnvf");
    fnglTexEnvfv = GetProcAddress(OpenGL32Module, "glTexEnvfv");
    fnglTexEnvi = GetProcAddress(OpenGL32Module, "glTexEnvi");
    fnglTexEnviv = GetProcAddress(OpenGL32Module, "glTexEnviv");
    fnglTexGend = GetProcAddress(OpenGL32Module, "glTexGend");
    fnglTexGendv = GetProcAddress(OpenGL32Module, "glTexGendv");
    fnglTexGenf = GetProcAddress(OpenGL32Module, "glTexGenf");
    fnglTexGenfv = GetProcAddress(OpenGL32Module, "glTexGenfv");
    fnglTexGeni = GetProcAddress(OpenGL32Module, "glTexGeni");
    fnglTexGeniv = GetProcAddress(OpenGL32Module, "glTexGeniv");
    fnglTexImage1D = GetProcAddress(OpenGL32Module, "glTexImage1D");
    fnglTexImage2D = GetProcAddress(OpenGL32Module, "glTexImage2D");
    fnglTexParameterf = GetProcAddress(OpenGL32Module, "glTexParameterf");
    fnglTexParameterfv = GetProcAddress(OpenGL32Module, "glTexParameterfv");
    fnglTexParameteri = GetProcAddress(OpenGL32Module, "glTexParameteri");
    fnglTexParameteriv = GetProcAddress(OpenGL32Module, "glTexParameteriv");
    fnglTexSubImage1D = GetProcAddress(OpenGL32Module, "glTexSubImage1D");
    fnglTexSubImage2D = GetProcAddress(OpenGL32Module, "glTexSubImage2D");
    fnglTranslated = GetProcAddress(OpenGL32Module, "glTranslated");
    fnglTranslatef = GetProcAddress(OpenGL32Module, "glTranslatef");
    fnglVertex2d = GetProcAddress(OpenGL32Module, "glVertex2d");
    fnglVertex2dv = GetProcAddress(OpenGL32Module, "glVertex2dv");
    fnglVertex2f = GetProcAddress(OpenGL32Module, "glVertex2f");
    fnglVertex2fv = GetProcAddress(OpenGL32Module, "glVertex2fv");
    fnglVertex2i = GetProcAddress(OpenGL32Module, "glVertex2i");
    fnglVertex2iv = GetProcAddress(OpenGL32Module, "glVertex2iv");
    fnglVertex2s = GetProcAddress(OpenGL32Module, "glVertex2s");
    fnglVertex2sv = GetProcAddress(OpenGL32Module, "glVertex2sv");
    fnglVertex3d = GetProcAddress(OpenGL32Module, "glVertex3d");
    fnglVertex3dv = GetProcAddress(OpenGL32Module, "glVertex3dv");
    fnglVertex3f = GetProcAddress(OpenGL32Module, "glVertex3f");
    fnglVertex3fv = GetProcAddress(OpenGL32Module, "glVertex3fv");
    fnglVertex3i = GetProcAddress(OpenGL32Module, "glVertex3i");
    fnglVertex3iv = GetProcAddress(OpenGL32Module, "glVertex3iv");
    fnglVertex3s = GetProcAddress(OpenGL32Module, "glVertex3s");
    fnglVertex3sv = GetProcAddress(OpenGL32Module, "glVertex3sv");
    fnglVertex4d = GetProcAddress(OpenGL32Module, "glVertex4d");
    fnglVertex4dv = GetProcAddress(OpenGL32Module, "glVertex4dv");
    fnglVertex4f = GetProcAddress(OpenGL32Module, "glVertex4f");
    fnglVertex4fv = GetProcAddress(OpenGL32Module, "glVertex4fv");
    fnglVertex4i = GetProcAddress(OpenGL32Module, "glVertex4i");
    fnglVertex4iv = GetProcAddress(OpenGL32Module, "glVertex4iv");
    fnglVertex4s = GetProcAddress(OpenGL32Module, "glVertex4s");
    fnglVertex4sv = GetProcAddress(OpenGL32Module, "glVertex4sv");
    fnglVertexPointer = GetProcAddress(OpenGL32Module, "glVertexPointer");
    fnglViewport = GetProcAddress(OpenGL32Module, "glViewport");
    fnwglChoosePixelFormat = GetProcAddress(OpenGL32Module, "wglChoosePixelFormat");
    fnwglCopyContext = GetProcAddress(OpenGL32Module, "wglCopyContext");
    fnwglCreateContext = GetProcAddress(OpenGL32Module, "wglCreateContext");
    fnwglCreateLayerContext = GetProcAddress(OpenGL32Module, "wglCreateLayerContext");
    fnwglDeleteContext = GetProcAddress(OpenGL32Module, "wglDeleteContext");
    fnwglDescribeLayerPlane = GetProcAddress(OpenGL32Module, "wglDescribeLayerPlane");
    fnwglDescribePixelFormat = GetProcAddress(OpenGL32Module, "wglDescribePixelFormat");
    fnwglGetCurrentContext = GetProcAddress(OpenGL32Module, "wglGetCurrentContext");
    fnwglGetCurrentDC = GetProcAddress(OpenGL32Module, "wglGetCurrentDC");
    fnwglGetDefaultProcAddress = GetProcAddress(OpenGL32Module, "wglGetDefaultProcAddress");
    fnwglGetLayerPaletteEntries = GetProcAddress(OpenGL32Module, "wglGetLayerPaletteEntries");
    fnwglGetPixelFormat = GetProcAddress(OpenGL32Module, "wglGetPixelFormat");
    fnwglGetProcAddress = GetProcAddress(OpenGL32Module, "wglGetProcAddress");
    fnwglMakeCurrent = GetProcAddress(OpenGL32Module, "wglMakeCurrent");
    fnwglRealizeLayerPalette = GetProcAddress(OpenGL32Module, "wglRealizeLayerPalette");
    fnwglSetLayerPaletteEntries = GetProcAddress(OpenGL32Module, "wglSetLayerPaletteEntries");
    fnwglSetPixelFormat = GetProcAddress(OpenGL32Module, "wglSetPixelFormat");
    fnwglShareLists = GetProcAddress(OpenGL32Module, "wglShareLists");
    fnwglSwapBuffers = GetProcAddress(OpenGL32Module, "wglSwapBuffers");
    fnwglSwapLayerBuffers = GetProcAddress(OpenGL32Module, "wglSwapLayerBuffers");
    fnwglSwapMultipleBuffers = GetProcAddress(OpenGL32Module, "wglSwapMultipleBuffers");
    fnwglUseFontBitmapsA = GetProcAddress(OpenGL32Module, "wglUseFontBitmapsA");
    fnwglUseFontBitmapsW = GetProcAddress(OpenGL32Module, "wglUseFontBitmapsW");
    fnwglUseFontOutlinesA = GetProcAddress(OpenGL32Module, "wglUseFontOutlinesA");
    fnwglUseFontOutlinesW = GetProcAddress(OpenGL32Module, "wglUseFontOutlinesW");
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        LoadOpenGL32();
        Patch(hModule);
        break;
    }

    case DLL_PROCESS_DETACH:
    {
        //Clean();
        break;
    }

    default:
        break;
    }

    return TRUE;
}
