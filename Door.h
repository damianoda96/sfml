#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Player.h"

struct Door
{
    //Create Door
    sf::Vector2f doorSize;
    sf::RectangleShape doorRect;

    Door();

    float getDoorTop();
    float getDoorBottom();
    float getDoorLeft();
    float getDoorRight();

    bool checkCollision(Player);

};

#endif // DOOR_H_INCLUDED
