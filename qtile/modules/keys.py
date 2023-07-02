from libqtile.lazy import lazy
from libqtile.config import KeyChord, Key

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
     █   ▄▀█ █ █ █▄ █ █▀▀ █ █ █ █▄ █ █▀▀   █▀ ▀█▀ █ █ █▀▀ █▀▀
     █▄▄ █▀█ █▄█ █ ▀█ █▄▄ █▀█ █ █ ▀█ █▄█   ▄█  █  █▄█ █▀  █▀ 
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
    █▀█ ▀█▀ █ █   █▀▀   █▀ █▀▀ █▀ █▀ █ █▀█ █▄ █
    ▀▀█  █  █ █▄▄ ██▄   ▄█ ██▄ ▄█ ▄█ █ █▄█ █ ▀█
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
    █ █ ▄▀█ █▀█ █▀▄ █ █ █ ▄▀█ █▀█ █▀▀   █▄▀ █▀▀ █▄█ █▀
    █▀█ █▀█ █▀▄ █▄▀ ▀▄▀▄▀ █▀█ █▀▄ ██▄   █ █ ██▄  █  ▄█
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

    # Tidygroups
    Key([mod, "shift"], "t", lazy.function(tidygroups)),
    Key([mod, ctrl], "t", lazy.function(tidygroups, follow_focus=False)),

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
    █▀ █▀▀ █▀█ ▄▀█ ▀█▀ █▀▀ █░█ █▀█ ▄▀█ █▀▄ █▀
    ▄█ █▄▄ █▀▄ █▀█ ░█░ █▄▄ █▀█ █▀▀ █▀█ █▄▀ ▄█
    '''

    Key([mod], "n", lazy.group['scratchpad'].dropdown_toggle('term')),
    Key([mod], "c", lazy.group['scratchpad'].dropdown_toggle('ranger')),
    Key([mod], "v", lazy.group['scratchpad'].dropdown_toggle('volume')),
    Key([mod], "m", lazy.group['scratchpad'].dropdown_toggle('mus')),
    Key([mod], "b", lazy.group['scratchpad'].dropdown_toggle('news')),
    Key([mod, "shift"], "n", lazy.group['scratchpad'].dropdown_toggle('term2')),


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
        lazy.spawn("betterlockscreen --lock"))

]
