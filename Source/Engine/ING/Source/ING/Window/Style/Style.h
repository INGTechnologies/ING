#pragma once


#ifdef USE_MSVC

/*
 * Window Styles
 */
#define ING_WS_OVERLAPPED       0x00000000L
#define ING_WS_POPUP            0x80000000L
#define ING_WS_CHILD            0x40000000L
#define ING_WS_MINIMIZE         0x20000000L
#define ING_WS_VISIBLE          0x10000000L
#define ING_WS_DISABLED         0x08000000L
#define ING_WS_CLIPSIBLINGS     0x04000000L
#define ING_WS_CLIPCHILDREN     0x02000000L
#define ING_WS_MAXIMIZE         0x01000000L
#define ING_WS_CAPTION          0x00C00000L     /* ING_WS_BORDER | ING_WS_DLGFRAME  */
#define ING_WS_BORDER           0x00800000L
#define ING_WS_DLGFRAME         0x00400000L
#define ING_WS_VSCROLL          0x00200000L
#define ING_WS_HSCROLL          0x00100000L
#define ING_WS_SYSMENU          0x00080000L
#define ING_WS_THICKFRAME       0x00040000L
#define ING_WS_GROUP            0x00020000L
#define ING_WS_TABSTOP          0x00010000L

#define ING_WS_MINIMIZEBOX      0x00020000L
#define ING_WS_MAXIMIZEBOX      0x00010000L


#define ING_WS_TILED            ING_WS_OVERLAPPED
#define ING_WS_ICONIC           ING_WS_MINIMIZE
#define ING_WS_SIZEBOX          ING_WS_THICKFRAME
#define ING_WS_TILEDWINDOW      ING_WS_OVERLAPPEDWINDOW

/*
 * Common Window Styles
 */
#define ING_WS_OVERLAPPEDWINDOW (ING_WS_OVERLAPPED     | \
                             ING_WS_CAPTION        | \
                             ING_WS_SYSMENU        | \
                             ING_WS_THICKFRAME     | \
                             ING_WS_MINIMIZEBOX    | \
                             ING_WS_MAXIMIZEBOX)

#define ING_WS_POPUPWINDOW      (ING_WS_POPUP          | \
                             ING_WS_BORDER         | \
                             ING_WS_SYSMENU)

#define ING_WS_CHILDWINDOW      (ING_WS_CHILD)

/*
 * Extended Window Styles
 */
#define ING_WS_EX_DLGMODALFRAME     0x00000001L
#define ING_WS_EX_NOPARENTNOTIFY    0x00000004L
#define ING_WS_EX_TOPMOST           0x00000008L
#define ING_WS_EX_ACCEPTFILES       0x00000010L
#define ING_WS_EX_TRANSPARENT       0x00000020L
#define ING_WS_EX_MDICHILD          0x00000040L
#define ING_WS_EX_TOOLWINDOW        0x00000080L
#define ING_WS_EX_WINDOWEDGE        0x00000100L
#define ING_WS_EX_CLIENTEDGE        0x00000200L
#define ING_WS_EX_CONTEXTHELP       0x00000400L

#define ING_WS_EX_RIGHT             0x00001000L
#define ING_WS_EX_LEFT              0x00000000L
#define ING_WS_EX_RTLREADING        0x00002000L
#define ING_WS_EX_LTRREADING        0x00000000L
#define ING_WS_EX_LEFTSCROLLBAR     0x00004000L
#define ING_WS_EX_RIGHTSCROLLBAR    0x00000000L

#define ING_WS_EX_CONTROLPARENT     0x00010000L
#define ING_WS_EX_STATICEDGE        0x00020000L
#define ING_WS_EX_APPWINDOW         0x00040000L


#define ING_WS_EX_OVERLAPPEDWINDOW  (ING_WS_EX_WINDOWEDGE | ING_WS_EX_CLIENTEDGE)
#define ING_WS_EX_PALETTEWINDOW     (ING_WS_EX_WINDOWEDGE | ING_WS_EX_TOOLWINDOW | ING_WS_EX_TOPMOST)

#define ING_WS_EX_LAYERED           0x00080000

#define ING_WS_EX_NOINHERITLAYOUT   0x00100000L // Disable inheritence of mirroring by children

#define ING_WS_EX_NOREDIRECTIONBITMAP 0x00200000L

#define ING_WS_EX_LAYOUTRTL         0x00400000L // Right to left mirroring

#define ING_WS_EX_COMPOSITED        0x02000000L

#define ING_WS_EX_NOACTIVATE        0x08000000L

#endif