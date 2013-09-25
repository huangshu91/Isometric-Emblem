Isometric-Emblem
================

TODO: 

	-ITEMS
	-MAP LOADING
	-EXPERIENCE/LEVELUP/LEVEL
	-UNIT TYPES/ADV STATS
	
	Effect_Manager holds all the effects which are created and owned by the manager.  Others will call the manager asking to create certain effects.  Effects are like GUIWidgets and all derive from base class Effect which has info on duration, effect_type, etc.
	
	Work on graphical things next.  Combat numbers popping up.  Particle effects.  Consider elevating the tiles of units in combat while darkening the rest of the screen.
	
	Instead of adding simple animation effects to renderable objects themselves, use the effectmanager (WIP). This will keep track of what object needs to be moved/shaked/etc.
	
	Can add move schemantics to MenuWidget (addChild) but I don't think the speedup gain is worth the time.  Work on this if i'm ever bored.
	
	Need to consider how to use textwidget by itself.  What owns it?  Each one needs to built anew because of size.
	
	Levelup.  Can do this without finishing stats system.  Need the GUI for levelup and controller.
	
	Items system.  Flesh it out and split into multiple parts.  Equipment is one task (involves stats, hooking up with units, chapter/enemy loading, etc).  Items held is another, they dont' have to DO anything yet but system needs to be set up so that you can see what items you have on you.  Item drops/chests is a third system that is integrated into map/tiles and need a generation system and map loading.
	
	Visibility system.  Tiles should have a variable that says if it is visible or not.  If not, terrain info and units/items are hidden.  Use default tile (greyed color) to represent a hidden tile.  Decreased visibility at dusk and dawn with severely decreased visibility at night.
	
	Color for dialogue. 
	
	multithread for loading in future. database loading, sound manager, map loading. display simple load screen and use other thread to load then pass messages back to update progress. will be necessary because of number of assests loaded into mem at start of game.  Actually, looking at the load times for database files (which includes textures), this might not be necessary.
	
	Maps are loaded when needed (when it is used).  Everything else should be loaded right at start in database.
	
	For text, use double \n because of spacing and readability.  For now use very simple formating, consider effects in future.
	
	Reaaaaaaaally need to split up inputcontroller. getting real messy. DONE
	
	Split InputController into 2 source files.  One that has bare minimum of update, render, etc. The other contains logic for selecting cell, selecting menu, updating cell, etc.
	
	Rework Menu so that InputController is manages the unit menu directly.  MenuController only controls menus that are not attached to any entity (base menu, status menu, etc).
	
	MenuWidget. Instead of doing a very general approach, it is easier to just hardcode the different types of actions.  Similarly, instead of a general number and type of menu it is easier to just hardcode the menus that get created in menucontroller.  For now this behavior makes sense because of the limited possibiltiies of these menus but might require large refactor in future.
	
	Change fonts over to Visitor.  Easy but too lazy to experiment
	
	Map source split into 2 files.  Map_Construction.cpp deals with anything related to the construction of a map and rendering.  Map.cpp deals with how the map is used and functions that others call.
	
	Needs more refining of battle system.  Tweak delay to make it obvious when consecutive fights occur.  Move camera/highlight to attacking unit (when enemy).  Either return camera to old location when player turn or switch highlight to last logical position.
	
	Map source too big.  Split into different source files.  One for handling the map during runtime and the other for loading/setting up the map.
	
	Map::createEntity is to load ENEMY entities for that level.  setupEntity is just for player entities and does not load from file.  hardcode player entities in database.
	
	Camera.  In update, at the end of smooth state, if setcenter, there is a slight whiplash effect.  can keep or remove.
	
	EXP gain.  Until I flesh out class structure and have an idea of how growth should work, not going to bother making
	exp gain formula.  Static exp gain of 50 per killed unit.  Once the expwidget reaches 100, call level up on unit.  This might be bad design but it lets the animation finish before displaying level up screen.
	
	Note to self: Exp bar.  ProgressBar class, build from sfml primitives + pointer for now.  Window focus. Check focus in event handling and then check that in update of inputcontroller.
	
	Two versions of the function shakeMove. One has a center but its never used (maybe useful, keep for now).
	
	Cells. Redo alot of this stuff.  Since we are now using different types of cells. A newly created cell just has logic but no graphics.  You then set the type and the cell will check the database for what the graphical base and adds are for itself.  Cell creation is now a two set process but overall is more flexible.
	
	Database is the encyclopedia of all game data.  It will load all character, item, map data.  When creating new anything,
	check database for base values.  If it's not in the game-database, it is not valid. Finish up class loading later, need to do some file i/o to get values.  Link entity creation to database lookup of class types.  Database will have lots of methods for debugging, verify data is loaded correctly and everything is linked at the end of loading.
	
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
	skills? - (Consider if this mechanic makes sense)
	
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
	
	Do not overdesign the classdb and make sure all referenced classes in promote path exist, even if the numbers are filler.