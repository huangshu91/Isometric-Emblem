/*
 * Map.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Maiev
 */

#include "../Util/Constants.h"
#include "../Entity/DynamicEntity.h"
#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(GameEngine* eng) : eng_ptr(eng), row(0), col(0) { }

void Map::setDimensions(int x, int y) {
  row = x;
  col = y;

  for (int i = 0; i < row; i++) {
    vector<Cell> row;
    for (int j = 0; j < col; j++) {
      row.push_back(Cell(eng_ptr, getMap(), i, j));
    }
    board.push_back(row);
  }
}

// offsets and tiles are currently hardcoded, get from file
void Map::setupEntity() {
  player = new DynamicEntity(eng_ptr, SPRITE_KEY);
  player->setOffset(6, -4);
  player->setTile(getCell(1,2));
  getCell(1,2)->unit = player;
}

Map::~Map() {
  // TODO Auto-generated destructor stub
}

Cell* Map::getCell(int x, int y) {
  if (x < 0 || x >= row || y < 0 || y >= col) return 0;

  return &(board[x][y]);
}

void Map::render() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      board[i][j].render();
    }
  }
}

void Map::renderUnits() {
  player->render();
}
