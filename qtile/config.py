"""
██╗███╗░░░███╗██████╗░░█████╗░██████╗░████████╗░██████╗
██║████╗░████║██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔════╝
██║██╔████╔██║██████╔╝██║░░██║██████╔╝░░░██║░░░╚█████╗░
██║██║╚██╔╝██║██╔═══╝░██║░░██║██╔══██╗░░░██║░░░░╚═══██╗
██║██║░╚═╝░██║██║░░░░░╚█████╔╝██║░░██║░░░██║░░░██████╔╝
╚═╝╚═╝░░░░░╚═╝╚═╝░░░░░░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═════╝░
"""

import os
import re
import socket
import subprocess
from libqtile import bar, hook, qtile
from libqtile.layout.bsp import Bsp
from libqtile.layout.xmonad import MonadThreeCol, MonadTall
from libqtile.layout.floating import Floating
from libqtile.layout.max import Max
from libqtile.config import Click, Drag, Group, KeyChord, Key
from libqtile.config import Match, Screen, ScratchPad, DropDown
from libqtile.lazy import lazy
from time import sleep
from typing import List  # noqa: F401
from qtile_extras import widget
from qtile_extras.widget.decorations import BorderDecoration



"""
██╗░░██╗███████╗██╗░░░██╗██████╗░██╗███╗░░██╗██████╗░██╗███╗░░██╗░██████╗░░██████╗
██║░██╔╝██╔════╝╚██╗░██╔╝██╔══██╗██║████╗░██║██╔══██╗██║████╗░██║██╔════╝░██╔════╝
█████═╝░█████╗░░░╚████╔╝░██████╦╝██║██╔██╗██║██║░░██║██║██╔██╗██║██║░░██╗░╚█████╗░
██╔═██╗░██╔══╝░░░░╚██╔╝░░██╔══██╗██║██║╚████║██║░░██║██║██║╚████║██║░░╚██╗░╚═══██╗
██║░╚██╗███████╗░░░██║░░░██████╦╝██║██║░╚███║██████╔╝██║██║░╚███║╚██████╔╝██████╔╝
╚═╝░░╚═╝╚══════╝░░░╚═╝░░░╚═════╝░╚═╝╚═╝░░╚══╝╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░╚═════╝░
"""

mod = "mod4"
alt = "mod1"
ctrl = "control"

