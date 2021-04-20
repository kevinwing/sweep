/**
 * @file template.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief minesweeper header file
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "board.h"

#ifndef TEMPLATE_H
#define TEMPLATE_H

class Game
{
public:
	Game();
	~Game();

	void run();

    void input();

    void update();

    bool gameOver();
private:
	Board board;
};

#endif