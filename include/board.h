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

class Board
{
public:
	Board(int width, int height);
    void setSize(int width, int height);
	void createBoard();
	void print();
	void layMines();
	void setNumMines();
	void showMines();
	bool checkForMine(int x, int y);
	void setWidth(int width);
	void setHeight(int height);
	Cell& getCell(int x, int y);

	void checkCell(int x, int y);

private:
	int mMines;
    int mWidth;
    int mHeight;
	vector<vector<Cell>> mBoard;
	
	void checkCell(int x, int y, bool isClicked);

};

#endif