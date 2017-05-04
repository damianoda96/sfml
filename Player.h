#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
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

    float wallJumpGrav;
    float fallingGrav;
    float gravity;

    bool canJump;
    bool canWallJump;
    bool isJumping;
    bool isWallJumping;
    bool isFalling;
    bool onPlatform;
    bool canMoveRight;
    bool canMoveLeft;

    Player();

    void jump(float);//, float&, float&);
    void fall(float);
    void wallJump(float);
    void moveRight(float);
    void hitMoveRight(float);
    void moveLeft(float);
    void hitMoveLeft(float);

    float getPlayerTop();
    float getPlayerBottom();
    float getPlayerRight();
    float getPlayerLeft();

    sf::Text scoreText;
    sf::Text healthText;
    sf::Font font;

    void addScore();
    void loseScore();
    void resetScore();
    int getPlayerScore();

    void loseHealth();
    void addHealth();
    void resetHealth();
    int getPlayerHealth();

    private:

        int playerHealth;
        int playerScore;
};

#endif // PLAYER_H_INCLUDED
