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

const string VERSION_NUM = "0.0.1";
const string GAME_LABEL = "Isometric FireEmblem RPG";
const sf::Color WINDOW_COLOR = sf::Color(117,169,191);

const string LOG_FILE = "log.txt";

const float INPUT_DELAY = 0.15;

// image paths hardcoded
const string TILE_ROCK = "res/rock_tile.png";
const string TILE_KEY = "rocktile";

// tile modifiers
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
const string PHASE_HUD = "phasehud";
const float PHASE_DUR = 1.0f;

const string TEMP_SPRITE = "res/unit_armor.png";
const string SPRITE_KEY = "spritearmor";

// Fonts
const string DEFAULT_FONT = "res/fonts/arial.ttf";
const string DEFAULT_FONT_KEY = "default";

// HUD keys
const string TERRAIN_MENU = "terrain_menu";

const int FONT_SIZE = 14;
const int LABEL_SIZE = 20;

// enums

namespace gamestate {
  enum Statetype { MENU, START, PLAY, PAUSE, EXIT, UNINIT };
  enum Playphase { PLAYER, ENEMY, NEUTRAL };
}

//maintain parallel enum/array so they can be used as indices
namespace terraintype {
  enum Area { NONE, PLAIN, MOUNTAIN, CLIFF, SEA, FOREST };

  const string TERRAIN_NAME[] = { "None", "Plain", "Mountain", "Cliff", "Sea", "Forest" };
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

#endif /* CONSTANTS_H_ */
