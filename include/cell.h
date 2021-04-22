/**
 * @file cell.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Cell class declaration file
 * @date 2021-04-21
 */
#ifndef CELL_H
#define CELL_H

#include <string>
#include "baseRect.h"

using std::string;

class Cell: protected BaseRect
{
private:
    bool mIsMine;
    int mNumNeighborMines;
    int mSideLength;
    int mCoordinateX, mCoordinateY;
public:
    Cell(int s=55, bool isMine=false, int xCoord=0, int yCoord=0);
    int getXcoord();
    int getYCoord();
    bool isMine();
    int getNumMines();
    void setSize(int size=55);
    void setTexture(string str);
};

#endif