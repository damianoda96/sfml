#ifndef DOORARRAY_H_INCLUDED
#define DOORARRAY_H_INCLUDED

#include "gameArrays.h"
#include <iostream>
#include <vector>
#include "Door.h"

struct doorArray : gameArrays, std::vector<Door>
{
    using std::vector<Door>::vector;
};

#endif // DOORARRAY_H_INCLUDED
