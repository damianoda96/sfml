#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include <SFML/Graphics.hpp>

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

};

#endif // PLATFORM_H_INCLUDED
