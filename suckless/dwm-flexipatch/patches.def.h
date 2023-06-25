
#define BAR_AWESOMEBAR_PATCH 0


#define BAR_DWMBLOCKS_PATCH 0

#define BAR_DWMBLOCKS_SIGUSR1_PATCH 0

#define BAR_FANCYBAR_PATCH 0


#define BAR_FLEXWINTITLE_PATCH 0

#define BAR_LAYOUTMENU_PATCH 0

/* Show layout symbol in bar */
#define BAR_LTSYMBOL_PATCH 1

#define BAR_POWERLINE_STATUS_PATCH 0


#define BAR_POWERLINE_TAGS_PATCH 0


#define BAR_POWERLINE_TAGS_SLASH_PATCH 0
#define BAR_TABGROUPS_PATCH 0

#define BAR_TAGGRID_PATCH 0

/* Hover tag icons to see a preview of the windows on that tag.
 *
 * The patch depends on Imlib2 for icon scaling.
 * You need to uncomment the corresponding line in config.mk to use the -lImlib2 library
 *
 * Arch Linux:
 *     sudo pacman -S imlib2
 * Debian:
 *     sudo apt install libimlib2-dev
 *
 * As with the winicon patch you may want to consider adding the compiler flags of -O3 and
 * -march=native to enable auto loop vectorize for better performance.
 *
 * https://dwm.suckless.org/patches/tag-previews/
 */
#define BAR_TAGPREVIEW_PATCH 1

/* Show status in bar */
#define BAR_STATUS_PATCH 1

/* This patch adds a clickable button to the left hand side of the statusbar.
 * https://dwm.suckless.org/patches/statusbutton/
 */
#define BAR_STATUSBUTTON_PATCH 1

/* This patch adds the ability to execute shell commands based on the mouse button and position
 * when clicking the status bar. Refer to the website for usage.
 * https://dwm.suckless.org/patches/statuscmd/
 */
#define BAR_STATUSCMD_PATCH 1

/* Status2d allows colors and rectangle drawing in your dwm status bar.
 * This patch is incompatible with the statuscolors patch which takes precedence.
 * This patch is incompatible with the extrabar patch.
 * https://dwm.suckless.org/patches/status2d/
 */
#define BAR_STATUS2D_PATCH 1


#define BAR_STATUS2D_NO_ALPHA_PATCH 1


#define BAR_STATUS2D_XRDB_TERMCOLORS_PATCH 0

/* The systray patch adds systray for the status bar.
 * https://dwm.suckless.org/patches/systray/
 */
#define BAR_SYSTRAY_PATCH 1

/* Show tag symbols in the bar. */
#define BAR_TAGS_PATCH 1


#define BAR_TAGLABELS_PATCH 0

/* This patch underlines the selected tag, or optionally all tags.
 * https://dwm.suckless.org/patches/underlinetags/
 */
#define BAR_UNDERLINETAGS_PATCH 1


#define BAR_WINICON_PATCH 1

/* Show window title in bar */
#define BAR_WINTITLE_PATCH 0

#define BAR_WINTITLE_FLOATING_PATCH 0


#define BAR_WINTITLE_HIDDEN_PATCH 0

/* Title bar modules such as wintitle (default), fancybar and awesomebar
 * do not by default add left and/or right padding as they take up the
 * remaining space. These options allow you explicitly add padding should
 * you need it.
 */
#define BAR_TITLE_RIGHT_PAD_PATCH 1
#define BAR_TITLE_LEFT_PAD_PATCH 1

#define BAR_ACTIVETAGINDICATORBAR_PATCH N/A


#define BAR_ACTIVETAGINDICATORBAR_ALT1_PATCH N/A

/* The alpha patch adds transparency for the status bar.
 * You need to uncomment the corresponding line in config.mk to use the -lXrender library
 * when including this patch.
 * https://dwm.suckless.org/patches/alpha/
 */
#define BAR_ALPHA_PATCH 1


#define BAR_ALTERNATIVE_TAGS_PATCH 0


#define BAR_ALTTAGSDECORATION_PATCH 0


#define BAR_ANYBAR_PATCH 0

#define BAR_ANYBAR_TOP_AND_BOTTOM_BARS_PATCH 0


#define BAR_ANYBAR_MANAGE_WIDTH_PATCH 0

#define BAR_BORDER_PATCH 0

