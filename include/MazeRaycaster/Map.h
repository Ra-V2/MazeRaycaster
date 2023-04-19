#pragma once

#include <vector>
#include "Vector2f.h"

class Map
{
public:
    Map();
    ~Map();

    bool init();
    void draw();

    friend class Raycaster;

private:
    int size;
    std::vector<std::vector<int>> map;
};