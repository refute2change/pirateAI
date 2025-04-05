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

struct QRS
{
    int q, r, s;
    QRS(int q, int r, int s): q(q), r(r), s(s) {}
    QRS() = default;
};

struct IJ
{
    int i, j;
    IJ(int i, int j): i(i), j(j) {}
    IJ() = default;
};

class coordinates
{
public:
    static QRS IJtoQRS(int i, int j, int radius)
    {
        int q = j + std::max(-radius, -(i + radius));
        int r = i - radius;
        int s = -q - r;
        return QRS(q, r, s);
    }

    static IJ qrsToIJ(int q, int r, int radius)
    {
        int i = r + radius;
        int j = q - std::max(-radius, -(r + radius));
        return IJ(i, j);
    }
};
