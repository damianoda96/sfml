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

bool Enemy::checkCollision(Player player)
{
     if((player.getPlayerRight() >= this->getEnemyLeft() - 5.f)
        && (player.getPlayerRight() < this->getEnemyLeft() + 10.f)
        && (player.getPlayerTop() < this->getEnemyBottom())
        && (player.getPlayerLeft() < this->getEnemyLeft())
        && (player.getPlayerBottom() >= this->getEnemyBottom()
            || player.getPlayerBottom() >= this->getEnemyTop() ))
    {
        return true;
    }

        ///////////////////////////////IF PLAYER HITS THE SIDE OF A ENEMY FROM THE LEFT////////////////////////////
        if((player.getPlayerLeft() <= this->getEnemyRight() + 5.f)
            && (player.getPlayerLeft() > this->getEnemyRight() - 10.f)
            && (player.getPlayerTop() < this->getEnemyBottom())
            && (player.getPlayerRight() > this->getEnemyRight())
            && (player.getPlayerBottom() >= this->getEnemyBottom()
                || player.getPlayerBottom() >= this->getEnemyTop() ))
        {
            return true;
        }

        if(player.getPlayerRight() >= this->getEnemyLeft()
            && player.getPlayerLeft() <= this->getEnemyRight()
            && player.getPlayerBottom() >= this->getEnemyTop()
            && player.getPlayerBottom() <= this->getEnemyBottom())
        {
            return true;
        }
        else if(player.getPlayerRight() >= this->getEnemyLeft()
            && player.getPlayerLeft() <= this->getEnemyRight()
            && player.getPlayerTop() >= this->getEnemyTop()
            && player.getPlayerTop() <= this->getEnemyBottom())
        {
            return true;
        }

        return false;

                     /*//FIX THIS, WE NEED SMOOTH HIT MOVEMENT FOR PLAYER
                    ///////////////////////////////HIT ENEMY FROM RIGHT////////////

                    if((player.getPlayerRight() >= first->getEnemyLeft() - 5.f)
                        && (player.getPlayerRight() < first->getEnemyLeft() + 10.f)
                        && (player.getPlayerTop() < first->getEnemyBottom())
                        && (player.getPlayerLeft() < first->getEnemyLeft())
                        && (player.getPlayerBottom() >= first->getEnemyBottom()
                            || player.getPlayerBottom() >= first->getEnemyTop() ))
                    {
                        player.canMoveRight = false;
                        while(player.getPlayerRight() >= first->getEnemyLeft() - 50.f)
                        {
                            player.hitMoveLeft(deltaTime);

                        }
                        player.loseHealth();
                        break;
                    }
                    else if((player.getPlayerTop() > first->getEnemyBottom()
                        && player.getPlayerBottom() > first->getEnemyBottom())
                        || (player.getPlayerBottom() < first->getEnemyTop()
                            && player.getPlayerTop() < first->getEnemyTop()))
                    {
                        player.canMoveRight = true;
                    }

                    ///////////////////////////////IF PLAYER HITS THE SIDE OF A ENEMY FROM THE LEFT////////////////////////////

                    if((player.getPlayerLeft() <= first->getEnemyRight() + 5.f)
                        && (player.getPlayerLeft() > first->getEnemyRight() - 10.f)
                        && (player.getPlayerTop() < first->getEnemyBottom())
                        && (player.getPlayerRight() > first->getEnemyRight())
                        && (player.getPlayerBottom() >= first->getEnemyBottom()
                            || player.getPlayerBottom() >= first->getEnemyTop() ))
                    {
                        player.canMoveLeft = false;
                        while(player.getPlayerLeft() <= first->getEnemyRight() + 50.f)
                        {
                            player.hitMoveRight(deltaTime);
                        }
                        player.loseHealth();
                        break;
                    }
                    else if((player.getPlayerTop() > first->getEnemyBottom()
                            && player.getPlayerBottom() > first->getEnemyBottom())
                            || (player.getPlayerBottom() < first->getEnemyTop()
                                && player.getPlayerTop() < first->getEnemyTop()))
                    {
                        player.canMoveLeft = true;
                    }

                    if(player.getPlayerRight() >= first->getEnemyLeft()
                       && player.getPlayerLeft() <= first->getEnemyRight()
                       && player.getPlayerBottom() >= first->getEnemyTop()
                       && player.getPlayerBottom() <= first->getEnemyBottom())
                    {
                        if(player.getPlayerHealth() > 1)
                        {
                            player.loseHealth();
                        }
                        else
                        {
                            player.loseHealth();
                            gameOver = true;
                            isPlaying = false;
                            break;
                        }
                    }
                    else if(player.getPlayerRight() >= first->getEnemyLeft()
                       && player.getPlayerLeft() <= first->getEnemyRight()
                       && player.getPlayerTop() >= first->getEnemyTop()
                       && player.getPlayerTop() <= first->getEnemyBottom())
                    {
                        if(player.getPlayerHealth() > 1)
                        {
                            gravity = -10.f;
                            player.playerRect.move(0.f, -playerSpeed * deltaTime - gravity);
                            gravity-=1.f;
                            player.loseHealth();
                            break;
                        }
                        else
                        {
                            player.loseHealth();
                            gameOver = true;
                            isPlaying = false;
                            break;
                        }
                    }
                    else
                    {
                        first++;
                    }*/

}
