#ifndef PLATFORMARRAY_H_INCLUDED
#define PLATFORMARRAY_H_INCLUDED

#include <iostream>
#include <vector>
#include "gameArrays.h"
#include "Platform.h"

struct platformArray : gameArrays, std::vector<Platform>
{
    using std::vector<Platform>::vector;
};

#endif // PLATFORMARRAY_H_INCLUDED
