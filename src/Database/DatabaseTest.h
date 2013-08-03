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

void testClasses(std::vector<std::string> classes, std::map<std::string, UnitClass> db);
void testTiles(std::vector<std::string> tiles, std::map<std::string, TileDef> db);
void testChap(std::vector<std::string> chap, std::map<std::string, ChapDef> db);
void testConvo(std::vector<std::string> convs, std::map<std::string, Convo> db);

#endif /* DATABASETEST_H_ */
