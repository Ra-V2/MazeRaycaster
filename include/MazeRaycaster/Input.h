#pragma once

#include "Player.h"

class Input
{
public:
    Input();
    ~Input();

    bool init(Player* p);
    void keyPressed(int key, int action);

    bool showMap;
private:
    Player* player;
};