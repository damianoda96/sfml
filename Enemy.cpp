#include <SFML/Graphics.hpp>
#include "Enemy.h"

Enemy::Enemy()
{
    //Create Enemy
    enemySize.x = 25.f;
    enemySize.y = 25.f;
    enemyRect.setSize(enemySize);
    enemyRect.setOutlineThickness(2);
    enemyRect.setOutlineColor(sf::Color::White);
    enemyRect.setFillColor(sf::Color::Red);
    enemyRect.setOrigin(enemySize / 2.f);
}

float Enemy::getEnemyTop()
{
    return(enemyRect.getPosition().y - enemySize.y/2.f);
}

float Enemy::getEnemyBottom()
{
    return(enemyRect.getPosition().y + enemySize.y/2.f);
}

float Enemy::getEnemyLeft()
{
    return(enemyRect.getPosition().x - enemySize.x/2.f);
}

float Enemy::getEnemyRight()
{
    return(enemyRect.getPosition().x + enemySize.x/2.f);
}