#define BAR_CENTEREDWINDOWNAME_PATCH 0


#define BAR_CLIENTINDICATOR_PATCH N/A


#define BAR_DMENUMATCHTOP_PATCH 0


#define BAR_EXTRASTATUS_PATCH 0


#define BAR_EWMHTAGS_PATCH 0

/* Allows the bar height to be explicitly set rather than being derived from font.
 * https://dwm.suckless.org/patches/bar_height/
 */
#define BAR_HEIGHT_PATCH 1


#define BAR_HIDEVACANTTAGS_PATCH 0


#define BAR_HOLDBAR_PATCH 0

#define BAR_IGNORE_XFT_ERRORS_WHEN_DRAWING_TEXT_PATCH 0


#define BAR_NO_COLOR_EMOJI_PATCH 0

/* This patch adds vertical and horizontal space between the statusbar and the edge of the screen.
 * https://dwm.suckless.org/patches/barpadding/
 */
#define BAR_PADDING_PATCH 1

/* Same as barpadding patch but specifically tailored f1r the vanitygaps patch in that the outer
 * bar padding is derived from the vanitygaps settings. In addition to this the bar padding is
 * toggled in unison when vanitygaps are toggled. Increasing or decreasing gaps during runtime
 * will not affect the bar padding.
 */
#define BAR_PADDING_VANITYGAPS_PATCH 1


#define BAR_PANGO_PATCH 0

#define BAR_STATICSTATUS_PATCH 0

/* This patch draws and updates the statusbar on all monitors.
 * https://dwm.suckless.org/patches/statusallmons/
 */
#define BAR_STATUSALLMONS_PATCH 1

#define BAR_STATUSCOLORS_PATCH 0

/* This patch adds configuration options for horizontal and vertical padding in the status bar.
 * https://dwm.suckless.org/patches/statuspadding/
 */
#define BAR_STATUSPADDING_PATCH 1


#define BAR_VTCOLORS_PATCH 0


#define BAR_WINTITLEACTIONS_PATCH BAR_AWESOMEBAR_PATCH || BAR_TABGROUPS_PATCH || BAR_FLEXWINTITLE_PATCH


#define ALT_TAB_PATCH 0

#define ALWAYSCENTER_PATCH 0

#define ASPECTRESIZE_PATCH 0
#define ATTACHABOVE_PATCH 0

/* This patch adds new clients on top of the stack.
 * This patch takes precedence over ATTACHBELOW_PATCH.
 * https://dwm.suckless.org/patches/attachaside/
 */
#define ATTACHASIDE_PATCH 1

#define ATTACHBELOW_PATCH 0

#define ATTACHBOTTOM_PATCH 0
#define AUTOSTART_PATCH 0

#define AUTORESIZE_PATCH 0

#define BIDI_PATCH 0

/* This patch adds an iscentered rule to automatically center clients on the current monitor.
 * This patch takes precedence over centeredwindowname, alwayscenter and fancybar patches.
 * https://dwm.suckless.org/patches/center/
 */
#define CENTER_PATCH 1

#define CENTER_TRANSIENT_WINDOWS_PATCH 0

/* As above, except that the transient window is centered within the position of the parent
 * window, rather than at the center of the screen. This takes precedence over the above patch.
 */
#define CENTER_TRANSIENT_WINDOWS_BY_PARENT_PATCH 1

/* This patch provides the ability to assign different weights to clients in their
 * respective stack in tiled layout.
 * https://dwm.suckless.org/patches/cfacts/
 */
#define CFACTS_PATCH 1

#define CMDCUSTOMIZE_PATCH 0

#define COMBO_PATCH 0

#define COOL_AUTOSTART_PATCH 0

#define CYCLELAYOUTS_PATCH 0

#define DECORATION_HINTS_PATCH 0


#define DISTRIBUTETAGS_PATCH 0

/* Similarly to the dragmfact patch this allows you to click and drag clients to change the
 * cfact to adjust the client's size in the stack. This patch depends on the cfacts patch.
 */
#define DRAGCFACT_PATCH 1

/* This patch lets you resize the split in the tile layout (i.e. modify mfact) by holding
 * the modkey and dragging the mouse.
 * This patch can be a bit wonky with other layouts, but generally works.
 * https://dwm.suckless.org/patches/dragmfact/
 */
#define DRAGMFACT_PATCH 1

