from libqtile.config import  ScratchPad, DropDown, Key, Group
from libqtile.lazy import lazy
from libqtile.command import lazy
from .keys import keys, mod 

'''
░██████╗░██████╗░░█████╗░██╗░░░██╗██████╗░░██████╗
██╔════╝░██╔══██╗██╔══██╗██║░░░██║██╔══██╗██╔════╝
██║░░██╗░██████╔╝██║░░██║██║░░░██║██████╔╝╚█████╗░
██║░░╚██╗██╔══██╗██║░░██║██║░░░██║██╔═══╝░░╚═══██╗
╚██████╔╝██║░░██║╚█████╔╝╚██████╔╝██║░░░░░██████╔╝
░╚═════╝░╚═╝░░╚═╝░╚════╝░░╚═════╝░╚═╝░░░░░╚═════╝░
'''

    '''
    █▀ █▀▀ █▀█ ▄▀█ ▀█▀ █▀▀ █░█ █▀█ ▄▀█ █▀▄ █▀
    ▄█ █▄▄ █▀▄ █▀█ ░█░ █▄▄ █▀█ █▀▀ █▀█ █▄▀ ▄█
    '''
# Define scratchpads
groups = [
    ScratchPad("scratchpad", 
        [
            DropDown("term", "kitty --class=scratch", width=0.8, height=0.8, x=0.1, y=0.1, opacity=1),
            DropDown("term2", "kitty --class=scratch", width=0.8, height=0.8, x=0.1, y=0.1, opacity=1),
            DropDown("ranger", "kitty --class=ranger -e ranger", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
            DropDown("volume", "kitty --class=volume -e pulsemixer", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
            DropDown("mus", "kitty --class=mus -e ncmpcpp", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
            DropDown("news", "kitty --class=news -e newsboat", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9)
        ]
    )
]


(ScratchPad("scratchpad", [
    DropDown("term", "kitty --class=scratch", width=0.8, height=0.8, x=0.1, y=0.1, opacity=1),
    DropDown("term2", "kitty --class=scratch", width=0.8, height=0.8, x=0.1, y=0.1, opacity=1),
    DropDown("ranger", "kitty --class=ranger -e ranger", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
    DropDown("volume", "kitty --class=volume -e pulsemixer", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
    DropDown("mus", "kitty --class=mus -e ncmpcpp", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),
    DropDown("news", "kitty --class=news -e newsboat", width=0.8, height=0.8, x=0.1, y=0.1, opacity=0.9),

]))



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
            Key([alt], "Tab", lazy.screen.next_group(), desc="Move to next group."),
            Key([alt, "shift"], "Tab",
                lazy.screen.prev_group(),
                desc="Move to previous group.",),
            Key([mod, "shift"], i.name,
                lazy.window.togroup(i.name),
                desc="Move focused window to new group.",),
        ]
    )
