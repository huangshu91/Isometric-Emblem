Isometric-Emblem
================

TODO: 

	Gamestates
	
	Menu/OverlayBox/GUI
	
	Frames done, need to redo graphic for accurate sizes (and smaller border)
	future: system to change fill color and border color (get pixel, replace all)
	
	Rethink how GUI works.  Might not be necessary to have flexible GUIDisplay/GUIFrame
	work on specific GUI widgets that are actually going to be used
	
	GUIWidget Animations. Zoom in from off-screen.  Have a "target" location and move towards that.  
	Animations should be in GUIWidget.  Once the frame is in place, render containing text/etc.  
	Ignore for now because animations are a luxury.
	
	DynamicEntity.  Currently have hardcoded move and attack ranges.  This will change in future.  
	Load default values based on unit type and add modifiers.  Control for movement is Q, control for
	attack is E.  Eventually figure out a good menu or A,B input method.  
	
	1) If unit is already present in selected tile, cannot move. DONE
	2) multiple vectors for enemy, neutral, player units. Use this to create the inDistance method.
	3) Display the red attack range if there are enemies in range of player AFTER moving.
	
FUTURE:

	Mouse control scheme (point in polygon)
	Font manager if more than one font is used. (including same font different sizes?)
	
NOTES:

	build release with -mwindows so no console + crash on exit
	
	Might need to rethink the relationship between the map/cell/entities.  
	Currently think of entities has "pieces" so they dont have a "move" method.  
	The input controller will move the entity which is owned by the map and cell.  
	The entity knows which cell it belongs to but has no control of its own.
	
	Show movement range (and accompanying sprites/logic) is contained in the map.  
	This makes sense to me because the highlight is part of the map and unlike tilehighlight is not "controlled" 
	by input other than activated or not.