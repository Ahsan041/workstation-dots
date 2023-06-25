/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;   
static const int corner_radius      = 12;
static const unsigned int snap      = 32;  
static const int scalepreview       = 4;
static const int smartgaps_fact     = 0;
static const unsigned int gappih    = 12;  
static const unsigned int gappiv    = 12;  
static const unsigned int gappoh    = 12;  
static const unsigned int gappov    = 12;
static const int showbar            = 1;   
static const int topbar             = 1;
static const int floatbar           = 1;
static const int bar_height         = 0;    
static const int statusmon          = -1;
static const int horizpadbar        = 5;
static const int vertpadbar         = 11;
static const int vertpadtab         = 35;
static const int horizpadtabi       = 15;
static const int horizpadtabo       = 15;   
static const char buttonbar[]       = "󰣨";

#define ICONSIZE 20    
#define ICONSPACING 8  

static const int new_window_attach_on_end = 1;
static const unsigned int systraypinning 	= 0;
static const unsigned int systrayspacing  = 5;   
static const int showsystray              = 1;   
static const unsigned int ulinepad        = 5;         
static const unsigned int ulinestroke     = 2;     
static const unsigned int ulinevoffset    = 0;     
static const int ulineall                 = 0;                  


/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_NONE;
static const char *fonts[]               = { "JetBrainsMono Nerd Font:size=11" };
static const char dmenufont[]            = "monospace:size=10";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

#include "theme.h"

static const char *colors[][3] = {
	/*                       fg     bg      border  */              
	[SchemeNorm]      = { gray3,   black,   gray2 },
	[SchemeSel]       = { gray4,   blue,    blue  },
	[SchemeTitleNorm] = { white,   black,   black },
	[SchemeTitleSel]  = { gray4,   blue,    blue  },
	[SchemeTagsNorm]  = { red,     black,   black },
	[SchemeTagsSel]   = { orange,  black,   black },
	[SchemeHidNorm]   = { green,   black,   black },
	[SchemeHidSel]    = { yellow,  black,   black },
	[SchemeUrg]       = { gray4,   blue,    blue  },
};


const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};


static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

static const Rule rules[] = {
  /* class      instance    title       tags mask     iscentered   isfloating   monitor */
  { "Gimp",     NULL,       NULL,       0,            0,           1,           -1 },
  { "Firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },
  { "eww",      NULL,       NULL,       0,            0,           1,           -1 },
  { "spterm",   NULL,       NULL,       0,            0,           1,           -1 },
};


static const MonitorRule monrules[] = {
	/* monitor  layout  mfact  nmaster  showbar  topbar */
	{  0,       0,      -1,    -1,      -1,      -1     }, 
	{  1,       1,      -1,    -1,      -1,      -1     }, 
  {  2,       1,      -1,    -1,      -1,      -1     },
};


static const BarRule barrules[] = {
	/* monitor   bar  alignment         widthfunc         drawfunc         clickfunc         hoverfunc     name */
	{  0,        0,   BAR_ALIGN_LEFT,   width_stbutton,   draw_stbutton,   click_stbutton,   NULL,         "statusbutton" },
	{ -1,        0,   BAR_ALIGN_LEFT,   width_tags,       draw_tags,       click_tags,       hover_tags,   "tags" },
	{  0,        0,   BAR_ALIGN_RIGHT,  width_systray,    draw_systray,    click_systray,    NULL,         "systray" },
	{ -1,        0,   BAR_ALIGN_LEFT,   width_ltsymbol,   draw_ltsymbol,   click_ltsymbol,   NULL,         "layout" },
	{ statusmon, 0,   BAR_ALIGN_RIGHT,  width_status2d,   draw_status2d,   click_statuscmd,  NULL,         "status2d" },
};

/* layout(s) */
static const float mfact        = 0.40; 
static const int nmaster        = 1;    
static const int resizehints    = 0;    
static const int lockfullscreen = 1; 


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "|M|",      centeredmaster },
  { "[]=",      tile },    
	{ "><>",      NULL },    
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "|||",      col },
	{ "[D]",      deck },
	{ "[\\]",     dwindle },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define CTRL ControlMask
#define SHIFT ShiftMask

#define TAGKEYS(KEY,TAG) \
	{ MOD,            KEY,  view,        {.ui = 1 << TAG} }, \
	{ MOD|CTRL,       KEY,  toggleview,  {.ui = 1 << TAG} }, \
	{ MOD|SHIFT,      KEY,  tag,         {.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT, KEY,  toggletag,   {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *btncmd[]  = { "dwmmenu", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static const StatusCmd statuscmds[] = {
	{ "notify-send Volume$BUTTON", 1 },
	{ "notify-send CPU$BUTTON", 2 },
	{ "notify-send Battery$BUTTON", 3 },
};
/* test the above with: xsetroot -name "$(printf '\x01Volume |\x02 CPU |\x03 Battery')" */
static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };


static const Key keys[] = {
	/* modifier                     key            function                argument */

  { MOD,						            XK_o, 	       hidewin, 	   {0}},
  { MOD|SHIFT, 			      XK_o, 	       restorewin, 	   {0}},
  { MOD, 						          XK_w, 	       hideotherwins,  {0}},
  { MOD|SHIFT, 			      XK_w, 	       restoreotherwins, {0}},
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = btncmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,                   Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         MOD,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MOD,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MOD|SHIFT,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MOD|SHIFT,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MOD,              Button1,        tag,            {0} },
	{ ClkTagBar,            MOD,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static const Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "rotatestack",             rotatestack },
	{ "pushdown",                pushdown },
	{ "pushup",                  pushup },
	{ "setcfact",                setcfact },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "shifttag",                shifttag },
	{ "shiftview",               shiftview },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglefullscreen",        togglefullscreen },
	{ "togglescratch",           togglescratch },
	{ "killclient",              killclient },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};

