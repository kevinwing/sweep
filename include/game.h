
#include <SFML/Graphics.hpp>
#include "board.h"

#ifndef GAME_H
#define GAME_H

class Game 
{   
public:
    Game(int width, int height, int cellSize);
    // void loadGamemWindow();
    // void setWidth(int width);
    // void setHeight(int height);
    // bool loadGamePieces();
    // void setGamePieces();        
    // void setUserPrompt();
    // void rectangleCoordinates();
    // void setRectCoordinates(sf::IntRect &rect, int left, int top, int width, int height);
    // void setPositionPieces(sf::Vector2i &pos, int left, int top);
    // void positionPiece();
    // bool isClickInBounds(int boardPos);
    // bool takeTurn(int turn);
    void run();

private:
    sf::RenderWindow mWindow;
    Board mBoard;
    // sf::Texture gameBoard, cell, grayCell;
    // sf::Sprite addBoard, addCell, addGrayCell, piece[390];
    // sf::IntRect square[390];
    // sf::Vector2i position[390];
    // sf::Event event;
    int mWindowHeight, mWindowWidth, mCellSize;

};


#endif