#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <string>
#include<sstream>

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


Player::Player()
{
    //Create Player
    playerSize.x = 25.f;
    playerSize.y = 100.f;
    playerRect.setSize(playerSize);
    playerRect.setOutlineThickness(2);
    playerRect.setOutlineColor(sf::Color::White);
    playerRect.setFillColor(sf::Color::Magenta);
    playerRect.setOrigin(playerSize / 2.f);

    playerSpeed = 400.f;
    playerRightAcc = 5.f;
    playerLeftAcc = 5.f;

    wallJumpGrav = 10.f;
    gravity = 10.f;
    fallingGrav = 1.f;

    canJump = true;
    canWallJump = false;
    isWallJumping = false;
    isJumping = false;
    isFalling = false;
    onPlatform = false;

    canMoveRight = true;
    canMoveLeft = true;

    playerScore = 0;

    playerHealth = 3;

    //std::string scoreString = std::to_string(0);

    if (!font.loadFromFile("resources/Anonymous_Pro.ttf"))
        printf("Cannot find font file!");

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(100.f, 100.f);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("SCORE:" + to_string(playerScore));

    healthText.setFont(font);
    healthText.setCharacterSize(30);
    healthText.setPosition(100.f, 100.f);
    healthText.setFillColor(sf::Color::Red);
    healthText.setString("Health:" + to_string(playerHealth));

}

void Player::jump(float deltaTime)//, float& gravity, float& fallingGrav)
{
    if(!isWallJumping)
    {
        playerRect.move(0.f, -playerSpeed * deltaTime - gravity);
        gravity-=1.f;
    }
}

void Player::fall(float deltaTime)
{
    if(!isWallJumping)
    {
        playerRect.move(0.f, (playerSpeed * deltaTime) + fallingGrav);
        fallingGrav+=.5;
    }
}

void Player::wallJump(float deltaTime)
{
    playerRect.move(0.f, -playerSpeed * deltaTime - wallJumpGrav);
    wallJumpGrav-=1.f;
}

void Player::moveLeft(float deltaTime)
{
    if(playerLeftAcc >= 0.f)
    {
        playerLeftAcc-=.3;
    }

    playerRect.move(-playerSpeed * deltaTime + playerLeftAcc, 0.f);
}

void Player::moveRight(float deltaTime)
{
    if(playerRightAcc >= 0.f)
    {
        playerRightAcc-=.3;
    }

    playerRect.move(playerSpeed * deltaTime - playerRightAcc, 0.f);
}

void Player::hitMoveLeft(float deltaTime)
{
    playerRect.move(-playerSpeed * deltaTime, 0.f);

}

void Player::hitMoveRight(float deltaTime)
{
    playerRect.move(playerSpeed * deltaTime, 0.f);
}


float Player::getPlayerTop()
{
    return (playerRect.getPosition().y - playerSize.y/2.f);
}

float Player::getPlayerBottom()
{
    return (playerRect.getPosition().y + playerSize.y/2.f);
}

float Player::getPlayerLeft()
{
    return (playerRect.getPosition().x - playerSize.x/2.f);
}

float Player::getPlayerRight()
{
    return (playerRect.getPosition().x + playerSize.x/2.f);
}

void Player::addScore()
{
    playerScore += 10;
    scoreText.setString("SCORE:"+to_string(playerScore));
}

void Player::loseScore()
{
    playerScore -= 10;
    scoreText.setString("SCORE:"+to_string(playerScore));
}
void Player::resetScore()
{
    playerScore = 0;
    scoreText.setString("SCORE:"+to_string(playerScore));
}

int Player::getPlayerScore()
{
    return playerScore;
}

void Player::addHealth()
{
    playerHealth++;
    healthText.setString("HEALTH:"+to_string(playerHealth));
}

void Player::loseHealth()
{
    playerHealth--;
    healthText.setString("HEALTH:"+to_string(playerHealth));
}
void Player::resetHealth()
{
    playerHealth = 1;
    healthText.setString("HEALTH:"+to_string(playerHealth));
}

int Player::getPlayerHealth()
{
    return playerHealth;
}




