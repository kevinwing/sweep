/**
 * @file cell.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Cell class declaration file
 * @date 2021-04-21
 */
#ifndef CELL_H
#define CELL_H

#include <string>
// #include "baseRect.h"

using std::string;

const string ASSET_DIR = "assets/";
const string TEXTURE_PATHS[] = {
    "UnCheckedCell.png",
    "EmptyCell.png",
    "ExplodedMine.png",
    "Mine.png",
    "NotAMine.png",
    "Flag.png",
    "One.png",
    "Two.png",
    "Three.png",
    "Four.png",
    "Five.png",
    "Six.png",
    "Seven.png",
    "Eight.png"
};

enum TexturePathIndices{
    UNCHECKED=0,
    EMPTY,
    EXPLODED,
    MINE,
    NOTMINE,
    FLAG,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT
};

class Cell
{
    private:
        string mTexturePath;
        bool mIsMine;
        int mNumNeighborMines;
        float mSideLength;
    public:
        // Cell(float s=25, bool isMine=false, int xCoord=0, int yCoord=0);
        Cell(float s=25, bool isMine=false);
        // int getXcoord();
        // int getYCoord();
        bool& isMine();
        int getNumMines();
        void setNumMines(int n);
        // void setSize(float size);
        // void setTexturePath(string path);
        string& texturePath();
};

#endif