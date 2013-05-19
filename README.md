Isometric-Emblem
================

TODO: 

	-ITEMS
	-MAP LOADING
	-EXPERIENCE/LEVELUP/LEVEL
	-UNIT TYPES/ADV STATS
	
	Database is the encyclopedia of all game data.  It will load all character, item, map data.  When creating new anything,
	check database for base values.  If it's not in the game-database, it is not valid. Finish up class loading later, need to do some file i/o to get values.  Link entity creation to database lookup of class types.
	
	Day/night cycle.  Certain units get bonuses for day/night.  Have a cycle status widget in center top of screen.
	
	Unit stat widget.  Consider making this simple widget so taht when a unit is highlighted, you can see its stats.
	This should be placed next to the unit or above the unit, this way the status widget can be kept simple yet you
	can at a glance see the strength of a unit without having to go into a different screen/mode.
	
	Loading from files, use simple text for now but consider Json, xml, yaml, ini if scope gets bigger.
	
	Particle system for effects?  Camera shake is probablyf ine for now.
	
	Camera shake when attack. When unit is attacked, center it. What about tilehighlight?  Could either set the tile highlight to be the attacked tile or at the beginning of the newturn, return camera to that location.
	
	Items.  For now make parent entity necessary but in future use a storage/warehouse system (that could be a parent
	instead?). Think of system for determining what classes can use what equipment.
	
	If battle becomes more complicated with the addition of helpers, formations, bonuses, skills, etc.  It
	might be necessary to create a 'BattleManager' system where you pass in the units that are fighting and have
	that system resolve the battle and update all relevant systems.  This not only keeps Entity code clean but makes
	sense logically because the pieces themselves should not be handling system updates.

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
	
	Movement. Need to use A* to find the path that the unit should travel. Add arrow to show.  Double check
	movement modifiers such as different terrain or impassable terrain affect my current method.
	
FUTURE:

	Mouse control scheme (point in polygon)
	Font manager if more than one font is used. (including same font different sizes?)
	
	Features:
	Formation - Stand United (positional bonuses)
	Titles - (bonuses for unit achievements)
	Rewards - (bonuses for objectives in stage)
	Day/Night phase - (modifier based on time of day for certain units)
	
NOTES:

	build release with -mwindows so no console + crash on exit
	
	Might need to rethink the relationship between the map/cell/entities.  
	Currently think of entities has "pieces" so they dont have a "move" method.  
	The input controller will move the entity which is owned by the map and cell.  
	The entity knows which cell it belongs to but has no control of its own.
	
	Show movement range (and accompanying sprites/logic) is contained in the map.  
	This makes sense to me because the highlight is part of the map and unlike tilehighlight is not "controlled" 
	by input other than activated or not.
	
	NEED TESTING. STARTING TO GET TOO COMPLICATED TO EASILY REASON ABOUT.