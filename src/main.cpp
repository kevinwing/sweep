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
<<<<<<< HEAD
{	
	// sf::RenderWindow window(sf::VideoMode(640, 480), "Rendering the rectangle.");
	// Game game;
	// Board board = game.getBoard();
	// board.setUp();
	// //board.layMines();

	// while(window.isOpen())
    // {
    //     sf::Event event;
    //     while(window.pollEvent(event))
    //     {
    //         if(event.type == sf::Event::Closed)
    //         {
    //             // Close window button clicked.
    //             window.close();
    //         }
    //     }

    //     window.clear(sf::Color::Black);
    //     for (int i = 0; i < board.getHeight(); ++i)
	// 	{
	// 		for (int j = 0; j < board.getWidth(); ++j)
	// 		{
    //         	board.getMatrix()[i][j].getShape().setPosition(sf::Vector2f(board.getMatrix()[i][j].getXcoord(), board.getMatrix()[i][j].getYcoord()));
	// 			window.draw(board.getMatrix()[i][j].getShape());
	// 			std::cout << board.getMatrix()[i][j].getXcoord() << ' ' << board.getMatrix()[i][j].getYcoord() << '\n';
	// 		}
	// 	}
    //     window.display();
    // }

	return 0;
=======
{
	Game game;
    game.loadGameWindow();
    if(!game.loadGamePieces()) //game.loadGamePieces
        return EXIT_FAILURE;

    game.setGamePieces();

    game.gameLoop();

    return EXIT_SUCCESS;
>>>>>>> master
}