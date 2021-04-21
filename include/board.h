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

class Board
{
public:
	Board(int mines = 5, int x = 5, int y = 5)
	{
		mMines = mines;
		mWidth = x;
		mHeight = y;
	}
	void print();
	void setWidth(int width);
	void setHeight(int height);
private:
	int mMines = 10;
    int mWidth = 10;
    int mHeight = 10;
	char bomb = 'B';
};

#endif