<<<<<<< HEAD
/**
 * @file template.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief minesweeper header file
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
=======

#include <SFML/Graphics.hpp>
// #include "board.h"
>>>>>>> GameClass

#ifndef GAME_H
#define GAME_H

<<<<<<< HEAD
#include <vector>
#include <iostream>
#include "board.h"

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
	Board getBoard();
private:
	Board mBoard;
};

=======
class Game 
{   
public:
    void loadGameWindow();
    void setWidth();
    void setHeight();
    bool loadGamePieces();
    void setGamePieces();        
    void setUserPrompt();
    void rectangleCoordinates();
    void setRectCoordinates(sf::IntRect &rect, int left, int top, int width, int height);
    void setPositionPieces(sf::Vector2i &pos, int left, int top);
    void positionPiece();
    bool isClickInBounds(int boardPos);
    // bool takeTurn(int turn);
    void gameLoop();

private:
    sf::RenderWindow window;
    sf::Texture gameBoard, cell, grayCell;
    sf::Sprite addBoard, addCell, addGrayCell, piece[390];
    sf::IntRect square[390];
    sf::Vector2i position[390];
    sf::Event event; 
    int windowHeight, windowWidth;

};


>>>>>>> GameClass
#endif