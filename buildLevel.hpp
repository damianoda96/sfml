#ifndef BUILDLEVEL_HPP_INCLUDED
#define BUILDLEVEL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "platformArray.h"
#include "collectibleArray.h"
#include "enemyArray.h"
#include "doorArray.h"

void buildLevel(int level, const int gameWidth, const int gameHeight, Player& player, platformArray& platforms, collectibleArray& collectibles, enemyArray& enemies, doorArray& doors)
{
    Platform platform;
    Platform platformVert;
    Collectible collectible;
    Enemy enemy;
    Door door;


    sf::Vector2f platformSize(100.f, 25.f);
    platform.platformSize = platformSize;

    sf::Vector2f platformSizeVert(25.f, 200.f);
    platformVert.platformSize = platformSizeVert;

    platform.platformRect.setSize(platformSize);
    platform.platformRect.setOrigin(platformSize/2.f);

    platformVert.platformRect.setSize(platformSizeVert);
    platformVert.platformRect.setOrigin(platformSizeVert/2.f);

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

                if(platforms.size() == 8)
                {
                    platforms.push_back(platformVert);
                    printf("PLATFORMS CREATED\n");
                    break;
                }
            }

            //CREATE OUR COLLECTIBLES/////////////////////
            while(true)
            {
                collectibles.push_back(collectible);

                if(collectibles.size() == 3)
                {
                    printf("COINS CREATED\n");
                    break;
                }

            }

            //CREATE LEVEL DOOR

            doors.push_back(door);

            printf("DOOR CREATED\n");

            ///////////////////POSITION OBJECTS///////////////
            player.playerRect.setPosition(gameWidth/2, gameHeight/2);

            ///////////////////////////SET PLATFORM POSITIONS/////////////////////////////////////////
            for(std::size_t first = 0; first < platforms.size(); first++)
            {
                if(first < 5)
                {
                    platforms[first].platformRect.setPosition(gameWidth/2 + (first * 100), gameHeight/2 + 100.f);
                }
                else if(first >= 5 && first <= 7)
                {
                    platforms[first].platformRect.setPosition(gameWidth/2 + (first * 200) - 400, gameHeight/2 - (first * 50) + 300);
                }
                else
                {
                    platforms[first].platformRect.setPosition(gameWidth/2 - 50, gameHeight/2);
                }
            }
            //////////////////////////SET COLLECTIBLE POSITIONS//////////////////////////////////////////////////////////////

            collectibles[0].collectibleRect.setPosition(platforms[4].getPosition());
            collectibles[1].collectibleRect.setPosition(platforms[5].getPosition());
            collectibles[2].collectibleRect.setPosition(platforms[6].getPosition());

            //SET DOOR POSITION

            doors[0].doorRect.setPosition(platforms[7].platformRect.getPosition().x, gameHeight/2 - 120);

            break;

        case 2:
            ////////////CREATE OBJECTS//////////////////////////////////
            //CREATE OUR PLATFORMS////////////////////////
            while(true)
            {
                platforms.push_back(platform);

                if(platforms.size() == 20)
                {
                    printf("PLATFORMS CREATED\n");
                    break;
                }
            }

            //CREATE OUR COLLECTIBLES/////////////////////
            while(true)
            {
                collectibles.push_back(collectible);

                if(collectibles.size() == 3)
                {
                    printf("COINS CREATED\n");
                    break;
                }

            }

            //CREATE OUR ENEMIES////////////////
            while(true)
            {
                enemies.push_back(enemy);

                if(enemies.size() == 1)
                {
                    printf("ENEMIES CREATED\n");
                    break;
                }

            }
            //CREATE LEVEL DOOR
            doors.push_back(door);
            printf("DOOR CREATED\n");

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
                    platforms[first].platformRect.setPosition(gameWidth/2 + (first * 200) - 300, gameHeight/2 - (first * 50) + 200);
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

            doors[0].doorRect.setPosition(gameWidth/2 + 300.f, gameHeight/2 - 100.f);

            break;

        default:
            break;
    }

}

#endif // BUILDLEVEL_HPP_INCLUDED