keys = [

     '''
     █░░ ▄▀█ █░█ █▄░█ █▀▀ █░█ █ █▄░█ █▀▀   █▀ ▀█▀ █░█ █▀▀ █▀▀
     █▄▄ █▀█ █▄█ █░▀█ █▄▄ █▀█ █ █░▀█ █▄█   ▄█ ░█░ █▄█ █▀░ █▀░
     '''
    # Launch terminal --
    Key([mod], "Return", lazy.spawn("qterm")),
    Key([mod, "shift"], "Return", lazy.spawn("qterm --float")),
    Key([mod], "t", lazy.spawn("qterm --full")),

    # Launch GUI Apps
    Key([mod, "shift"], "f", lazy.spawn("thunar")),
    Key([mod, "shift"], "b", lazy.spawn("firefox")),
    Key([mod, "shift"], "e", lazy.spawn("emacsclient -c -a emacs")),

    # Launch CLI Apps
    Key([mod, "shift"], "r", lazy.spawn("qterm -e ranger")),
    Key([mod, "shift"], "n", lazy.spawn("qterm -e lvim")),
    
    # Launch Application Menu
    Key([mod], "d", lazy.spawn("qmenu")),


    '''
    █▀█ ▀█▀ █ █░░ █▀▀   █▀ █▀▀ █▀ █▀ █ █▀█ █▄░█
    ▀▀█ ░█░ █ █▄▄ ██▄   ▄█ ██▄ ▄█ ▄█ █ █▄█ █░▀█
    '''
    Key([mod, ctrl], "r", 
        lazy.reload_config(),
        lazy.spawn('dunstify -u low' + ' "Configuration Reloaded!"')),

    Key([mod, ctrl], "s", 
        lazy.restart(),
        lazy.spawn('dunstify -u low' + ' "Restarting Qtile..."')),

    Key([mod, ctrl], "r", 
        lazy.shutdown(),
        lazy.spawn('dunstify -u low' + ' "Exiting Qtile..."')),


    '''
    █░█ ▄▀█ █▀█ █▀▄ █░█░█ ▄▀█ █▀█ █▀▀   █▄▀ █▀▀ █▄█ █▀
    █▀█ █▀█ █▀▄ █▄▀ ▀▄▀▄▀ █▀█ █▀▄ ██▄   █░█ ██▄ ░█░ ▄█
    '''
    Key([], "XF86AudioRaiseVolume", lazy.spawn("volume --up")),
    Key([], "XF86AudioLowerVolume", lazy.spawn("volume --down")),
    Key([], "XF86AudioMute", lazy.spawn("volume --toggle")),
    Key([], "Print", lazy.spawm("flameshot gui")),
 
    ''' 
    █░█░█ █ █▄░█ █▀▄ █▀█ █░█░█   █▀▄▀█ ▄▀█ █▄░█ ▄▀█ █▀▀ █▀▀ █▀▄▀█ █▀▀ █▄░█ ▀█▀
    ▀▄▀▄▀ █ █░▀█ █▄▀ █▄█ ▀▄▀▄▀   █░▀░█ █▀█ █░▀█ █▀█ █▄█ ██▄ █░▀░█ ██▄ █░▀█ ░█░
    '''
    # Kill active window
    Key([mod], "q", lazy.window.kill()),
    
    # Window Focus
    Key([mod], "Up", lazy.layout.up()),
    Key([mod], "Down", lazy.layout.down()),
    Key([mod], "Left", lazy.layout.left()),
    Key([mod], "Right", lazy.layout.right()),

    # Shuffle Windows
    Key([mod, "shift"], "Left", lazy.layout.shuffle_left()),
    Key([mod, "shift"], "Right", lazy.layout.shuffle_right()),
    Key([mod, "shift"], "Down", lazy.layout.shuffle_down()),
    Key([mod, "shift"], "Up", lazy.layout.shuffle_up()),

    # Window size
    Key(
        [mod, ctrl], "Right",
        lazy.layout.grow_right(),
        lazy.layout.grow(),
        lazy.layout.increase_ratio(),
        lazy.layout.delete(),
    ),
    Key(
        [mod, ctrl], "Left",
        lazy.layout.grow_left(),
        lazy.layout.shrink(),
        lazy.layout.decrease_ratio(),
        lazy.layout.add(),
    ),
    Key(
        [mod, ctrl], "Up",
        lazy.layout.grow_up(),
        lazy.layout.grow(),
        lazy.layout.decrease_nmaster(),
    ),
    Key(
        [mod, ctrl], "Down",
        lazy.layout.grow_down(),
        lazy.layout.shrink(),
        lazy.layout.increase_nmaster(),
    ),

    '''
    █▄▀ █▀▀ █▄█ █▀▀ █░█ █▀█ █▀█ █▀▄ █▀
    █░█ ██▄ ░█░ █▄▄ █▀█ █▄█ █▀▄ █▄▀ ▄█
    '''
    # Emacs programs launched using the key chord control+e followed by 'key'
    KeyChord(
        [ctrl], "e", [
            Key([], "e", lazy.spawn("emacsclient -c -a 'emacs'")),
            Key([], "b", lazy.spawn("emacsclient -c -a 'emacs' --eval '(ibuffer)'")),
            Key([], "d", lazy.spawn("emacsclient -c -a 'emacs' --eval '(dired nil)'")),
            Key([], "i", lazy.spawn("emacsclient -c -a 'emacs' --eval '(erc)'")),
            Key([], "n", lazy.spawn("emacsclient -c -a 'emacs' --eval '(elfeed)'")),
            Key([], "s", lazy.spawn("emacsclient -c -a 'emacs' --eval '(eshell)'")),
            Key([], "v", lazy.spawn("emacsclient -c -a 'emacs' --eval '(+vterm/here nil)'")),
    ]),


    '''
    █▀▀ █▀█ █▀█ █░█ █▀█ █▀ ░░▄▀ █░░ ▄▀█ █▄█ █▀█ █░█ ▀█▀ █▀
    █▄█ █▀▄ █▄█ █▄█ █▀▀ ▄█ ▄▀░░ █▄▄ █▀█ ░█░ █▄█ █▄█ ░█░ ▄█
    '''
    # Toggle floating and fullscreen
    Key([mod], "space", lazy.window.toggle_floating()),
    Key([mod], "f", lazy.window.toggle_fullscreen()),
   
    # Toggle betweem layouts
    Key([], "Tabs", lazy.next_layout()),  

    # Toggle between adjacent groups
    Key([ctrl, alt], "Right", lazy.screen.next_group()),
    Key([ctrl, alt], "Left", lazy.screen.prev_group()),

    # Move to last visited group
    Key(["shift"], "Tab", lazy.screen.toggle_group()),  

 	# Increase the space for master window
    Key([mod], "equal", lazy.layout.increase_ratio()),

	# Decrease the space for master window
    Key([mod], "minus", lazy.layout.decrease_ratio()),

    # Toggle between split and unsplit sides of stack.
    Key([mod, "shift"], "s", lazy.layout.toggle_split()),   


        
    '''
    █▀▄▀█ █ █▀ █▀▀ █▀▀ █░░ █░░ █▀▀ █▄░█ █▀▀ █▀█ █░█ █▀
    █░▀░█ █ ▄█ █▄▄ ██▄ █▄▄ █▄▄ ██▄ █░▀█ ██▄ █▄█ █▄█ ▄█
    '''
    Key([mod, "control"], "l",
        lazy.spawn("betterlockscreen --lock")),



]




