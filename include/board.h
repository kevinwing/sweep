/**
 * @file board.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief board class header file
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
	// void print();
	// void initTextures();
	void setNumFlags(int flags);
	void addFlag();
	void subtractFlag();
	bool noFlags();
	// void setWidth(int width);
	// void setHeight(int height);
	void setMines(int mines);
	Cell& getCell(int x, int y);
	void checkCell(int x, int y);
	bool getGameStatus();
	void setGameStatus(bool game);
	bool& isWon();
	bool checkConditions();
	void showMines();
	int &cellsRemaining();

private:
	int mMines;
    int mWidth;
    int mHeight;
	int mFlags;
	int mCellsRemaining;
	vector<vector<Cell>> mBoard;
	
	void countNeighborMines();
	void createBoard();
	void layMines();
	void checkCell(int x, int y, bool isClicked);
	bool checkForMine(int x, int y);

	bool gameStatus;
	bool mIsWon;

};

#endif