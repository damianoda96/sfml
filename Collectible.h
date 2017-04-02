#ifndef COLLECTIBLE_H_INCLUDED
#define COLLECTIBLE_H_INCLUDED

#include <SFML/Graphics.hpp>

struct Collectible
{
    //Create Platform
    sf::Vector2f collectibleSize;
    sf::RectangleShape collectibleRect;

    Collectible();

    float getCollectibleTop();
    float getCollectibleBottom();
    float getCollectibleLeft();
    float getCollectibleRight();

};

#endif // COLLECTIBLE_H_INCLUDED
