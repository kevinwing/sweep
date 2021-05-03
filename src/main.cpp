/**
 * @file main.cpp
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief Spring 2021 CS151 final project - Minesweeper
 * @date 2021-04-14
 */

#include "game.h"
#include <SFML/Graphics.hpp>

int main()
{
	Game game(10, 10, 30);
    game.menu();

    return 0;
}