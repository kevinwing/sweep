/**
 * @file template.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief minesweeper header file
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GAME_H
#define GAME_H

#include "../include/board.h"
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

class Game
{
public:
	Game();
	void run();
    void input();
    void update();
    bool gameOver();
	Board board();
private:
	Board mBoard;
};

#endif