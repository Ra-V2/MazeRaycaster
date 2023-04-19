#pragma once

#include "Player.h"
#include "Map.h"

#include <vector>

class Raycaster
{
public:
	Raycaster();
	~Raycaster();

	bool init(Player* p, Map* m);

	void castRays();
	void drawMap();
	void drawGame();

private:
	Player* player;
	Map* map;
	std::vector<Vector2f> rays;
	std::vector<int> raysSide;
	std::vector<float> raysAngle;
};