/* Simple dwmc client using a fork of fsignal to communicate with dwm.
 * To use this either copy the patch/dwmc shell script to somewhere in your path or
 * uncomment the following line in Makefile:
 *    #cp -f patch/dwmc ${DESTDIR}${PREFIX}/bin
 * http://dwm.suckless.org/patches/dwmc/
 */
#define DWMC_PATCH 1


#define EMPTYVIEW_PATCH 0


#define EXRESIZE_PATCH 0


#define FAKEFULLSCREEN_PATCH 0


#define FAKEFULLSCREEN_CLIENT_PATCH 0


#define FLOATPOS_PATCH 0


#define FLOATPOS_RESPECT_GAPS_PATCH 0


#define FOCUSADJACENTTAG_PATCH 0


#define FOCUSDIR_PATCH 0


#define FOCUSMASTER_PATCH 0


#define FOCUSONCLICK_PATCH 0


#define FOCUSURGENT_PATCH 0


#define FOCUSONNETACTIVE_PATCH 0

#define FSIGNAL_PATCH 0


#define FULLSCREEN_PATCH 0

#define INPLACEROTATE_PATCH 0


#define INSETS_PATCH 0


#define IPC_PATCH 0


#define ISPERMANENT_PATCH 0

#define KEYMODES_PATCH 0


#define KILLUNSEL_PATCH 0

/* This changes the window manager name to LG3d instead of dwm as a workaround for Java
 * applications that assume that the window manager is using window reparenting.
 * Refer to the ISSUES secton of the dwm man page for more details.
 */
#define LG3D_PATCH 1


#define LOSEFULLSCREEN_PATCH 0


#define MAXIMIZE_PATCH 0


#define MPDCONTROL_PATCH 0

/* Adds rules per monitor, e.g. have default layouts per monitor.
 * The use case for this is if the second monitor is vertical (i.e. rotated) then
 * you may want to use a different default layout for this monitor than what is
 * used for the main monitor. E.g. normal vertical split for main monitor and
 * horizontal split for the second.
 */
#define MONITOR_RULES_PATCH 1


#define MONOCLESYMBOL_PATCH 0

#define MOVEPLACE_PATCH 0


#define MOVERESIZE_PATCH 0


#define MOVESTACK_PATCH 1


#define NAMETAG_PATCH 0


#define NAMETAG_PREPEND_PATCH 0


#define NET_CLIENT_LIST_STACKING_PATCH 0


#define NOBORDER_PATCH 0

/* Enable modifying or removing dmenu in config.def.h which resulted previously in a
 * compilation error because two lines of code hardcode dmenu into dwm.
 * https://dwm.suckless.org/patches/nodmenu/
 */
#define NODMENU_PATCH 1


#define NO_MOD_BUTTONS_PATCH 0


#define NO_TRANSPARENT_BORDERS_PATCH 0

#define ON_EMPTY_KEYS_PATCH 0


#define ONLY_ONE_RULE_MATCH_PATCH 0

#define ONLYQUITONEMPTY_PATCH 0


#define PERTAG_PATCH 0


#define PERTAG_VANITYGAPS_PATCH 0

#define PERTAGBAR_PATCH 0


#define PLACEMOUSE_PATCH 0

/* This patch provides a way to move clients up and down inside the client list.
 * https://dwm.suckless.org/patches/push/
 */
#define PUSH_PATCH 1


#define PUSH_NO_MASTER_PATCH 0


#define RENAMED_SCRATCHPADS_PATCH 0


#define RENAMED_SCRATCHPADS_AUTO_HIDE_PATCH 0


#define REORGANIZETAGS_PATCH 0

#define RESIZECORNERS_PATCH 0

/* Practically the same as resizecorners, but the cursor does not warp to corners.
 * This takes precedence over the resizecorners patch.
 * https://github.com/bakkeby/patches/blob/master/dwm/dwm-resizepoint-6.2.diff
 */
#define RESIZEPOINT_PATCH 1

/* Adds a keyboard shortcut to restart dwm or alternatively by using kill -HUP dwmpid.
 * Additionally dwm can quit cleanly by using kill -TERM dwmpid.
 * https://dwm.suckless.org/patches/restartsig/
 */
#define RESTARTSIG_PATCH 1


#define RIODRAW_PATCH 0

/* This patch let's you rotate through the stack using keyboard shortcuts.
 * https://dwm.suckless.org/patches/rotatestack/
 */
