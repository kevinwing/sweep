/**
 * @file cell.h
 * @author Connor McElroy, Caleb Simmons, Kevin Wing
 * @brief Cell class declaration file
 * @date 2021-04-21
 */
#ifndef CELL_H
#define CELL_H

#include "baseRect.h"
#include <string>

using std::string;

class Cell : public BaseRect
{
    private:
        // string mTexturePath;
        bool mIsMine;
        int mNumNeighborMines;
        // float mSideLength;
    public:
        Cell(int s=25, bool isMine=false, string path=TEXTURE_PATHS[UNCHECKED]);
        bool& isMine();
        int& numMines();
        // string& texturePath();
};

#endif