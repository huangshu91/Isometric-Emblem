/*
 * Constants.h
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace std;

template <typename T>
string numberToString ( T Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}

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

const string TILE_HIGH = "res/highlight_tile.png";
const string TILE_HIGH_KEY = "tilehigh";

const string GUI_FRAME = "res/gui_frame.png";
const string GUI_FRAME_KEY = "guiframe";
const int FRAME_CELL = 40;

// HUD keys
const string TERRAIN_MENU = "terrain_menu";

const int FONT_SIZE = 14;
const int LABEL_SIZE = 20;

// enums

namespace state {
  enum GameStateType { MENU, START, CHAT, LOOP, PAUSE, EXIT };
}

namespace terraintype {
  enum Area { NONE, PLAIN, MOUNTAIN, CLIFF, SEA, FOREST };

  const string TERRAIN_NAME[] = { "NONE", "PLAIN", "MOUNTAIN", "CLIFF", "SEA", "FOREST" };
  const string NONE_STRING = "Terrain";
  const string PLAIN_STRING = "Plain";
  const string MOUNTAIN_STRING = "Mountain";
}

#endif /* CONSTANTS_H_ */