#define ROTATESTACK_PATCH 1

/* This patch adds rounded corners to client windows in dwm.
 * You need to uncomment the corresponding line in config.mk to use the -lXext library
 * when including this patch. You will also want to set "borderpx = 0;" in your config.h.
 * https://github.com/mitchweaver/suckless/blob/master/dwm/patches/mitch-06-rounded_corners-f04cac6d6e39cd9e3fc4fae526e3d1e8df5e34b2.patch
 */
#define ROUNDED_CORNERS_PATCH 1

/* This patch saves size and position of every floating window before it is forced
 * into tiled mode. If the window is made floating again then the old dimensions
 * will be restored.
 * https://dwm.suckless.org/patches/save_floats/
 */
#define SAVEFLOATS_PATCH 1

/* The scratchpad patch allows you to spawn or restore floating terminal windows.
 * It is typically useful when one need to do some short typing.
 *
 * Note that this patch changes TAGMASK to make room for special scratchpad tags,
 * so ~0 does more than select all tags with this patch. Code that relies on ~0 to
 * represent all tags should use ~SPTAGMASK instead.
 *
 * Upgraded to Christian Tenllado's multiple scratchpad version.
 * https://lists.suckless.org/hackers/2004/17205.html
 * https://dwm.suckless.org/patches/scratchpads/
 */
#define SCRATCHPADS_PATCH 0

/* Minor alteration of the above allowing clients to keep their size and position when shown */
#define SCRATCHPADS_KEEP_POSITION_AND_SIZE_PATCH 0

/* This alternative patch enables a scratchpad feature in dwm similar to the scratchpad
 * feature in i3wm.
 * https://github.com/GasparVardanyan/dwm-scratchpad
 */
#define SCRATCHPAD_ALT_1_PATCH 1

/* This patch persists some settings across window manager restarts. These include but are not
 * limited to:
 *    - client's assigned tag(s) on which monitor
 *    - the order of clients
 *    - nmaster
 *    - selected layout
 *    - plus various additions depending on what other patches are used
 *
 * The above is not persisted across reboots, however.
 */
#define SEAMLESS_RESTART_PATCH 1

/* As opposed to the original patch this only adds a rule option allowing fake fullscreen
 * to be enabled for applications when they start. This is intended to be used in combination
 * with the fakefullscreenclient patch and offers no practical functionality without it.
 * https://dwm.suckless.org/patches/selectivefakefullscreen/
 */
#define SELECTIVEFAKEFULLSCREEN_PATCH 0


#define SELFRESTART_PATCH 0


#define SENDMON_KEEPFOCUS_PATCH 0

#define SETBORDERPX_PATCH 0

#define SHIFTBOTH_PATCH 0

/* Swaps all the clients on the current tag with all the client on the next/prev tag.
 * Depends on the swaptags patch.
 * https://dwm.suckless.org/patches/shift-tools/
 */
#define SHIFTSWAPTAGS_PATCH 1

/* Moves the current selected client to the adjacent tag.
 * Also see the focusadjacenttag patch.
 * https://dwm.suckless.org/patches/shift-tools/
 */
#define SHIFTTAG_PATCH 1

#define SHIFTTAGCLIENTS_PATCH 0

/* This patch adds keybindings for left and right circular shift through tags.
 * https://github.com/chau-bao-long/dotfiles/blob/master/suckless/dwm/shiftview.diff
 */
#define SHIFTVIEW_PATCH 1


#define SHIFTVIEW_CLIENTS_PATCH 0


#define SIZEHINTS_PATCH 0

#define SIZEHINTS_RULED_PATCH 0

#define SIZEHINTS_ISFREESIZE_PATCH 0


#define SORTSCREENS_PATCH 0


#define SPAWNCMD_PATCH 0

#define STACKER_PATCH 0

#define STEAM_PATCH 0


#define STICKY_PATCH 0

#define SWALLOW_PATCH 0


#define SWAPFOCUS_PATCH 0

#define SWAPTAGS_PATCH 0

#define SWITCHCOL_PATCH 0


#define SWITCHTAG_PATCH 0


#define TAB_PATCH 0


#define TAGALL_PATCH 0


#define TAGALLMON_PATCH 0


#define TAGINTOSTACK_ALLMASTER_PATCH 0


#define TAGINTOSTACK_ONEMASTER_PATCH 0


