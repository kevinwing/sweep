/**
 * @file game.h
 * @author Kevin Wing, Connor McElroy, Caleb Simmons
 * @brief game class header file
 * @date 2021-05-03
 */
#include <SFML/Graphics.hpp>
#include "board.h"

#ifndef GAME_H
#define GAME_H

class Game 
{   
public:
    Game(int width, int height, int cellSize);
    void menu();
    void run(int width, int height, int mines);

private:
    sf::RenderWindow mWindow;
    Board mBoard;
    int mWindowHeight, mWindowWidth, mCellSize;

};


#endif