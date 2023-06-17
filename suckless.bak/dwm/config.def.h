/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx        = 4;   
static const unsigned int snap            = 32; 
static const int scalepreview             = 4;   
static const unsigned int gappih          = 12;  
static const unsigned int gappiv          = 12;  
static const unsigned int gappoh          = 12;  
static const unsigned int gappov          = 12;  
static const int smartgaps_fact           = 1;   
static const int showbar                  = 1;   
static const int topbar                   = 0;   
static const int bar_height               = 27;   
static const int vertpad                  = 5;  
static const int sidepad                  = 10;

#define ICONSIZE 20    
#define ICONSPACING 5  

static const int statusmon                = -1;
static const int horizpadbar              = 10;   
static const int vertpadbar               = 10;   
static const char buttonbar[]             = " ";
static const unsigned int systrayspacing  = 2;   
static const int showsystray              = 0;   
static const unsigned int ulinepad        = 5;         
static const unsigned int ulinestroke     = 2;     
static const unsigned int ulinevoffset    = 0;     
static const int ulineall                 = 0;


/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "Jetbrainsmono nerd font:size=11" };
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#D9E0EE";
static char normbgcolor[]                = "#1E1D2D";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#E0B0FF";
static char selbordercolor[]             = "#E0B0FF";
static char selfloatcolor[]              = "#E0B0FF";

static char titlenormfgcolor[]           = "#D9E0EE";
static char titlenormbgcolor[]           = "#E0B0FF";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#1E1D2D";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]   = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]   = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]    = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]       = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]      = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]       = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm] = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]  = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]  = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]   = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]   = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]    = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]       = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};

static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "", "", "", "", "", "", "", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>" },
};

static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
};

static const MonitorRule monrules[] = {
	/* monitor  tag   layout  mfact  nmaster  showbar  topbar */
	{  0,       -1,   0,      -1,    -1,      -1,      -1     }, 
	{  1,       -1,   1,      -1,    -1,      -1,      -1     },
	{  2,       -1,   1,      -1,    -1,      -1,      -1     },
};


