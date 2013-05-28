/*
 * Constants.h
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <SFML/Graphics.hpp>
using namespace std;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;
const int WINDOW_COLOR_DEPTH = 32;
const int FPS_LIMIT = 60;
const bool DEBUG = true;

const string VERSION_NUM = "0.0.2";
const string GAME_LABEL = "Isometric RPG";
const sf::Color WINDOW_COLOR = sf::Color(117,169,191);

const string LOG_FILE = "log.txt";
const string SS_PATH = "Screenshot/";

const float INPUT_DELAY = 0.15;

const string TILE_ROCK = "res/Tiles/rock_plain_tile.png";
const string TILE_KEY = "rocktile";

const string TILE_WATER = "res/Tiles/water_plain_tile.png";
const string TILE_WATER_KEY = "watertile";

const string TILE_GRASS = "res/Tiles/grass_plain_tile.png";
const string TILE_GRASS_KEY = "grasstile";

const string TILE_TREE = "res/Tiles/forest_plain_tile.png";
const string TILE_TREE_KEY = "treetile";

const string TILE_HIGH = "res/highlight_tile.png";
const string TILE_HIGH_KEY = "tilehigh";

const string RANGE_MOVE = "res/range_move.png";
const string RANGE_MOVE_KEY = "tilemoverange";

const string RANGE_ATTACK = "res/range_attack.png";
const string RANGE_ATTACK_KEY = "tileattackrange";
//-----

const string GUI_FRAME = "res/gui_frame.png";
const string GUI_FRAME_KEY = "guiframe";
const int FRAME_CELL = 40;

const string PHASE_PLAYER = "res/phase_player.png";
const string PHASE_ENEMY = "res/phase_enemy.png";
const string PHASE_PLAYER_KEY = "playerphase";
const string PHASE_ENEMY_KEY = "enemyphase";
const float PHASE_DUR = 0.5f;

const string UNIT_ARMOR = "res/Units/unit_armor.png";
const string UNIT_ARMOR_KEY = "Maiev";

const string UNIT_ARMOR_RED = "res/Units/unit_armor_red.png";
//const string UNIT_ARMOR_RED = "res/Units/unit_dummy.png";
const string UNIT_ARMOR_RED_KEY = "Testing";

const string PORTRAIT_ICON = "res/portrait_icon.png";

// Fonts
const string DEFAULT_FONT = "res/fonts/arial.ttf";
const string DEFAULT_FONT_KEY = "default";

// HUD keys
const string TERRAIN_MENU = "terrain_menu";
const string PHASE_HUD = "phasehud";
const string STATUS_HUDR = "status_hudr";
const string STATUS_HUDL = "status_hudl";
const string EXP_HUD = "exp_hud";

const int GUI_PADDING = 30;

const int FONT_SIZE = 14;
const int LABEL_SIZE = 20;

const float SHAKE_DURATION = 0.2f;
const int SHAKE_INTENSITY = 2;

const float EXP_DUR = 1;
const int EXP_RATE = 2;

// encyclopedia file paths

const string DB_CLASS = "res/Data/classdb.txt";
const string DB_TILE = "res/Data/tiledb.txt";
const string DB_CHAP = "res/Data/chapterdb.txt";

// enums

namespace gamestate {
  enum Statetype { MENU, START, PLAY, PAUSE, EXIT, UNINIT };
  enum Playphase { PLAYER, ENEMY, NEUTRAL, NEWTURN,
                   FIGHT, FINISHFIGHT, UNITDEATH, LOSS };
}

namespace camera {
  enum Effect { NONE, SMOOTH, SHAKE };
}

//maintain parallel enum/array so they can be used as indices
namespace unit {
  enum Class { NONE, BANDIT, ARCHER, CAVALIER };
  enum Control { EMPTY, PLAYER, ALLIED, ENEMY };

  const string CLASS_SPRITE[] = { "None", "Bandit", "Archer", "Cavalier" };
}

namespace dir {
  enum Direction { UP, DOWN, LEFT, RIGHT };
}

namespace inputstate {
  enum Phase { FREE, MOVE, ACTION, ATTACK };
}

namespace range {
  enum RangeType { MOVE, ATTACK, COMBINED, AURA };
}

namespace item {
  enum Type { UNINIT, SWORD, AXE, LANCE, SHIELD, CONSUME };
}

#endif /* CONSTANTS_H_ */
