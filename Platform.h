#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Player.h"

struct Platform
{
    //Create Platform
    sf::Vector2f platformSize;
    sf::RectangleShape platformRect;

    Platform();

    float getPlatformTop();
    float getPlatformBottom();
    float getPlatformLeft();
    float getPlatformRight();

    sf::Vector2f getPosition();

    void checkVertCollision(Player&, float);//float&, float&, float);
    void checkHorizCollision(Player&);

    void checkOnPlat(Player&);
};

#endif // PLATFORM_H_INCLUDED
