/**
 * @file main.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief Spring 2021 CS151 final project - Minesweeper
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// #include "template.h"
// #include "board.h"
#include "game.h"
#include <SFML/Graphics.hpp>
// #include <iostream>

// const int MENU_WIDTH = 200;
// const int MENU_HEIGHT = 320;

int main()
{
	Game game(10, 10, 30);
    // game.loadGamemWindow();
    // if(!game.loadGamePieces()) //game.loadGamePieces

    //     return EXIT_FAILURE;
    // game.setGamePieces();

    game.menu();

    return 0;
}