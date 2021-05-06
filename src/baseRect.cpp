/**
 * @file baseRect.cpp
 * @author Kevin Wing, Caleb Simmons, Connor McElroy
 * @brief BaseRect class definitions
 * @date 2021-05-05
 */
#include "baseRect.h"

// BaseRect::BaseRect(int x, int y, string path)
// {
//     mRectWidth = x;
//     mRectHeight = y;
//     mTexturePath = path;
//     mTexture.loadFromFile(ASSET_DIR + mTexturePath);
//     mRect.setSize(sf::Vector2f(mRectWidth, mRectHeight));
//     mRect.setTexture(&mTexture);
// }

sf::Texture& BaseRect::getTexture()
{
    return mTexture;
}

// void BaseRect::setRectTexture(string path)
// {
//     mTexturePath = path;
//     mTexture.loadFromFile(ASSET_DIR + mTexturePath);
//     mRect.setTexture(&mTexture);
// }

sf::RectangleShape& BaseRect::getShape()
{
    return mRect;
}

string& BaseRect::texturePath()
{
    return mTexturePath;
}

int& BaseRect::rectWidth()
{
    return mRectWidth;
}

int& BaseRect::rectHeight()
{
    return mRectHeight;
}