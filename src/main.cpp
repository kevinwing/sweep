/**
 * @file main.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief Spring 2021 CS151 final project - Minesweeper
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include "game.h"

int main()
{	
	Game game;
	Board board = game.getBoard();
	board.setUp();
	board.print();
	std::cout << '\n';
	board.layMines();
	board.print();
	return 0;
}