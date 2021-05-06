/**
 * @file baseRect.cpp
 * @author Kevin Wing, Caleb Simmons, Connor McElroy
 * @brief BaseRect class definitions
 * @date 2021-05-05
 */
#include "baseRect.h"

/**
 * @brief returns reference to the mTexture object
 * 
 * @return sf::Texture& mTexture ref
 */
sf::Texture& BaseRect::getTexture()
{
    return mTexture;
}

/**
 * @brief get reference to the sf::RectangleShape member object
 * 
 * @return sf::RectangleShape& mRect object ref
 */
sf::RectangleShape& BaseRect::getShape()
{
    return mRect;
}

/**
 * @brief return reference to the texture path string
 * 
 * @return string& path string ref
 */
string& BaseRect::texturePath()
{
    return mTexturePath;
}

/**
 * @brief returns reference to mRectWidth int
 * 
 * @return int& mRectWidth ref
 */
int& BaseRect::rectWidth()
{
    return mRectWidth;
}

/**
 * @brief returns reference to mRectHeight
 * 
 * @return int& mRectHeight ref
 */
int& BaseRect::rectHeight()
{
    return mRectHeight;
}