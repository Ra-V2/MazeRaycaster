#pragma once

#include "Player.h"
#include "Input.h"
#include "Renderer.h"
#include "Map.h"
#include "Raycaster.h"

class Game
{
public:
	Game();
	~Game();

	bool init();
	bool run();
	void display();
	void update();

private:
	GLFWwindow* glfwWindow;
	Renderer* renderer;
	Input* input;
	Player* player;
	Map* map;
	Raycaster* raycaster;
};