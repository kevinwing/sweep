/**
 * @file board.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief
 * @date 2021-04-19
 */


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "cell.h"

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
	void setNumFlags(int flags);
	void addFlag();
	void subtractFlag();
	bool noFlags();
	void showMines();
	bool checkForMine(int x, int y);
	void setWidth(int width);
	void setHeight(int height);
	void setMines(int mines);
	Cell& getCell(int x, int y);

	void checkCell(int x, int y);

private:
	int mMines;
    int mWidth;
    int mHeight;
	int mFlags;
	vector<vector<Cell>> mBoard;
	
	void checkCell(int x, int y, bool isClicked);

};

#endif