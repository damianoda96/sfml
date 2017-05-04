#include <SFML/Graphics.hpp>
#include "Platform.h"

Platform::Platform()
{
    //Create Platform
    //platformSize.x = 100.f;
    //platformSize.y = 25.f;
    //platformRect.setSize(platformSize);
    platformRect.setOutlineThickness(2);
    platformRect.setOutlineColor(sf::Color::White);
    platformRect.setFillColor(sf::Color::Blue);
    //platformRect.setOrigin(platformSize / 2.f);
}

float Platform::getPlatformTop()
{
    return(platformRect.getPosition().y - platformSize.y/2.f);
}

float Platform::getPlatformBottom()
{
    return(platformRect.getPosition().y + platformSize.y/2.f);
}

float Platform::getPlatformLeft()
{
    return(platformRect.getPosition().x - platformSize.x/2.f);
}

float Platform::getPlatformRight()
{
    return(platformRect.getPosition().x + platformSize.x/2.f);
}

//THIS IS USED TO SET ITEMS ON TOP OF PLATFORMS

sf::Vector2f Platform::getPosition()
{
    sf::Vector2f vect(platformRect.getPosition().x, platformRect.getPosition().y - 50);
    return vect;
}



void Platform::checkVertCollision(Player& player, float deltaTime) //float& fallingGrav, float& gravity, float deltaTime)
{
    /////////////////////////IF WE HIT THE TOP OF A PLATFORM////////////////////////////////
    if((player.getPlayerBottom() > this->getPlatformTop())
        && (player.getPlayerBottom() < this->getPlatformBottom())
        && (player.getPlayerRight() >= this->getPlatformLeft())
        && (player.getPlayerLeft() <= this->getPlatformRight()))
            {
                player.onPlatform = true;
                player.isJumping = false;
                player.isFalling = false;
                player.isWallJumping = false;
                player.wallJumpGrav = 10.f;
                player.fallingGrav = 1.f;
                player.gravity = 10.f;
                player.playerRect.setPosition(player.playerRect.getPosition().x, this->getPlatformTop() - player.playerSize.y/2 - 2.f);
                player.canWallJump = false;
                player.canJump = true;
                player.canMoveRight = true;
            }

            ////////////////////////////IF WE HIT THE BOTTOM OF A PLATFORM///////////////////////////

    if((player.getPlayerTop() <= this->getPlatformBottom())
        && (player.getPlayerBottom() >= this->getPlatformTop())
        && (player.getPlayerRight() >= this->getPlatformLeft())
        && (player.getPlayerLeft() <= this->getPlatformRight()))
        {
            player.gravity = -10.f;
            player.playerRect.move(0.f, -1 * deltaTime - player.gravity);
            player.gravity-=1.f;
        }
    ///////////////////////////////////////////////////////////////////////////////////////
}

void Platform::checkHorizCollision(Player& player)
{
    ///////////////////////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE RIGHT////////////////////////////

    if((player.getPlayerRight() >= this->getPlatformLeft() - 5.f)
        && (player.getPlayerRight() < this->getPlatformLeft() + 10.f)
        && (player.getPlayerTop() < this->getPlatformBottom())
        && (player.getPlayerLeft() < this->getPlatformLeft())
        && (player.getPlayerBottom() >= this->getPlatformBottom()
            || player.getPlayerBottom() >= this->getPlatformTop() ))
    {
        player.canMoveRight = false;
        player.playerRect.setPosition(this->getPlatformLeft() - player.playerSize.x/2.f - 2.f, player.playerRect.getPosition().y);
        if(!player.onPlatform)
        {
            player.canWallJump = true;
        }
    }
    else if((player.getPlayerTop() > this->getPlatformBottom()
        && player.getPlayerBottom() > this->getPlatformBottom())
        || (player.getPlayerBottom() < this->getPlatformTop()
            && player.getPlayerTop() < this->getPlatformTop()))
    {
        player.canMoveRight = true;
    }

    ///////////////////////////////IF PLAYER HITS THE SIDE OF A BLOCK FROM THE LEFT////////////////////////////

    if((player.getPlayerLeft() <= this->getPlatformRight() + 5.f)
        && (player.getPlayerLeft() > this->getPlatformRight() - 10.f)
        && (player.getPlayerTop() < this->getPlatformBottom())
        && (player.getPlayerRight() > this->getPlatformRight())
        && (player.getPlayerBottom() >= this->getPlatformBottom()
            || player.getPlayerBottom() >= this->getPlatformTop() ))
    {
        player.canMoveLeft = false;
        player.playerRect.setPosition(this->getPlatformRight() + player.playerSize.x/2.f + 2.f, player.playerRect.getPosition().y);
        if(!player.onPlatform)
        {
            player.canWallJump = true;
        }
    }
    else if((player.getPlayerTop() > this->getPlatformBottom()
        && player.getPlayerBottom() > this->getPlatformBottom())
        || (player.getPlayerBottom() < this->getPlatformTop()
            && player.getPlayerTop() < this->getPlatformTop()))
    {
        player.canMoveLeft = true;
        //player.canWallJump = false;
    }
}

void Platform::checkOnPlat(Player& player)
{
    if((player.getPlayerBottom() >= this->getPlatformTop() - 2.f)
        && (player.getPlayerBottom() <= this->getPlatformBottom())
        && (player.getPlayerLeft() <= this->getPlatformRight())
        && (player.getPlayerRight() >= this->getPlatformLeft()))
    {
        player.onPlatform = true;
    }
    else
    {
        player.onPlatform = false;
    }
}


