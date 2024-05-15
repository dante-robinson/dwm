## DWM
My personal DWM config that I use on OpenBSD. You will need to edit config.mk if using this setup on a different OS as the build options are set for OpenBSD. Currently using FIra Mono as the default but this can be changed in the config.def.h file as well as things like the bar size and keybinds.

## Compile
```
doas make install
```

It's really that simple. If you make a change delete config.h and make the changes to config.def.h or only make changes to config.h going forward, your choice.

## Patches
- barpadding
- bottomstack (through vanitygaps)
- dfacts
- dragmfact
- fibonacii (through vanitygaps)
- gaplessgrid (through vanitygaps)
- horizgrid (through vanitygaps)
- movestack
- statuspadding
- notitle

## Keybinds
**Super + Mouse Button 1 (Left Click) -** Move/Drag Window (also brings window to front and makes the window floating)<br>
**Super + Mouse Button 3 (Right Click) -** Resize floating only windows/adjust cfact/mfact<br>
**Super + J -** Cycle focused window left<br>
**Super + K -** Cycle focused window right<br>
**Super + Shift + R -** Restart DWM<br>
**Super + Shift + Q -** Quit CWM<br>
**Super + Q -** Kill app<br>
**Super + D -** Toggle Mute<br>
**Super + A -** Increase volume by 5%<br>
**Super + S -** Decrease volume by 5%<br>
**Super + W -** Launch dmenu<br>
**Super + Enter -** Launch an st terminal<br>
**Super + Number -** Change to that Workspace Number so 5 would bring to Workspace 5<br>
**Super + Shift + Number -** Move current window to that workspace<br>
**Super + P -** Take a screenshot of the entire screen using scrot<br>
**Super + Shift + P -** Take a screenshot of a selected area using scrot<br>
**Super + Shift + J -** Move window to the left<br>
**Super + Shift + K -** Move window to the right<br>
**Super + I -** Change to a vertical window stack<br>
**Super + Shift + I -** Change to a horizontal stack<br>
**Super + Space -** Toggle between last used layout<br>
**Super + H -** Change mfact left<br>
**Super + L -** Change mfact right<br>
**Super + Shift + H -** Change cfact up<br>
**Super + Shift + L -** Change cfact down<br>
**Super + O -** Reset mfact to default<br> 
**Super + Shift + O -** Reset cfact to default<br>
**Super + 0 -** View all open apps across all workspaces<br>
**Super + Z -** Tile Layout<br>
**Super + X -** Monocle Layout<br>
**Super + E -** Spiral Layout<br>
**Super + Shift + E** Dwindle Layout<br>
**Super + V -** Deck Layout<br>
**Super + B -** BStack Layout<br>
**Super + Shift + B -** BStack Horizontal Layout<br>
**Super + N -** Grid Layout<br>
**Super + Shift + N -** NRow Grid Layout<br>
**Super + M -** Horizontal Grid Layout<br>
**Super + Shift + M -** Gapless Grid Layout<br>
**Super + C -** Centered Master Layout<br>
**Super + Shift + C -** Centered Floating Master Layout <br>

## Pictures
Coming Soon
