/*
 * Calavera wm !! - minimalist stacking window manager for X.
 * See LICENSE file for copyright and license details.
 */

#ifndef CONFIG_H
#define CONFIG_H

#define UNFOCUS "black"     
#define FOCUS   "SandyBrown" 
#define PADDING_TOP      0  /* gap at top of screen */
#define MOVESTEP         32 /* pixels to move a window at a time */
#define RESIZESTEP       32 /* Pixels to resize a window at a time.*/
#define SNAP             16 /* monitor edge snap distance */
#define FOLLOW_MOUSE     1  /* Focus the window with the mouse */
#define HIDE_CURSOR      0  /* Pressing a key sends the cursor to the bottom right corner */
#define WAITKEY          1  /* Show the cursor when waiting for a key */

/* X Font cursor theme for command mode
 * see http://tronche.com/gui/x/xlib/appendix/b/
 */
#define CURSOR_WAITKEY XC_icon

/* Number of Workspaces */
#define N_WORKSPACES 10 

#define PREFIX_MODKEY ControlMask  /* modifier prefix */
#define PREFIX_KEYSYM XK_t         /* prefix key */

#define WS_KEY(KEY,WS) \
        { None,                       KEY,      change_workspace,  {.ui = 1 << WS} }, \
	{ ShiftMask,                  KEY,      moveto_workspace,  {.ui = 1 << WS} },

static const char *CMD_TERM[]    = { "urxvt", NULL };
static const char *CMD_BROWSER[] = { "conkeror", NULL };
static const char *CMD_EDITOR[]  = { "emacsclient", "-n", "-c", "-a", "", NULL };
static const char *CMD_LOCK[]    = { "xlock", "-mode", "star", NULL };

/* KEY BINDINGS */
static Key keys[] = {
	/* modifier                   key        function        argument */
        { None,                       XK_a,      launcher,       {0} },
	{ None,                       XK_c,      spawn,          {.v = CMD_TERM } },
        { None,                       XK_e,      spawn,          {.v = CMD_EDITOR } },
	{ None,                       XK_w,      spawn,          {.v = CMD_BROWSER } },
	{ None,                       XK_l,      spawn,          {.v = CMD_LOCK } },
	{ None,                       XK_f,      fullscreen,     {0} },
	{ None,                       XK_m,      maximize,       {0} },
	{ None,                       XK_h,      horizontalmax,  {0} },
        { None,                       XK_v,      verticalmax,    {0} },
	{ None,                       XK_period, center,         {0} },
	{ None,                       XK_n,      focusstack,     {.i = +1 } },
	{ None,                       XK_p,      focusstack,     {.i = -1 } },
	{ None,                       XK_k,      killfocused,    {0} },
	WS_KEY(                        XK_1,                      0)
	WS_KEY(                        XK_2,                      1)
	WS_KEY(                        XK_3,                      2)
	WS_KEY(                        XK_4,                      3)
        WS_KEY(                        XK_5,                      4)
        WS_KEY(                        XK_6,                      5)
        WS_KEY(                        XK_7,                      6)
        WS_KEY(                        XK_8,                      7)
        WS_KEY(                        XK_9,                      8)
        WS_KEY(                        XK_0,                      9)
        { None,                       XK_Down,   moveresize,     {.v = (int []){ 0, MOVESTEP, 0, 0 }}},
        { None,                       XK_Up,     moveresize,     {.v = (int []){ 0, -MOVESTEP, 0, 0 }}},
        { None,                       XK_Right,  moveresize,     {.v = (int []){ MOVESTEP, 0, 0, 0 }}},
        { None,                       XK_Left,   moveresize,     {.v = (int []){ -MOVESTEP, 0, 0, 0 }}},
        { ShiftMask,                  XK_Down,   moveresize,     {.v = (int []){ 0, 0, 0, RESIZESTEP }}},
        { ShiftMask,                  XK_Up,     moveresize,     {.v = (int []){ 0, 0, 0, -RESIZESTEP }}},
        { ShiftMask,                  XK_Right,  moveresize,     {.v = (int []){ 0, 0, RESIZESTEP, 0 }}},
        { ShiftMask,                  XK_Left,   moveresize,     {.v = (int []){ 0, 0, -RESIZESTEP, 0 }}},
        { ShiftMask,                  XK_r,      reload,         {0} }, 
        { ShiftMask,                  XK_q,      quit,           {0} },

    /* Multimedia keys */
    {0, XF86XK_AudioLowerVolume,
        spawn, {.v = (const char*[]){"amixer", "-q", "-c", "0", "set", "Master", "5-", "unmute", NULL}}},
    {0, XF86XK_AudioRaiseVolume,
        spawn, {.v = (const char*[]){"amixer", "-q", "-c", "0", "set", "Master", "5+", "unmute", NULL}}},
    {0, XF86XK_AudioMute,
        spawn, {.v = (const char*[]){"amixer", "-q", "-c", "0", "set", "Master", "toggle", NULL}}},
};

/* BUTTONS*/
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         ControlMask,    Button1,        movemouse,      {0} },
	{ ClkClientWin,         ControlMask,    Button3,        resizemouse,    {0} },
        { ClkClientWin,         ControlMask,    Button2,        killfocused,    {0} },
};

#endif 
