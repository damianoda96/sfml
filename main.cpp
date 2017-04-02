#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Menu.h"
#include "platformArray.h"
#include "Collectible.h"
#include "collectibleArray.h"
#include "Enemy.h"
#include "enemyArray.h"
#include "createGameObjects.hpp"

int main()
{
    //Game Constants
    const int gameWidth = 800;
    const int gameHeight = 600;

    //GAME LEVEL
    int level = 0;

    //Create the application window
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "My Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    //Initialize view
    sf::View viewport(sf::Vector2f(400, 300), sf::Vector2f(800, 600));

    //Initialize Menu
    Menu mainMenu;

    //SCORE COUNTER
    int score = 0;

    //Physics
    float playerSpeed = 400.f;
    float gravity = 10.f;
    float fallingGrav = 1.f;

    Player player;

    platformArray platforms;
    collectibleArray collectibles;
    enemyArray enemies;

    //CREATES OUR GAME OBJECTS
    createGameObjects(level, platforms, collectibles, enemies);

    //Clock
    sf::Clock clock;

    bool isPlaying = false;

    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Space key pressed:
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Tab))
            {
                if(!isPlaying)
                {
                    //restart Game
                    isPlaying = true;
                    clock.restart();

                    //Reset player Position
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
                }
            }
        }

        ////////////////////////////GAME LOOP///////////////////////////////////////////////////////////////////
        if(isPlaying)
        {
            viewport.setCenter(player.playerRect.getPosition().x, player.playerRect.getPosition().y);
            window.setView(viewport);

            player.scoreText.setPosition(player.playerRect.getPosition().x - 350.f, player.playerRect.getPosition().y - 250.f);
            player.healthText.setPosition(player.playerRect.getPosition().x + 225.f, player.playerRect.getPosition().y -250.f);

            float deltaTime = clock.restart().asSeconds();

            /////////////////////SIDEWAYS MOVEMENT///////////////////////////////////////////////

            //RIGHT MOVEMENT//////////////////

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if(player.canMoveRight)
                {
                    player.moveRight(deltaTime);
                }
                else
                {
                    player.playerRightAcc = 5.f;
                }
            }
            else
            {
                //PLAYER DECELERATION AFTER D IS RELEASED
                if(player.playerRightAcc < 5.f)
                {
                    player.playerRightAcc += .6;
                    player.playerRect.move(playerSpeed * deltaTime - player.playerRightAcc, 0.f);
                }
            }

            //LEFT MOVEMENT////////////////

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if(player.canMoveLeft)
                {
                    player.moveLeft(deltaTime);
                }
                else
                {
                    player.playerLeftAcc = 5.f;
                }
            }
            else
            {
                //PLAYER DECELERATION AFTER A IS RELEASED
                if(player.playerLeftAcc < 5.f)
                {
                    player.playerLeftAcc += .6;
                    player.playerRect.move(-playerSpeed * deltaTime + player.playerLeftAcc, 0.f);
                }
            }

            //RESTART GAME WHEN R IS PRESSED////
            //FIX THIS !!!//////

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                player.playerRect.setPosition(gameWidth/2, gameHeight/2 - 100.f);
            }


            /////////////////////IF WE ARENT JUMPING AND HIT THE SIDE OF A BLOCK//////////////////////////

            ///////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE RIGHT/////////////////////
            for(std::size_t i = 0; i <= platforms.size(); i++)
            {
                if((player.getPlayerRight() >= platforms[i].getPlatformLeft() - 5.f)
                    && (player.getPlayerRight() < platforms[i].getPlatformLeft() + 10.f)
                    && (player.getPlayerTop() < platforms[i].getPlatformBottom())
                    && (player.getPlayerLeft() < platforms[i].getPlatformLeft())
                    && (player.getPlayerBottom() >= platforms[i].getPlatformBottom()
                        || player.getPlayerBottom() >= platforms[i].getPlatformTop() ))
                {
                    player.canMoveRight = false;
                    player.playerRect.setPosition(platforms[i].getPlatformLeft() - player.playerSize.x/2.f - 2.f, player.playerRect.getPosition().y);
                    break;
                }
                else if((player.getPlayerTop() > platforms[i].getPlatformBottom()
                    && player.getPlayerBottom() > platforms[i].getPlatformBottom())
                    || (player.getPlayerBottom() < platforms[i].getPlatformTop()
                        && player.getPlayerTop() < platforms[i].getPlatformTop()))
                {
                    player.canMoveRight = true;
                }

                ///////////////////////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE LEFT////////////////////////////

                if((player.getPlayerLeft() <= platforms[i].getPlatformRight() + 5.f)
                    && (player.getPlayerLeft() > platforms[i].getPlatformRight() - 10.f)
                    && (player.getPlayerTop() < platforms[i].getPlatformBottom())
                    && (player.getPlayerRight() > platforms[i].getPlatformRight())
                    && (player.getPlayerBottom() >= platforms[i].getPlatformBottom()
                        || player.getPlayerBottom() >= platforms[i].getPlatformTop() ))
                {
                    player.canMoveLeft = false;
                    player.playerRect.setPosition(platforms[i].getPlatformRight() + player.playerSize.x/2.f + 2.f, player.playerRect.getPosition().y);
                    break;
                }
                else if((player.getPlayerTop() > platforms[i].getPlatformBottom()
                        && player.getPlayerBottom() > platforms[i].getPlatformBottom())
                        || (player.getPlayerBottom() < platforms[i].getPlatformTop()
                            && player.getPlayerTop() < platforms[i].getPlatformTop()))
                {
                    player.canMoveLeft = true;
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////

            /////////////////////////JUMPING///////////////////////////////////////////////////

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(player.canJump)
                {
                    player.canJump = false;
                    player.isJumping = true;
                }
            }

            if(!player.onPlatform)
            {
                player.isFalling = true;
                player.canJump = false;
            }

            //////////////////////IF WE ARE ON A PLATFORM//////////////////////////////////////////

            for(std::size_t i = 0; i <= platforms.size(); i++)
            {
                if((player.getPlayerBottom() >= platforms[i].getPlatformTop() - 2.f)
                    && (player.getPlayerBottom() <= platforms[i].getPlatformBottom())
                    && (player.getPlayerLeft() <= platforms[i].getPlatformRight())
                    && (player.getPlayerRight() >= platforms[i].getPlatformLeft()))
                {
                    player.onPlatform = true;
                    break;
                }
                else
                {
                    player.onPlatform = false;
                }
            }

            /////////////////////////////////////////IF WE ARE JUMPING////////////////////////////////////////////////////

            if(!player.canJump)
            {
                if(player.isJumping == true)
                {
                    player.playerRect.move(0.f, -playerSpeed * deltaTime - gravity);
                    gravity-=1.f;
                }
                else if(player.isFalling == true)
                {
                    player.playerRect.move(0.f, (player.playerSpeed * deltaTime) + fallingGrav);
                    fallingGrav+=.5;

                }
                //check collision between player and platform
                for(std::size_t i = 0; i <= platforms.size(); i++)
                {
                    ///////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE RIGHT/////////////////////

                    /*if((player.getPlayerRight() >= platforms[i].getPlatformLeft() - 5.f)
                        && (player.getPlayerRight() < platforms[i].getPlatformLeft() + 5.f)
                        && (player.getPlayerTop() < platforms[i].getPlatformBottom())
                        && (player.getPlayerLeft() < platforms[i].getPlatformLeft())
                        && (player.getPlayerBottom() >= platforms[i].getPlatformBottom()
                            || player.getPlayerBottom() >= platforms[i].getPlatformTop() ))
                    {
                        player.canMoveRight = false;
                        player.playerRect.setPosition(platforms[i].getPlatformLeft() - player.playerSize.x/2.f - 2.f, player.playerRect.getPosition().y);
                        //break;
                    }
                    else if((player.getPlayerTop() > platforms[i].getPlatformBottom()
                            && player.getPlayerBottom() > platforms[i].getPlatformBottom())
                            || (player.getPlayerBottom() < platforms[i].getPlatformTop()
                                && player.getPlayerTop() < platforms[i].getPlatformTop()))
                    {
                        player.canMoveRight = true;
                    }

                    ///////////////////////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE LEFT////////////////////////////

                    if((player.getPlayerLeft() <= platforms[i].getPlatformRight() + 5.f)
                        && (player.getPlayerLeft() > platforms[i].getPlatformRight() - 5.f)
                        && (player.getPlayerTop() < platforms[i].getPlatformBottom())
                        && (player.getPlayerRight() > platforms[i].getPlatformRight())
                        && (player.getPlayerBottom() >= platforms[i].getPlatformBottom()
                            || player.getPlayerBottom() >= platforms[i].getPlatformTop() ))
                    {
                        player.canMoveLeft = false;
                        player.playerRect.setPosition(platforms[i].getPlatformRight() + player.playerSize.x/2.f + 2.f, player.playerRect.getPosition().y);
                        //break;
                    }
                    else if((player.getPlayerTop() > platforms[i].getPlatformBottom()
                            && player.getPlayerBottom() > platforms[i].getPlatformBottom())
                            || (player.getPlayerBottom() < platforms[i].getPlatformTop()
                                && player.getPlayerTop() < platforms[i].getPlatformTop()))
                    {
                        player.canMoveLeft = true;
                    }*/

                    /////////////////////////IF WE HIT THE TOP OF A PLATFORM////////////////////////////////

                    if((player.getPlayerBottom() > platforms[i].getPlatformTop())
                        && (player.getPlayerBottom() < platforms[i].getPlatformBottom())
                        && (player.getPlayerRight() >= platforms[i].getPlatformLeft())
                        && (player.getPlayerLeft() <= platforms[i].getPlatformRight()))
                    {
                        player.onPlatform = true;
                        player.isJumping = false;
                        player.isFalling = false;
                        fallingGrav = 1.f;
                        gravity = 10.f;
                        player.playerRect.setPosition(player.playerRect.getPosition().x, platforms[i].getPlatformTop() - player.playerSize.y/2 - 2.f);
                        player.canJump = true;
                        player.canMoveRight = true;
                        break;
                    }

                    ////////////////////////////IF WE HIT THE BOTTOM OF A PLATFORM///////////////////////////

                    if((player.getPlayerTop() <= platforms[i].getPlatformBottom())
                        && (player.getPlayerBottom() >= platforms[i].getPlatformTop())
                        && (player.getPlayerRight() >= platforms[i].getPlatformLeft())
                        && (player.getPlayerLeft() <= platforms[i].getPlatformRight()))
                    {
                        gravity = -10.f;
                        player.playerRect.move(0.f, -playerSpeed * deltaTime - gravity);
                        gravity-=1.f;
                        break;
                    }

                    ///////////////////////////////////////////////////////////////////////////////////////
                }

            }

            ///////////////////////////////////////END OF JUMPING///////////////////////////////////////////

            ///////////////PLAYER/COLLECTIBLE COLLISION///////////////
            if(collectibles.size() > 0)
            {
                collectibleArray::iterator first = collectibles.begin();

                while(first != collectibles.end())
                {
                    if(player.getPlayerRight() >= first->getCollectibleLeft()
                       && player.getPlayerLeft() <= first->getCollectibleRight()
                       && player.getPlayerBottom() >= first->getCollectibleBottom()
                       && player.getPlayerTop() <= first->getCollectibleTop())
                    {
                        collectibles.erase(first);
                        player.addScore();
                    }
                    else if(player.getPlayerRight() >= first->getCollectibleLeft()
                       && player.getPlayerLeft() <= first->getCollectibleRight()
                       && player.getPlayerBottom() >= first->getCollectibleTop()
                       && player.getPlayerBottom() <= first->getCollectibleBottom())
                    {
                        collectibles.erase(first);
                        player.addScore();
                    }
                    else if(player.getPlayerRight() >= first->getCollectibleLeft()
                       && player.getPlayerLeft() <= first->getCollectibleRight()
                       && player.getPlayerTop() >= first->getCollectibleTop()
                       && player.getPlayerTop() <= first->getCollectibleBottom())
                    {
                        collectibles.erase(first);
                        player.addScore();
                    }
                    else
                    {
                        first++;
                    }
                }
            }


        }

        /////////////////////////////END OF GAME LOOP////////////////////////////////////////////////////////////



        //clear the window
        window.clear();

        //if game is playing, draw game objects
        if(isPlaying)
        {
            window.draw(player.playerRect);
            window.draw(player.scoreText);
            window.draw(player.healthText);

            for(std::size_t first = 0; first < platforms.size(); first++)
            {
                window.draw(platforms[first].platformRect);
            }
            for(std::size_t first = 0; first < collectibles.size(); first++)
            {
                window.draw(collectibles[first].collectibleRect);
            }
        }
        else  //draw pause screen
        {
            window.draw(mainMenu.titleText);
        }

        //display things on the screen
        window.display();

    }

    return 0;
}