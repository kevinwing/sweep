/**
 * @file board.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-04-19
 *
 * @copyright Copyright (c) 2021
 *
 */


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "cell.h"

using std::cout;
using std::vector;
using std::string;

const string ASSET_DIR = "assets/";

const string TEXTURE_PATHS[] = {
    "UnCheckedCell.png",
    "EmptyCell.png",
    "ExplodedMine.png",
    "Mine.png",
    "NotAMine.png",
    "Flag.png",
    "One.png",
    "Two.png",
    "Three.png",
    "Four.png",
    "Five.png",
    "Six.png",
    "Seven.png",
    "Eight.png"
};

enum TexturePathIndices{
    UNCHECKED=0,
    EMPTY,
    EXPLODED,
    MINE,
    NOTMINE,
    FLAG,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT
};

class Board
{
public:
	// Board();
	void createBoard(int width, int height);
	void print();
	void layMines();
	void setNumMines();
	void setWidth(int width);
	void setHeight(int height);
	Cell getCell(int x, int y);

	void checkCell(int x, int y);

private:
	int mMines;
    int mWidth;
    int mHeight;
	vector<vector<Cell>> mBoard;
	
	void checkCell(int x, int y, bool isClicked);

};

#endif