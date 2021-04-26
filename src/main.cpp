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

int main()
{
	Game game;
    game.loadGameWindow();
    if(!game.loadGamePieces()) //game.loadGamePieces
        return EXIT_FAILURE;

    game.setGamePieces();

    game.gameLoop();

    return EXIT_SUCCESS;
}