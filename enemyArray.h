#ifndef ENEMYARRAY_H_INCLUDED
#define ENEMYARRAY_H_INCLUDED

#include "gameArrays.h"
#include <iostream>
#include <vector>
#include "Enemy.h"

struct enemyArray : gameArrays, std::vector<Enemy>
{
    using std::vector<Enemy>::vector;
};


#endif // ENEMYARRAY_H_INCLUDED