#define TAGMONFIXFS_PATCH 0


#define TAGOTHERMONITOR_PATCH 0


#define TAGSWAPMON_PATCH 0


#define TAGSYNC_PATCH 0

#define TAPRESIZE_PATCH 0

/* This patch allows you to toggle fullscreen on and off using a single shortcut key.
 * https://github.com/bakkeby/patches/blob/master/dwm/dwm-togglefullscreen-6.2.diff
 */
#define TOGGLEFULLSCREEN_PATCH 1



#define TOGGLELAYOUT_PATCH 0

#define TOGGLETAG_PATCH 0


#define TRANSFER_PATCH 0

#define TRANSFER_ALL_PATCH 0


#define UNFLOATVISIBLE_PATCH 0

/* This patch adds configurable gaps between windows differentiating between outer, inner,
 * horizontal and vertical gaps.
 * https://github.com/bakkeby/patches/blob/master/dwm/dwm-vanitygaps-6.2.diff
 * https://github.com/bakkeby/patches/blob/master/dwm/dwm-cfacts-vanitygaps-6.2.diff
 */
#define VANITYGAPS_PATCH 1

/* This patch adds outer gaps for the monocle layout.
 * Most gaps patches tries to avoid gaps on the monocle layout, as it is often used as a
 * fullscreen mode, hence this is enabled separately from the main vanitygaps patch.
 */
#define VANITYGAPS_MONOCLE_PATCH 0


#define VIEW_HISTORY_PATCH 0

/* Follow a w0ndow to the tag it is being moved to.
 * https://dwm.suckless.org/patches/viewontag/
 */
#define VIEWONTAG_PATCH 1

/* This patch warps the mouse cursor to the center of the currently focused window or screen
 * when the mouse cursor is (a) on a different screen or (b) on top of a different window.
 * https://dwm.suckless.org/patches/warp/
 */
#define WARP_PATCH 1

#define WINDOWROLERULE_PATCH 0

#define WINVIEW_PATCH 0


#define XKB_PATCH 0

#define XRDB_PATCH 0


#define ZOOMFLOATING_PATCH 0

#define ZOOMSWAP_PATCH 0

#define BSTACK_LAYOUT 1


#define BSTACKHORIZ_LAYOUT 0

/* Centered master layout.
 * https://dwm.suckless.org/patches/centeredmaster/
 */
#define CENTEREDMASTER_LAYOUT 1

/* Centered floating master layout.
 * https://dwm.suckless.org/patches/centeredmaster/
 */
#define CENTEREDFLOATINGMASTER_LAYOUT 0

/* Same as the default tile layout except clients in the master area are arranged in
 * columns (i.e. left to right).
 * https://dwm.suckless.org/patches/columns/
 */
#define COLUMNS_LAYOUT 1

/* Deck layout.
 * https://dwm.suckless.org/patches/deck/
 */
#define DECK_LAYOUT 1

/* Fibonacci dwindle layout.
 * https://dwm.suckless.org/patches/fibonacci/
 */
#define FIBONACCI_DWINDLE_LAYOUT 1

/* Fibonacci spiral layout.
 * https://dwm.suckless.org/patches/fibonacci/
 */
#define FIBONACCI_SPIRAL_LAYOUT 0

/* Flextile deluxe layout.
 * A revamped, more flexible, and over-the-top version of the original flextile layout.
 * https://dwm.suckless.org/patches/flextile/ (original)
 */
#define FLEXTILE_DELUXE_LAYOUT 0

/* Gappless grid layout.
 * https://dwm.suckless.org/patches/gaplessgrid/
 */
#define GAPPLESSGRID_LAYOUT 1

/* Gridmode (grid) layout.
 * https://dwm.suckless.org/patches/gridmode/
 */
#define GRIDMODE_LAYOUT 0

/* Horizontal grid (horizgrid) layout.
 * https://dwm.suckless.org/patches/horizgrid/
 */
#define HORIZGRID_LAYOUT 1

/* Grid layout where nmaster controls the number of rows.
 * https://dwm.suckless.org/patches/nrowgrid/
 */
#define NROWGRID_LAYOUT 0

/* The default tile layout.
 * This can be optionally disabled in favour of other layouts.
 */
#define TILE_LAYOUT 1

/* Monocle layout (default).
 * This can be optionally disabled in favour of other layouts.
 */
#define MONOCLE_LAYOUT 1
