# dwm version
VERSION = 6.4

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib


# Xinerama, comment if you don't want it
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

# Uncomment this for the alpha patch and the winicon patch (BAR_ALPHA_PATCH, BAR_WINICON_PATCH)
XRENDER = -lXrender

# Uncomment this for the mdpcontrol patch / MDPCONTROL_PATCH
#MPDCLIENT = -lmpdclient

# Uncomment for the pango patch / BAR_PANGO_PATCH
#PANGOINC = `pkg-config --cflags xft pango pangoxft`
#PANGOLIB = `pkg-config --libs xft pango pangoxft`

# Uncomment for the ipc patch / IPC_PATCH
#YAJLLIBS = -lyajl
#YAJLINC = -I/usr/include/yajl

# Uncomment this for the rounded corners patch / ROUNDED_CORNERS_PATCH
XEXTLIB = -lXext

# Uncomment this for the swallow patch / SWALLOW_PATCH
#XCBLIBS = -lX11-xcb -lxcb -lxcb-res

# This is needed for the winicon and tagpreview patches / BAR_WINICON_PATCH / BAR_TAGPREVIEW_PATCH
IMLIB2LIBS = -lImlib2

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC} ${YAJLINC} ${PANGOINC} ${BDINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}  ${XRENDER} ${MPDCLIENT} ${XEXTLIB} ${XCBLIBS} ${KVMLIB} ${PANGOLIB} ${YAJLLIBS} ${IMLIB2LIBS} $(BDLIBS)

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
#CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-unused-function -Wno-deprecated-declarations -O2 -march=native ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}


# compiler and linker
CC = cc
