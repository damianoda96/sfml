#include <SFML/Graphics.hpp>
#include <../Collectible.h>

Collectible::Collectible()
{
    //Create Collectible
    collectibleSize.x = 25.f;
    collectibleSize.y = 25.f;
    collectibleRect.setSize(collectibleSize);
    collectibleRect.setOutlineThickness(2);
    collectibleRect.setOutlineColor(sf::Color::White);
    collectibleRect.setFillColor(sf::Color::Yellow);
    collectibleRect.setOrigin(collectibleSize / 2.f);
}

float Collectible::getCollectibleTop()
{
    return(collectibleRect.getPosition().y - collectibleSize.y/2.f);
}

float Collectible::getCollectibleBottom()
{
    return(collectibleRect.getPosition().y + collectibleSize.y/2.f);
}

float Collectible::getCollectibleLeft()
{
    return(collectibleRect.getPosition().x - collectibleSize.x/2.f);
}

float Collectible::getCollectibleRight()
{
    return(collectibleRect.getPosition().x + collectibleSize.x/2.f);
}

bool Collectible::checkCollision(Player& player)
{
    if(player.getPlayerRight() >= this->getCollectibleLeft()
        && player.getPlayerLeft() <= this->getCollectibleRight()
        && player.getPlayerBottom() >= this->getCollectibleBottom()
        && player.getPlayerTop() <= this->getCollectibleTop())
    {
        return true;
    }
    else if(player.getPlayerRight() >= this->getCollectibleLeft()
        && player.getPlayerLeft() <= this->getCollectibleRight()
        && player.getPlayerBottom() >= this->getCollectibleTop()
        && player.getPlayerBottom() <= this->getCollectibleBottom())
    {
        return true;
    }
    else if(player.getPlayerRight() >= this->getCollectibleLeft()
        && player.getPlayerLeft() <= this->getCollectibleRight()
        && player.getPlayerTop() >= this->getCollectibleTop()
        && player.getPlayerTop() <= this->getCollectibleBottom())
    {
        return true;
    }

    return false;
}
