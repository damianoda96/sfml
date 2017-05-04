#include <SFML/Graphics.hpp>
#include "Door.h"

Door::Door()
{
    //Create Enemy
    doorSize.x = 25.f;
    doorSize.y = 100.f;
    doorRect.setSize(doorSize);
    doorRect.setOutlineThickness(2);
    doorRect.setOutlineColor(sf::Color::White);
    doorRect.setFillColor(sf::Color::Green);
    doorRect.setOrigin(doorSize / 2.f);
}

float Door::getDoorTop()
{
    return(doorRect.getPosition().y - doorSize.y/2.f);
}

float Door::getDoorBottom()
{
    return(doorRect.getPosition().y + doorSize.y/2.f);
}

float Door::getDoorLeft()
{
    return(doorRect.getPosition().x - doorSize.x/2.f);
}

float Door::getDoorRight()
{
    return(doorRect.getPosition().x + doorSize.x/2.f);
}

bool Door::checkCollision(Player player)
{
     if((player.getPlayerRight() >= this->getDoorLeft() - 5.f)
        && (player.getPlayerRight() < this->getDoorLeft() + 10.f)
        && (player.getPlayerTop() < this->getDoorBottom())
        && (player.getPlayerLeft() < this->getDoorLeft())
        && (player.getPlayerBottom() >= this->getDoorBottom()
            || player.getPlayerBottom() >= this->getDoorTop() ))
    {
        return true;
    }

    ///////////////////////////////IF PLAYER HITS THE SIDE OF A ENEMY FROM THE LEFT////////////////////////////
    if((player.getPlayerLeft() <= this->getDoorRight() + 5.f)
        && (player.getPlayerLeft() > this->getDoorRight() - 10.f)
        && (player.getPlayerTop() < this->getDoorBottom())
        && (player.getPlayerRight() > this->getDoorRight())
        && (player.getPlayerBottom() >= this->getDoorBottom()
            || player.getPlayerBottom() >= this->getDoorTop() ))
    {
        return true;
    }

    if(player.getPlayerRight() >= this->getDoorLeft()
        && player.getPlayerLeft() <= this->getDoorRight()
        && player.getPlayerBottom() >= this->getDoorTop()
        && player.getPlayerBottom() <= this->getDoorBottom())
    {
        return true;
    }
    else if(player.getPlayerRight() >= this->getDoorLeft()
        && player.getPlayerLeft() <= this->getDoorRight()
        && player.getPlayerTop() >= this->getDoorTop()
        && player.getPlayerTop() <= this->getDoorBottom())
    {
        return true;
    }

    return false;
}
