Isometric-Emblem
================

TODO: 

	Gamestates.  Does setup need to be done for each gamestate?  For now playstate will have hardcoded vals
	but will be reading map info from file.  For now only worry about PlayState, eventually have a group of states,
	managed by a stateengine or statemanager within gameengine.  
	
	Menu/OverlayBox/GUI
	
	Frames done, need to redo graphic for accurate sizes (and smaller border)
	future: system to change fill color and border color (get pixel, replace all)
	
	Rethink how GUI works.  Might not be necessary to have flexible GUIDisplay/GUIFrame
	work on specific GUI widgets that are actually going to be used
	
	GUIWidget Animations. Zoom in from off-screen.  Have a "target" location and move towards that.  
	Animations should be in GUIWidget.  Once the frame is in place, render containing text/etc.  
	Ignore for now because animations are a luxury.
	
	DynamicEntity.  Currently have hardcoded move and attack ranges.  This will change in future.  
	Load default values based on unit type and add modifiers.  Need to look at sfml shaders for "ended" 
	units.
	
	1) If unit is already present in selected tile, cannot move. DONE
	2) multiple vectors for enemy, neutral, player units. Use this to create the inDistance method. DONE
	3) Display the red attack range if there are enemies in range of player AFTER moving. DONE
	4) Maybe not top-priority at the moment but resolve attack. This entails stats system, exp, etc.  
	Might save this for later since attacking works, it just doesn't really do anything right now.
	
	Graphics.  Sort the entities by row then col.  This will draw the sprites in the correct order based on 
	"closest" unit to the camera.
	
	InputState. Add inputstate of "attacking" so that no commands are accepted while the attack is being
	resolved.  For now, instantly resolve it in one update.
	
	
	
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