#include "Input.h"

#include <iostream>
#include <GLFW/glfw3.h>

#define M_PI 3.1415926

Input::Input()
	: player(NULL), showMap(false)
{
}

Input::~Input()
{
}

bool Input::init(Player* p)
{
	player = p;

	return true;
}


void Input::keyPressed(int key, int action)
{
	if (action == GLFW_RELEASE)
		return;

	if (key == GLFW_KEY_W)
	{
		player->position.x += player->delta.x;
		player->position.y += player->delta.y;
	}

	if (key == GLFW_KEY_A)
	{
		player->angle -= 0.05f;
		if (player->angle < 0.0f)
			player->angle += 2 * M_PI;
		player->delta.x = cos(player->angle) * 2;
		player->delta.y = sin(player->angle) * 2;
	}

	if (key == GLFW_KEY_S)
	{
		player->position.x -= player->delta.x;
		player->position.y -= player->delta.y;
	}

	if (key == GLFW_KEY_D)
	{
		player->angle += 0.05f;
		if (player->angle > 0.0f)
			player->angle -= 2 * M_PI;
		player->delta.x = cos(player->angle) * 2;
		player->delta.y = sin(player->angle) * 2;
	}

	if (key == GLFW_KEY_M)
	{
		showMap = !showMap;
	}
}