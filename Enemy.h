#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Player.h"

struct Enemy
{
    //Create Enemy
    sf::Vector2f enemySize;
    sf::RectangleShape enemyRect;

    Enemy();

    float getEnemyTop();
    float getEnemyBottom();
    float getEnemyLeft();
    float getEnemyRight();

    bool checkCollision(Player);

};

#endif // ENEMY_H_INCLUDED
