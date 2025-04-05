#pragma once
#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "cell.h"
#include <string>
#include <algorithm>

class hexagonmap
{
private:
    int radius;
    std::vector<std::vector<cell*>> cells;
public:
    hexagonmap();
    void printMap();
};