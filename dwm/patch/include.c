/* Bar functionality */
#include "bar_indicators.c"
#include "bar_tagicons.c"
#include "bar.c"

#include "bar_anybar.c"
#include "bar_ewmhtags.c"
#include "bar_ltsymbol.c"
#include "bar_status.c"
#include "bar_tags.c"
#include "bar_wintitle.c"

/* Other patches */
#include "attachx.c"
#include "cfacts.c"
#include "dragcfact.c"
#include "dwmc.c"
#include "focusdir.c"
#include "focusurgent.c"
#include "ipc.c"
#ifdef VERSION
#include "ipc/IPCClient.c"
#include "ipc/yajl_dumps.c"
#include "ipc/ipc.c"
#include "ipc/util.c"
#endif
#include "insets.c"
#include "killunsel.c"
#include "moveresize.c"
#include "reorganizetags.c"
#include "restartsig.c"
#include "roundedcorners.c"
#include "scratchpad.c"
#include "scratchpad_alt_1.c"
#include "sticky.c"
#include "swallow.c"
#include "togglefullscreen.c"
#include "vanitygaps.c"
#include "dragmfact.c"
#include "seamless_restart.c"
/* Layouts */
#include "layout_facts.c"
#include "layout_centeredmaster.c"
#include "layout_fibonacci.c"
#include "layout_monocle.c"
#include "layout_tile.c"
