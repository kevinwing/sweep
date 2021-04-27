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
#include "cell.h"

using std::cout;
using std::vector;

class Board
{
public:
	Board(int mines = 5, int x = 5, int y = 5, vector<vector<Cell>> m = {})
	{
		mMines = mines;
		mWidth = x;
		mHeight = y;
		matrix = m;
	}
	int getHeight();
	int getWidth();
	void setUp();
	void print();
	void layMines();
	void setWidth(int width);
	void setHeight(int height);
	vector<vector<Cell>> getMatrix();
	void checkCell(int x, int y);

private:
	int mMines;
    int mWidth;
    int mHeight;
	vector<vector<Cell>> matrix;
	
	void checkCell(int x, int y, bool isClicked);

};

#endif