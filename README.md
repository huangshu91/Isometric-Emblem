Isometric-Emblem
================

TODO: 
	Gamestates
	Menu/OverlayBox/GUI
		- Frames done, need to redo graphic for accurate sizes (and smaller border)
		- future: system to change fill color and border color (get pixel, replace all)
	Entities
	Rethink how GUI works.  Might not be necessary to have flexible GUIDisplay/GUIFrame
		- work on specific GUI widgets that are actually going to be used
	GUIWidget Animations
		- Zoom in from off-screen.  Have a "target" location and move towards that.  
		Animations should be in GUIWidget.  Once the frame is in place, render containing text/etc.  
		Ignore for now because animations are a luxury.
	
FUTURE:
	Mouse control scheme (point in polygon)
	Font manager if more than one font is used. (including same font different sizes?)
	
NOTES:
	build release with -mwindows so no console + crash on exit
	
	Might need to rethink the relationship between the map/cell/entities.  
	Currently think of entities has "pieces" so they dont have a "move" method.  
	The input controller will move the entity which is owned by the map and cell.  
	The entity knows which cell it belongs to but has no control of its own.