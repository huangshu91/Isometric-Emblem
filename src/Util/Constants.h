/*
 * Constants.h
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 540;
const int WINDOW_COLOR_DEPTH = 32;
const int FPS_LIMIT = 60;
const bool DEBUG = true;

const std::string VERSION_NUM = "0.0.2";
const std::string GAME_LABEL = "Isometric RPG";
const sf::Color WINDOW_COLOR = sf::Color(117,169,191);

const std::string LOG_FILE = "log.txt";
const std::string SS_PATH = "Screenshot/";

const float INPUT_DELAY = 0.15;

const std::string TILE_BASE = "res/Tiles/rock_plain_tile.png";
const std::string TILE_KEY = "rocktile";

const std::string TILE_HIGH = "res/highlight_tile.png";
const std::string TILE_HIGH_KEY = "tilehigh";

const std::string MENU_CURSOR = "res/Misc/cursor_feather.png";
const std::string MENU_CURSOR_KEY = "menucursor";

const std::string RANGE_MOVE = "res/range_move.png";
const std::string RANGE_MOVE_KEY = "tilemoverange";

const std::string RANGE_ATTACK = "res/range_attack.png";
const std::string RANGE_ATTACK_KEY = "tileattackrange";
//-----

const std::string GUI_FRAME = "res/gui_frame.png";
const std::string GUI_FRAME_KEY = "guiframe";
const int FRAME_CELL = 40;

const std::string PHASE_PLAYER = "res/phase_player.png";
const std::string PHASE_ENEMY = "res/phase_enemy.png";
const std::string PHASE_PLAYER_KEY = "playerphase";
const std::string PHASE_ENEMY_KEY = "enemyphase";
const float PHASE_DUR = 0.5f;

const std::string UNIT_ARMOR = "res/Units/unit_armor.png";
const std::string UNIT_ARMOR_KEY = "Maiev";

const std::string UNIT_ARMOR_RED = "res/Units/unit_armor_red.png";
const std::string UNIT_ARMOR_RED_KEY = "Testing";

const std::string PORTRAIT_ICON = "res/portrait_icon.png";

// Fonts
const std::string DEFAULT_FONT = "res/fonts/arial.ttf";
const std::string DEFAULT_FONT_KEY = "default";
const std::string VISITOR_FONT = "res/fonts/visitor1.ttf";
const std::string VISITOR_FONT_KEY = "visitor1";

// HUD keys
const std::string TERRAIN_MENU = "terrain_menu";
const std::string PHASE_HUD = "phasehud";
const std::string STATUS_HUDR = "status_hudr";
const std::string STATUS_HUDL = "status_hudl";
const std::string EXP_HUD = "exp_hud";
const std::string MENU_HUD_UNIT = "menu_hud_unit";
const std::string MENU_HUD_GEN = "menu_hud_gen";
const std::string SPEECH_HUD = "speech_hud";

const std::string TEXT_HUD = "text_hud";

const int GUI_PADDING = 30;
const int MENU_PADDING = 5;

const int FONT_SIZE = 14;
const int LABEL_SIZE = 20;
const int VISITOR_SIZE = 18;
const int VIS_LABEL_SIZE = 24;

const float SHAKE_DURATION = 0.2f;
const int SHAKE_INTENSITY = 2;

const float EXP_DUR = 1;
const int EXP_RATE = 2;

const int TEXT_RATE = 10;

// encyclopedia file paths

const std::string DB_CLASS = "res/Data/classdb.txt";
const std::string DB_TILE = "res/Data/tiledb.txt";
const std::string DB_CHAP = "res/Data/chapterdb.txt";
const std::string DB_INFO = "res/Data/infodb.txt";

// enums

namespace gamestate {
  enum Statetype { START, PLAY, PAUSE, EXIT, UNINIT };
}

namespace playstate {
  enum Phase { PLAYER, ENEMY, NEUTRAL, NEWTURN, RETURN,
    FIGHT, FINISHFIGHT, UNITDEATH, LOSS, MENU, CONVO };
}

namespace menu {
  enum Type { NONE, UNIT, STAT };
  enum UnitChoice { ATTACK, ITEM, END };
  enum GenChoice { UNITS, STATUS, OPTION, ENDTURN };

  const int NUM_UNIT_CHOICE = 3;
  const std::string CHOICE_TEXT[] = { "ATTACK", "ITEM", "END" };

  const int NUM_GEN_CHOICE = 4;
  const std::string GEN_TEXT[] = { "UNIT", "STATUS", "CONFIG", "END" };
}

namespace anchor {
  enum Position { TOPLEFT, TOPRIGHT, BOTLEFT, BOTRIGHT, CENTER };
}

namespace camera {
  enum Effect { NONE, SMOOTH, SHAKE };
}

//maintain parallel enum/array so they can be used as indices
namespace unit {
  enum Class { NONE, BANDIT, ARCHER, CAVALIER };
  enum Control { EMPTY, PLAYER, ALLIED, ENEMY };

  const std::string CLASS_SPRITE[] = { "None", "Bandit", "Archer", "Cavalier" };
}

namespace dir {
  enum Direction { UP, DOWN, LEFT, RIGHT };
}

namespace inputstate {
  enum Phase { FREE, MOVE, ACTION, ATTACK, MENU };
}

namespace range {
  enum RangeType { MOVE, ATTACK, COMBINED, AURA };
}

namespace item {
  enum Type { UNINIT, SWORD, AXE, LANCE, SHIELD, CONSUME };
}

#endif /* CONSTANTS_H_ */
