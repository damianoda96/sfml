#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <SFML/Graphics.hpp>

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

};

#endif // ENEMY_H_INCLUDED