static const BarRule barrules[] = {
	/* monitor   bar  alignment         widthfunc         drawfunc        clickfunc         hoverfunc     name */
	{ -1,        0,   BAR_ALIGN_LEFT,   width_stbutton,   draw_stbutton,  click_stbutton,   NULL,         "statusbutton" },
	{ -1,        0,   BAR_ALIGN_LEFT,   width_tags,       draw_tags,      click_tags,       hover_tags,   "tags" },
	{  0,        0,   BAR_ALIGN_RIGHT,  width_systray,    draw_systray,   click_systray,    NULL,         "systray" },
	{ -1,        0,   BAR_ALIGN_LEFT,   width_ltsymbol,   draw_ltsymbol,  click_ltsymbol,   NULL,         "layout" },
	{ statusmon, 0,   BAR_ALIGN_RIGHT,  width_status2d,   draw_status2d,  click_statuscmd,  NULL,         "status2d" },
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
	{ "(@)",      spiral },
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define CTRL ControlMask
#define SHIFT ShiftMask

#define TAGKEYS(KEY,TAG) \
	{ MOD,            KEY,  view,         {.ui = 1 << TAG} }, \
	{ MOD|CTRL,       KEY,  toggleview,   {.ui = 1 << TAG} }, \
	{ MOD|SHIFT,      KEY,  tag,          {.ui = 1 << TAG} }, \
	{ MOD|CTRL|SHIFT, KEY,  toggletag,    {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};

/* commands */
static const char *btncmd[]   = {"rofi", "-show", "drun", NULL};

static const StatusCmd statuscmds[] = {
  { "eww -c ~/.config/eww open-many --toggle powermenu", 1 },
  { "~/.local/bin/statusbar/wifi", 2  },
  { "eww -c ~/.config/eww open --toggle date", 3  },
  { "~/.local/bin/statusbar/battery", 4 },
  { "~/.local/bin/statusbar/sound", 5 },
  { "~/.local/bin/statusbar/mindash", 6 },
  { "~/.local/bin/statusbar/mincalendar", 7 },
  { "~/.local/bin/statusbar/notifications", 8 },
};

static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

static const Key keys[] = {
	/* modifier                     key            function                argument */
  { MOD|SHIFT,      XK_Return,    spawn,                {.v = spcmd1 } },
  // DWM Session	-----------
  { MOD|CTRL, 		  XK_q, 				quit,                 {0} }, 
  { MOD|SHIFT, 		  XK_r, 				quit,                 {1} }, 

  // Window Management -----------
	/* Murder */
  { MOD, 					  XK_q, 				killclient,           {0} }, 
  { MOD, 					  XK_Escape, 		spawn,                SHCMD("xkill") },

  /* Switch */
  { MOD, 					  XK_Left, 			focusstack,           {.i = +1 } }, 
  { MOD, 					  XK_Right, 		focusstack,           {.i = -1 } },
  { MOD|SHIFT, 		  XK_Left, 			movestack,            {.i = +1 } }, 
  { MOD|SHIFT, 		  XK_Right, 		movestack,            {.i = -1 } },

  { MOD, 					  XK_i, 				incnmaster,           {.i = +1 } }, 
  { MOD, 					  XK_u, 				incnmaster,           {.i = -1 } },

	/* Resize */
  { MOD|CTRL, 		  XK_Left, 			setmfact,             {.f = -0.05} }, 
  { MOD|CTRL, 		  XK_Right, 		setmfact,             {.f = +0.05} }, 
	{ MOD|SHIFT,      XK_h,         setcfact,             {.f = +0.25} },
	{ MOD|SHIFT,      XK_l,         setcfact,             {.f = -0.25} },
	{ MOD|SHIFT,      XK_o,         setcfact,             {0} },

  /* focus dir */
  { ALT,            XK_Left,      focusdir,             {.i = 0 } }, 
	{ ALT,            XK_Right,     focusdir,             {.i = 1 } }, 
	{ ALT,            XK_Up,        focusdir,             {.i = 2 } }, 
	{ ALT,            XK_Down,      focusdir,             {.i = 3 } },

  /* moveplace */
	{ MOD,            XK_KP_7,      moveplace,            {.ui = WIN_NW }},   
	{ MOD,            XK_KP_8,      moveplace,            {.ui = WIN_N  }},   
	{ MOD,            XK_KP_9,      moveplace,            {.ui = WIN_NE }},   
	{ MOD,            XK_KP_4,      moveplace,            {.ui = WIN_W  }},   
	{ MOD,            XK_KP_5,      moveplace,            {.ui = WIN_C  }},   
	{ MOD,            XK_KP_6,      moveplace,            {.ui = WIN_E  }},   
	{ MOD,            XK_KP_1,      moveplace,            {.ui = WIN_SW }},   
	{ MOD,            XK_KP_2,      moveplace,            {.ui = WIN_S  }},   
	{ MOD,            XK_KP_3,      moveplace,            {.ui = WIN_SE }},

	/* Misc */
  { MOD, 					  XK_b, 				togglebar,            {0} }, 
  { MOD, 					  XK_Tab, 			zoom,                 {0} }, 
  { ALT, 					  XK_Tab, 		  view,                 {0} },

  // Layouts  --------
  { MOD,            XK_t,         setlayout,            {.v = &layouts[0]} },
	{ MOD,            XK_f,         setlayout,            {.v = &layouts[1]} },
	{ MOD,            XK_m,         setlayout,            {.v = &layouts[2]} },
	{ MOD,            XK_space,     setlayout,            {0} },
	{ MOD|SHIFT,      XK_space,     togglefloating,       {0} },
	{ MOD,            XK_y,         togglefullscreen,     {0} },
  { MOD,            XK_comma,     focusmon,             {.i = -1 } },
	{ MOD,            XK_period,    focusmon,             {.i = +1 } },
	{ MOD|SHIFT,      XK_comma,     tagmon,               {.i = -1 } },
	{ MOD|SHIFT,      XK_period,    tagmon,               {.i = +1 } },
	{ MOD|SHIFT,      XK_f,         fullscreen,           {0} },

  // Scratchpads --------
	{ MOD,            XK_minus,     scratchpad_show,      {0} },
	{ MOD|SHIFT,      XK_minus,     scratchpad_hide,      {0} },
	{ MOD,            XK_equal,     scratchpad_remove,    {0} },
  { MOD|SHIFT,      XK_grave,     togglescratch,        {.ui = 0 } },
	{ MOD|CTRL,       XK_grave,     setscratch,           {.ui = 0 } },
	{ MOD|SHIFT,      XK_grave,     removescratch,        {.ui = 0 } },
  
  // Managing Tags -------
  { MOD|ALT,        XK_d,         distributetags,         {0} },
	{ MOD|ALT,        XK_Left,      viewtoleft,             {0} }, 
	{ MOD|ALT,        XK_Right,     viewtoright,            {0} }, 
	{ MOD|ALT|SHIFT,  XK_Left,      tagtoleft,              {0} }, 
	{ MOD|ALT|SHIFT,  XK_Right,     tagtoright,             {0} }, 
	{ MOD|ALT|CTRL,   XK_Left,      tagandviewtoleft,       {0} },
	{ MOD|ALT|CTRL,   XK_Right,     tagandviewtoright,      {0} },

	TAGKEYS(                        XK_1,                 0)
	TAGKEYS(                        XK_2,                 1)
	TAGKEYS(                        XK_3,                 2)
	TAGKEYS(                        XK_4,                 3)
	TAGKEYS(                        XK_5,                 4)
	TAGKEYS(                        XK_6,                 5)
	TAGKEYS(                        XK_7,                 6)
	TAGKEYS(                        XK_8,                 7)
	TAGKEYS(                        XK_9,                 8)
};

/* button definitions */
static const Button buttons[] = {
	/* click            event mask    button          function        argument */
	{ ClkButton,        0,            Button1,        spawn,          {.v = btncmd } },
	{ ClkLtSymbol,      0,            Button1,        setlayout,      {0} },
	{ ClkLtSymbol,      0,            Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,      0,            Button2,        zoom,           {0} },
	{ ClkStatusText,    0,            Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,    0,            Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,    0,            Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,     MOD,          Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,     MOD,          Button2,        togglefloating, {0} },
	{ ClkClientWin,     MOD,          Button3,        resizemouse,    {0} },
	{ ClkClientWin,     MOD|SHIFT,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,     MOD|SHIFT,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,        0,            Button1,        view,           {0} },
	{ ClkTagBar,        0,            Button3,        toggleview,     {0} },
	{ ClkTagBar,        MOD,          Button1,        tag,            {0} },
	{ ClkTagBar,        MOD,          Button3,        toggletag,      {0} },
};


