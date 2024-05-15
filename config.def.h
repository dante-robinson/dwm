/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int default_border = 0;   /* to switch back to default border after dynamic border resizing via keybinds */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 12;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 12;       /* vert inner gap between windows */
static const unsigned int gappoh    = 12;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 12;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int toptab             = 1;        /* 0 means bottom tab */
static const int user_bh            = 40;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int sidepad            = 12;       /* horizontal padding of bar */
static const int vertpad            = 12;      	/* vertical padding of bar */
static const int vertpadtab         = 35;
static const int horizpadtabi       = 15;
static const int horizpadtabo       = 15;
static const int scalepreview       = 4;
static const int tag_preview        = 0;        /* 1 means enable, 0 is off */
static const int new_window_attach_on_end = 0;  /*  1 means the new window will attach on the end; 0 means the new window will attach on the front,default is front */
#define ICONSIZE 7   /* icon size */
#define ICONSPACING 1 /* space between icon and title */

static const char *fonts[]          = {"Fira Mono Nerd Font:style:size=8"};
static const char dmenufont[]       = "Fira Mono Nerd Font:size=9";

static const char black[]       = "#1a1b26";
static const char white[]       = "#a9b1d6";
static const char gray2[]       = "#24283b"; // unfocused window border
static const char gray3[]       = "#414868";
static const char gray4[]       = "#565f89";
static const char blue[]        = "#7aa2f7";  // focused window border
static const char green[]       = "#9ece6a";
static const char red[]         = "#f7768e";
static const char orange[]      = "#ff9e64";
static const char yellow[]      = "#e0af68";
static const char pink[]        = "#bb9af7";
static const char col_borderbar[]  = "#1a1b26"; // inner borderpx

static char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const char *colors[][3]      = {
    /*                     fg       bg      border */
    [SchemeNorm]       = { gray3,   black,  gray2 },
    [SchemeSel]        = { gray4,   blue,   blue  },
};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
     /* class      instance    title       tags mask     isfloating   monitor */
     { "Gimp",     NULL,       NULL,       0,            1,           -1 },
     { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */

#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
		{ "[]=",      tile },    /* first entry is default */
    { "[M]",      monocle },
    { "[@]",      spiral },
    { "[\\]",     dwindle },
    { "H[]",      deck },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "HHH",      grid },
    { "###",      nrowgrid },
    { "---",      horizgrid },
    { ":::",      gaplessgrid },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "><>",      NULL },    /* no layout function means floating behavior */
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", gray3, "-nf", gray4, "-sb", blue, "-sf", gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
    /* modifier                         key         function        argument */
		
		// Launch dmenu
    { MODKEY,                           XK_w,       spawn,          {.v = dmenucmd } },
		// Launch st
    { MODKEY,                           XK_Return,  spawn,          {.v = termcmd } },

		// Adjust Audio in OpenBSD (Needs changed for other OSes)
    { MODKEY,                           XK_a,       spawn,          SHCMD("sndioctl output.level=-0.05") },
    { MODKEY,                           XK_s,       spawn,          SHCMD("sndioctl output.level=+0.05") },
    { MODKEY,                           XK_d,       spawn,          SHCMD("sndioctl output.mute=-1") },

		// Fullscreen Screenshots
    { MODKEY,                           XK_p,       spawn,          SHCMD("scrot '/home/user/Pictures/%Y-%m-%d-%H-%M.png'") },

		// Selection Screenshots
    { MODKEY|ShiftMask,                 XK_p,       spawn,          SHCMD("scrot -s '/home/user/Pictures/%Y-%m-%d-%H-%M.png'") },

    // Make window float
    { MODKEY|ShiftMask,                 XK_space,   togglefloating, {0} },

		// Change between focused window
    { MODKEY,                           XK_j,       focusstack,     {.i = +1 } },
    { MODKEY,                           XK_k,       focusstack,     {.i = -1 } },

		// Move window positions
		{ MODKEY|ShiftMask,             		XK_j,      	movestack,      {.i = +1 } },
  	{ MODKEY|ShiftMask,             		XK_k,      	movestack,      {.i = -1 } },
    
		// Change between vertical and horizontal stacked windows
		{ MODKEY,                           XK_i,       incnmaster,     {.i = +1 } },
		{ MODKEY|ShiftMask,									XK_i,				incnmaster,			{.i = -1 } },

    // Change window sizes (in horizontal length) in vertical stack
    { MODKEY,                           XK_h,       setmfact,       {.f = -0.05} },
    { MODKEY,                           XK_l,       setmfact,       {.f = +0.05} },
		{ MODKEY,														XK_o,				setmfact,				{.f =  0.00} },	

		// Change window sizes (in vertical length) in horizontal stack
    { MODKEY|ShiftMask,                 XK_h,       setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,                 XK_l,       setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,                 XK_o,       setcfact,       {.f =  0.00} },

    // Change Layouts
    { MODKEY,						               	XK_z,       setlayout,      {.v = &layouts[0]} },
    { MODKEY,						               	XK_x,       setlayout,      {.v = &layouts[1]} },
    { MODKEY,														XK_e,				setlayout,			{.v = &layouts[2]} },
    { MODKEY|ShiftMask,	               	XK_e,       setlayout,      {.v = &layouts[3]} },
		{ MODKEY,														XK_v,				setlayout,			{.v = &layouts[4]} },
    { MODKEY,						               	XK_b,       setlayout,      {.v = &layouts[5]} },
    { MODKEY|ShiftMask,	     						XK_b,       setlayout,      {.v = &layouts[6]} },
		{ MODKEY,														XK_n,				setlayout,			{.v = &layouts[7]} },
		{ MODKEY|ShiftMask,									XK_n,				setlayout,			{.v = &layouts[8]} },
		{ MODKEY,														XK_m,				setlayout,			{.v = &layouts[9]} },
		{ MODKEY|ShiftMask,									XK_m,				setlayout,			{.v = &layouts[10]} },
    { MODKEY,						               	XK_c,       setlayout,      {.v = &layouts[11]} },
		{ MODKEY|ShiftMask,                	XK_c,	      setlayout,      {.v = &layouts[12]} },

    // Switches between last layout used
		{ MODKEY,                           XK_space,   setlayout,      {0} },
		
		// View all open apps across all workspaces
    { MODKEY,                           XK_0,       view,           {.ui = ~0 } },

    { MODKEY|ShiftMask,                 XK_0,       tag,            {.ui = ~0 } },
    { MODKEY,                           XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,                           XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,                 XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,                 XK_period,  tagmon,         {.i = +1 } },

    // kill dwm
		{ MODKEY|ShiftMask,             		XK_q,      	quit,           {0} },
    // CLose window
    { MODKEY,                           XK_q,       killclient,     {0} },

    // Restart DWM
    { MODKEY|ShiftMask,                 XK_r,       restart,        {0} },
		
		// Change Windows
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
  /* click                event mask      button          function        argument */
 	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
 	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
 	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
 	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
 	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
 	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
 	{ ClkTagBar,            0,              Button1,        view,           {0} },
 	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
 	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
 	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
