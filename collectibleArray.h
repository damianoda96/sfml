#ifndef COLLECTIBLEARRAY_H_INCLUDED
#define COLLECTIBLEARRAY_H_INCLUDED

#include "gameArrays.h"
#include <iostream>
#include <vector>
#include "Collectible.h"

struct collectibleArray : gameArrays, std::vector<Collectible>
{
    using std::vector<Collectible>::vector;
};

#endif // COLLECTIBLEARRAY_H_INCLUDED
