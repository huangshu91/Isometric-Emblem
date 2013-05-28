/*
 * DatabaseTest.h
 *
 *  Created on: May 26, 2013
 *      Author: Maiev
 */

#ifndef DATABASETEST_H_
#define DATABASETEST_H_
#include <vector>
#include <map>
#include "Database.h"
using namespace std;

void testClasses(vector<string> classes, map<string, UnitClass> db);
void testTiles(vector<string> tiles, map<string, TileDef> db);
void testChap(vector<string> chap, map<string, ChapDef> db);

#endif /* DATABASETEST_H_ */
