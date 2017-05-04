#ifndef COLLECTIBLE_H_INCLUDED
#define COLLECTIBLE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Player.h"

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

    bool checkCollision(Player&);

};

#endif // COLLECTIBLE_H_INCLUDED
