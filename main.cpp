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
#include "buildLevel.hpp"
#include "Door.h"
#include "doorArray.h"
#include <iostream>
#include <string>
#include<sstream>

//THIS IS A FIX FOR TO.STRING()
template <typename T>
std::string to_string(T value)
{
    //create an output string stream
    std::ostringstream os ;

    //throw the value into the string stream
    os << value ;

    //convert the string stream into a string and return
    return os.str() ;
}

int main()
{
    //Game Constants
    const int gameWidth = 800;
    const int gameHeight = 600;

    //GAME LEVEL
    int level = 1;

    //Create the application window
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "My Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    //Initialize view
    sf::View viewport(sf::Vector2f(400, 300), sf::Vector2f(gameWidth, gameHeight));


    //Initialize Menu
    Menu mainMenu;

    //Physics
    float playerSpeed = 400.f;
    //float gravity = 10.f;
    //float fallingGrav = 1.f;

    Player player;

    platformArray platforms;
    collectibleArray collectibles;
    enemyArray enemies;
    doorArray doors;

    //Clock
    sf::Clock clock;

    bool isPlaying = false;
    bool gameOver  = false;
    bool nextLevel = false;

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

            // Tab key pressed:
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Tab))
            {
                if(!isPlaying)
                {
                    //CREATE OBJECTS AND PLACE OBJECTS DEPENDING ON LEVEL
                    buildLevel(level, gameWidth, gameHeight, player, platforms, collectibles, enemies, doors);

                    //RESTART GAME//////////////////////
                    isPlaying = true;
                    gameOver = false;
                    clock.restart();

                    //RESET PLAYER SCORE AND HEALTH////////////////
                    player.resetHealth();
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

            if(player.getPlayerHealth() < 1)
            {
                gameOver = true;
                isPlaying = false;
            }

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

            //RESTART GAME WHEN R IS PRESSED//////////////////////////
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                player.isJumping = false;
                player.isFalling = false;
                isPlaying = false;
                viewport.setCenter(400, 300);
                window.setView(viewport);
                platforms.clear();
                collectibles.clear();
                enemies.clear();
            }

            /////////////////////PLAYER/PLATFORM HORIZONTAL COLLISION AND ONPLATFORM CHECKS//////////////////////////

            for(std::size_t i = 0; i <= platforms.size(); i++)
            {
                platforms[i].checkHorizCollision(player);

                platforms[i].checkOnPlat(player);
            }

            /////////////////////////JUMPING///////////////////////////////////////////////////

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(player.canJump)
                {
                    player.canJump = false;
                    player.isJumping = true;
                }

                if(player.canWallJump)
                {
                    std::cout << "JUMP";
                    player.isJumping = false;
                    player.isFalling = false;
                    player.canWallJump = false;
                    player.isWallJumping = true;
                }

            }

            if(!player.onPlatform && !player.isJumping && !player.isWallJumping)
            {
                player.isFalling = true;
                player.canJump = false;

            }

            /////////////////////////////////////////IF WE ARE JUMPING////////////////////////////////////////////////////

            if(!player.canJump)
            {
                if(player.isJumping)
                {
                    player.jump(deltaTime);
                }

                if(player.isWallJumping)
                {
                    player.wallJump(deltaTime);
                }

                if(player.isFalling)
                {
                    player.fall(deltaTime);
                }



                //CHECK FOR VERTICAL COLLISION BETWEEN PLAYER AND PLATFORM
                for(std::size_t i = 0; i <= platforms.size(); i++)
                {
                    platforms[i].checkVertCollision(player, deltaTime);//fallingGrav, gravity, deltaTime);
                }
            }

            ///////////////////////////////////////END OF JUMPING///////////////////////////////////////////

            ///////////////PLAYER/COLLECTIBLE COLLISION///////////////

            if(collectibles.size() > 0)
            {
                collectibleArray::iterator first = collectibles.begin();
                int counter = 0;

                while(first != collectibles.end())
                {

                    if(collectibles[counter].checkCollision(player))
                    {
                        collectibles.erase(first);
                        player.addScore();
                    }
                    else
                    {
                        first++;
                        counter++;
                    }
                }
            }

            ///////////////PLAYER/ENEMY COLLISION///////////////

            if(enemies.size() > 0)
            {
                enemyArray::iterator first = enemies.begin();

                while(first != enemies.end())
                {
                    if(first->checkCollision(player))
                    {
                        player.loseHealth();
                        gameOver = true;
                        isPlaying = false;
                        nextLevel = false;
                        break;
                    }
                    else
                    {
                        first++;
                    }
                }
            }

            //PLAYER/DOOR COLLISION///////////////////////////
            //IF ALL COINS COLLECTED AND W IS PRESSED WHILE COLLIDING WITH DOOR, GO TO NEXT LEVEL!

            if(doors[0].checkCollision(player) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && collectibles.size() == 0)
            {
                isPlaying = false;
                nextLevel = true;
                level++;
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
            for(std::size_t first = 0; first < enemies.size(); first++)
            {
                window.draw(enemies[first].enemyRect);
            }

            window.draw(doors[0].doorRect);
        }
        else if(!isPlaying && !gameOver && !nextLevel) //draw pause screen
        {
            window.draw(mainMenu.titleText);
        }
        else if(!isPlaying && !gameOver && nextLevel)
        {
            //IF WE MOVE TO NEXT LEVEL
            viewport.setCenter(400,300);
            window.setView(viewport);
            mainMenu.levelText.setString("LEVEL " + to_string(level));
            window.draw(mainMenu.levelText);
            platforms.clear();
            collectibles.clear();
            enemies.clear();
            doors.clear();
        }
        else if(!isPlaying && gameOver && !nextLevel)
        {
            //IF GAME OVER
            window.draw(mainMenu.gameOverText);
            player.resetScore();
            platforms.clear();
            collectibles.clear();
            enemies.clear();
            doors.clear();
        }

        //display things on the screen
        window.display();

    }

    return 0;
}
