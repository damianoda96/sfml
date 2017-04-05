#ifndef BUILDLEVEL_HPP_INCLUDED
#define BUILDLEVEL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "platformArray.h"
#include "collectibleArray.h"
#include "enemyArray.h"

void buildLevel(int level, const int gameWidth, const int gameHeight, Player& player, platformArray& platforms, collectibleArray& collectibles, enemyArray& enemies)
{
    Platform platform;
    Collectible collectible;
    Enemy enemy;

    switch(level)
    {
        case 0:
            break;

        case 1:
            ////////////CREATE OBJECTS//////////////////////////////////
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
            ///////////////////POSITION OBJECTS///////////////
            player.playerRect.setPosition(gameWidth/2, gameHeight/2);

            ///////////////////////////SET PLATFORM POSITIONS/////////////////////////////////////////
            for(std::size_t first = 0; first < platforms.size(); first++)
            {
                if(first < 5)
                {
                    platforms[first].platformRect.setPosition(gameWidth/2 + (first * 100), gameHeight/2 + 100.f); //+ (first * 50));
                }
                else
                {
                    platforms[first].platformRect.setPosition(gameWidth/2 + (first * 100) - 300, gameHeight/2 - (first * 50) + 200);
                }
            }
            //////////////////////////SET COLLECTIBLE POSITIONS//////////////////////////////////////////////////////////////
            for(std::size_t first = 0; first < collectibles.size(); first++)
            {
                if(first < 2)
                {
                    collectibles[first].collectibleRect.setPosition(gameWidth/2 + (first * 100) + 300, gameHeight/2 + 60.f);
                }
                else
                {
                    collectibles[first].collectibleRect.setPosition(gameWidth/2 + (first * 100) + 200, gameHeight/2 - 100.f);
                }

            }
            //////////////////////////SET ENEMY POSITIONS//////////////////////////////////////////////////////////////
            for(std::size_t first = 0; first < enemies.size(); first++)
            {
                enemies[first].enemyRect.setPosition(gameWidth/2 + (first * 100) + 100, gameHeight/2 - 100.f);
            }

        case 2:
            break;

        default:
            break;
    }

}

#endif // BUILDLEVEL_HPP_INCLUDED