'''
░██████╗░██████╗░░█████╗░██╗░░░██╗██████╗░░██████╗
██╔════╝░██╔══██╗██╔══██╗██║░░░██║██╔══██╗██╔════╝
██║░░██╗░██████╔╝██║░░██║██║░░░██║██████╔╝╚█████╗░
██║░░╚██╗██╔══██╗██║░░██║██║░░░██║██╔═══╝░░╚═══██╗
╚██████╔╝██║░░██║╚█████╔╝╚██████╔╝██║░░░░░██████╔╝
░╚═════╝░╚═╝░░╚═╝░╚════╝░░╚═════╝░╚═╝░░░░░╚═════╝░
'''

group_names = ["1", "2", "3", "4", "5", "6"]
group_labels = ["", "", "󱕜", "", "", "󰿎"]
group_layouts = ["bsp", "bsp", "bsp", "bsp", "bsp", "bsp"]

# Add group names, labels, and default layouts to the groups object.
groups = []
for i in range(len(group_names)):
    groups.append(
        Group(
            name=group_names[i],
            layout=group_layouts[i].lower(),
            label=group_labels[i],
        )
    )

# Add group specific keybindings
for i in groups:
    keys.extend(
        [
            Key(
                [mod], i.name,
                lazy.group[i.name].toscreen(),
                desc="Mod + number to move to that group.",
            ),
            Key(["mod1"], "Tab", lazy.screen.next_group(), desc="Move to next group."),
            Key(
                ["mod1", "shift"],
                "Tab",
                lazy.screen.prev_group(),
                desc="Move to previous group.",
            ),
            Key(
                [mod, "shift"],
                i.name,
                lazy.window.togroup(i.name),
                desc="Move focused window to new group.",
            ),
        ]
    )


layouts = [
    Bsp(),
    MonadTall(),
    MonadThreeCol(),
    Max(),

    # Try more layouts by unleashing below layouts.
    # layout.Stack(num_stacks=2),
    # layout.Bsp(),
    # layout.Matrix(),
    # layout.MonadTall(),
    # layout.MonadWide(),
    # layout.RatioTile(),
    # layout.Tile(),
    # layout.TreeTab(),
    # layout.VerticalTile(),
    # layout.Zoomy(),
]


widget_defaults = dict(
    font="sans",
    fontsize=12,
    padding=3,
)
extension_defaults = widget_defaults.copy()

screens = [
    Screen(
        bottom=bar.Bar(
            [
                widget.CurrentLayout(),
                widget.GroupBox(),
                widget.Prompt(),
                widget.WindowName(),
                widget.Chord(
                    chords_colors={
                        "launch": ("#ff0000", "#ffffff"),
                    },
                    name_transform=lambda name: name.upper(),
                ),
                widget.TextBox("default config", name="default"),
                widget.TextBox("Press &lt;M-r&gt; to spawn", foreground="#d75f5f"),
                # NB Systray is incompatible with Wayland, consider using StatusNotifier instead
                # widget.StatusNotifier(),
                widget.Systray(),
                widget.Clock(format="%Y-%m-%d %a %I:%M %p"),
                widget.QuickExit(),
            ],
            24,
            # border_width=[2, 0, 2, 0],  # Draw top and bottom borders
            # border_color=["ff00ff", "000000", "ff00ff", "000000"]  # Borders are magenta
        ),
    ),
]


# Drag floating layouts.
mouse = [
    Drag(
        [mod],
        "Button1", lazy.window.set_position_floating(),
        start=lazy.window.get_position(),
    ),
    Drag(
        [mod], "Button3", lazy.window.set_size_floating(),
        start=lazy.window.get_size()
    ),
    Click([mod], "Button2", lazy.window.bring_to_front()),
]


@hook.subscribe.startup_once
def autostart():
    autostart = os.path.expanduser("/usr/local/bin/qstart")
    subprocess.run([autostart])


dgroups_key_binder = None
dgroups_app_rules = []  # type: list
follow_mouse_focus = True

bring_front_click = False
cursor_warp = True

floating_layout = Floating(
    border_focus=var_active_color,
    border_normal=var_normal_color,
    border_width=var_border_width,
    float_rules=[
        # Run the utility of `xprop` to see the wm class and name of an X client.
        *layout.Floating.default_float_rules,
        Match(wm_class="alacritty-float|Music"),
        Match(wm_class="Lxappearance|Nitrogen"),
        Match(wm_class="Pavucontrol|Xfce4-power-manager-settings|Nm-connection-editor"),
        Match(wm_class="feh|Viewnior|Gpicview|Gimp|MPlayer|Vlc|Spotify"),
        Match(wm_class="Kvantum Manager|qt5ct"),
        Match(wm_class="VirtualBox Manager|qemu|Qemu-system-x86_64"),
        Match(title="branchdialog"),
    ],
)

auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

auto_minimize = True

# When using the Wayland backend, this can be used to configure input devices.
wl_input_rules = None

wmname = "LG3D"
