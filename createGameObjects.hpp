#ifndef CREATEGAMEOBJECTS_HPP_INCLUDED
#define CREATEGAMEOBJECTS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "platformArray.h"
#include "collectibleArray.h"
#include "enemyArray.h"

void createGameObjects(int level, platformArray& platforms, collectibleArray& collectibles, enemyArray& enemies)
{
    Platform platform;
    Collectible collectible;
    Enemy enemy;

    //CREATE OUR PLATFORMS////////////////////////
    while(true)
    {
        platforms.push_back(platform);

        if(platforms.size() == 7)
        {
            printf("platforms created");
            break;
        }
    }

    //CREATE OUR COLLECTIBLES/////////////////////
    while(true)
    {
        collectibles.push_back(collectible);

        if(collectibles.size() == 3)
        {
            printf("coins created");
            break;
        }

    }

    //CREATE OUR ENEMIES////////////////
    while(true)
    {
        enemies.push_back(enemy);

        if(enemies.size() == 1)
        {
            printf("enemy created");
            break;
        }

    }
}
#endif // CREATEGAMEOBJECTS_HPP_INCLUDED
