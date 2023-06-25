/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 4;        
static const unsigned int default_border = 0;   
static const unsigned int snap      = 32;       
static const unsigned int gappih    = 12;       
static const unsigned int gappiv    = 12;       
static const unsigned int gappoh    = 12;       
static const unsigned int gappov    = 12;       
static const int smartgaps          = 0;        
static const unsigned int systraypinning = 0;   
static const unsigned int systrayspacing = 2;   
static const int systraypinningfailfirst = 1;   
static const int showsystray        = 1;        
static const int showbar            = 1;        
static const int showtab            = showtab_auto;
static const int toptab             = 1;        
static const int floatbar           = 1;
static const int topbar             = 0;        
static const int horizpadbar        = 10;
static const int vertpadbar         = 10;
static const int vertpadtab         = 34;
static const int horizpadtabi       = 10;
static const int horizpadtabo       = 10;
static const int scalepreview       = 4;
static const int tag_preview        = 1;        
static const int colorfultag        = 1;        

static const int new_window_attach_on_end = 1; 
#define ICONSIZE 19   /* icon size */
#define ICONSPACING 8 /* space between icon and title */

static const char *fonts[]          = {
  "JetBrainsMono Nerd Font:style:medium:size=11" 
};

// theme
#include "themes/catppuccin.h"

static const char *colors[][3]      = {
 /*                     fg       bg      border */
  [SchemeNorm]       = { gray3,   black,  gray2 },
  [SchemeSel]        = { gray4,   blue,   blue  },
  [SchemeTitle]      = { white,   black,  black  }, 
  [TabSel]           = { blue,    gray2,  black },
  [TabNorm]          = { gray3,   black,  black },
  [SchemeTag]        = { gray3,   black,  black },
  [SchemeTag1]       = { blue,    black,  black },
  [SchemeTag2]       = { red,     black,  black },
  [SchemeTag3]       = { orange,  black,  black },
  [SchemeTag4]       = { green,   black,  black },
  [SchemeTag5]       = { pink,    black,  black },
  [SchemeLayout]     = { green,   black,  black },
  [SchemeBtnPrev]    = { green,   black,  black },
  [SchemeBtnNext]    = { yellow,  black,  black },
  [SchemeBtnClose]   = { red,     black,  black },
};

/* tagging */
static char *tags[] = {"", "", "", "", ""};

static const char* dwmmenu[] = { "dwmmenu", NULL };

static const Launcher launchers[] = {
  /* command     name to display */
  { dwmmenu,         "󰣨" },
};

static const int tagschemes[] = {
  SchemeTag1, 
  SchemeTag2, 
  SchemeTag3, 
  SchemeTag4, 
  SchemeTag5
};

static const unsigned int ulinepad      = 5; 
static const unsigned int ulinestroke   = 2; 
static const unsigned int ulinevoffset  = 0; 
static const int ulineall               = 0; 

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance  title    tags mask   iscentered   isfloating   monitor */
    { "Gimp",     NULL,     NULL,    0,          0,           1,           -1 },
    { "Firefox",  NULL,     NULL,    1 << 8,     0,           0,           -1 },
    { "eww",      NULL,     NULL,    0,          0,           1,           -1 },
};

/* layout(s) */
static const float mfact        = 0.40; 
static const int nmaster        = 1;    
static const int resizehints    = 0;    
static const int lockfullscreen = 1; 

#define FORCE_VSPLIT 1  
#include "functions.h"


static const Layout layouts[] = {
  /* symbol   arrange function */
  { "|M|",    centeredmaster },
  { "[]=",    tile },    
  { "[M]",    monocle },
  { "[@]",    spiral },
  { "[\\]",   dwindle },
  { "H[]",    deck },
  { "TTT",    bstack },
  { "===",    bstackhoriz },
  { "HHH",    grid },
  { "###",    nrowgrid },
  { "---",    horizgrid },
  { ":::",    gaplessgrid },
  { ">M>",    centeredfloatingmaster },
  { "><>",    NULL },    
  { NULL,     NULL },
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define CTRL ControlMask
#define SHIFT ShiftMask

#define TAGKEYS(KEY,TAG) \
  { MOD,            KEY,   view,        {.ui = 1 << TAG} }, \
  { MOD|CTRL,       KEY,   toggleview,  {.ui = 1 << TAG} }, \
  { MOD|SHIFT,      KEY,   tag,         {.ui = 1 << TAG} }, \
  { MOD|CTRL|SHIFT, KEY,   toggletag,   {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */

static const Key keys[] = {
    /* modifier                         key         function        argument */
    // layout
    //{ MODKEY|ControlMask,               XK_comma,   cyclelayout,    {.i = -1 } },
    //{ MODKEY|ControlMask,               XK_period,  cyclelayout,    {.i = +1 } },
    //{ MODKEY,                           XK_0,       view,           {.ui = ~0 } },
    //{ MODKEY|ShiftMask,                 XK_0,       tag,            {.ui = ~0 } },

    TAGKEYS(                            XK_1,                       0)
    TAGKEYS(                            XK_2,                       1)
    TAGKEYS(                            XK_3,                       2)
    TAGKEYS(                            XK_4,                       3)
    TAGKEYS(                            XK_5,                       4)
    TAGKEYS(                            XK_6,                       5)
    TAGKEYS(                            XK_7,                       6)
    TAGKEYS(                            XK_8,                       7)
    TAGKEYS(                            XK_9,                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click            event    button      function        argument */
  { ClkLtSymbol,      0,       Button1,    setlayout,      {0} },
  { ClkLtSymbol,      0,       Button3,    setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,      0,       Button2,    zoom,           {0} },
  { ClkStatusText,    0,       Button2,    spawn,          SHCMD("st") },
  { ClkClientWin,     MOD,     Button1,    moveorplace,    {.i = 0} },
  { ClkClientWin,     MOD,     Button2,    togglefloating, {0} },
  { ClkClientWin,     MOD,     Button3,    resizemouse,    {0} },
  { ClkClientWin,     CTRL,    Button1,    dragmfact,      {0} },
  { ClkClientWin,     CTRL,    Button3,    dragcfact,      {0} },
  { ClkTagBar,        0,       Button1,    view,           {0} },
  { ClkTagBar,        0,       Button3,    toggleview,     {0} },
  { ClkTagBar,        MOD,     Button1,    tag,            {0} },
  { ClkTagBar,        MOD,     Button3,    toggletag,      {0} },
  { ClkTabBar,        0,       Button1,    focuswin,       {0} },
  { ClkTabBar,        0,       Button1,    focuswin,       {0} },
  { ClkTabPrev,       0,       Button1,    movestack,      { .i = -1 } },
  { ClkTabNext,       0,       Button1,    movestack,      { .i = +1 } },
  { ClkTabClose,      0,       Button1,    killclient,     {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
  { "movestack",      movestack },
  { "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
  { "hidewin",        hidewin },
  { "restorewin",     restorewin },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
