#ifndef LEVELSWITCHER_HPP_INCLUDED
#define LEVELSWITCHER_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "platformArray.h"
#include "collectibleArray.h"
#include "enemyArray.h"

void levelSwitcher(int level, const int gameWidth, const int gameHeight, Player& player, platformArray& platforms, collectibleArray& collectibles, enemyArray& enemies)
{
    switch(level)
    {
        case 0 :
            break;

        case 1 :
            //Reset player Position
            player.playerRect.setPosition(gameWidth/2, gameHeight/2);

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
                break;

        case 2 :
            break;

        default :
            break;

    }

}

#endif // LEVELSWITCHER_HPP_INCLUDED
