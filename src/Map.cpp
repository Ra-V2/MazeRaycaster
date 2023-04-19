#include "Map.h"

#include <GLFW/glfw3.h>

Map::Map()
    : size(32)
{
}

Map::~Map()
{
}

bool Map::init()
{
    map =
    {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };

    return true;
}

void Map::draw()
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == 1)
            {
                glColor3f(1, 1, 1);
            }
            else
            {
                glColor3f(0, 0, 0);
            }

            Vector2f mapSize(j * size, i * size);
            glRecti(mapSize.x, mapSize.y, mapSize.x + size, mapSize.y + size);
        }
    }
}
