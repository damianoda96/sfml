#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <../platformArray.h>
#include <../collectibleArray.h>
#include <iostream>
#include <string>

struct Player
{
    //Create Player
    sf::Vector2f playerSize;
    sf::RectangleShape playerRect;

    float playerSpeed;
    float playerRightAcc;
    float playerLeftAcc;

    bool canJump;
    bool isJumping;
    bool isFalling;
    bool onPlatform;
    bool canMoveRight;
    bool canMoveLeft;

    Player();

    void Jump();
    void moveRight(float);
    void moveLeft(float);
    void checkCollision(platformArray, collectibleArray);

    float getPlayerTop();
    float getPlayerBottom();
    float getPlayerRight();
    float getPlayerLeft();

    sf::Text scoreText;
    sf::Text healthText;
    sf::Font font;

    void addScore();
    void loseScore();

    void loseHealth();
    void addHealth();

    private:

        int playerScore;
        int playerHealth;
};

#endif // PLAYER_H_INCLUDED
