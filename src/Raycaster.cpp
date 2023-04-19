#include "Raycaster.h"

#include <ctype.h>
#include <iostream>
#include <iterator>
#include <cmath>
#include <GLFW/glfw3.h>

#define M_PI 3.1415926
#define RAD 0.0174533

Raycaster::Raycaster()
	: player(NULL), map(NULL), rays(NULL)
{
}

Raycaster::~Raycaster()
{
}

bool Raycaster::init(Player* p, Map* m)
{
	player = p;
	map = m;
	rays.resize(512);
	raysSide.resize(512);
	raysAngle.resize(512);

	return true;
}

void Raycaster::castRays()
{
	Vector2f playerDir;
	Vector2f playerBox;
	Vector2f rayDelta;
	Vector2f rayDir;
	Vector2f rayPos;

	for (int i = 0; i < 512; i++)
	{
		float fov = i - 256;
		float step = 0;
		int range = 0;
		int side = 0; // 0 - X axis, 1 - Y axis

		rayDir = Vector2f(cos(player->angle + fov / 500), sin(player->angle + fov / 500));

		if (abs(rayDir.x) > abs(rayDir.y))
			step = abs(rayDir.x);
		else
			step = abs(rayDir.y);

		rayDir.x /= step;
		rayDir.y /= step;

		rayPos = player->position;

		while (range < 12)
		{
			Vector2f toTheEdge;
			if (rayDir.x > 0) // right edge
			{
				toTheEdge.x = map->size - (rayPos.x - int(rayPos.x) / map->size * map->size);
			}
			else //left edge
			{
				if (int(rayPos.x) % map->size == 0)
					rayPos.x -= 0.0001f;

				toTheEdge.x = -(rayPos.x - int(rayPos.x) / map->size * map->size);
			}

			if (rayDir.y > 0) //down edge
			{
				toTheEdge.y = map->size - (rayPos.y - int(rayPos.y) / map->size * map->size);
			}
			else //up edge
			{
				if (int(rayPos.y) % map->size == 0)
					rayPos.y -= 0.0001f;

				toTheEdge.y = -(rayPos.y - int(rayPos.y) / map->size * map->size);
			}

			Vector2f toEdgeVectorX;
			Vector2f toEdgeVectorY;
			toEdgeVectorX = Vector2f(toTheEdge.x, abs(toTheEdge.x / rayDir.x) * rayDir.y);
			toEdgeVectorY = Vector2f(abs(toTheEdge.y / rayDir.y) * rayDir.x, toTheEdge.y);

			//compare which edge we hit first
			if (toEdgeVectorX.x * toEdgeVectorX.x + toEdgeVectorX.y * toEdgeVectorX.y < 
				toEdgeVectorY.x * toEdgeVectorY.x + toEdgeVectorY.y * toEdgeVectorY.y)
			{
				rayPos += toEdgeVectorX; //move the ray to the X edge
				if (toEdgeVectorY.x < 0)
					rayPos.x -= 0.0001f; //isn't on edge
				side = 0;
			}
			else
			{
				rayPos += toEdgeVectorY; //move the ray to the Y edge
				if (toEdgeVectorY.y < 0)
					rayPos.y -= 0.0001f; //isn't on edge
				side = 1;
			}

			int rayBlockX = (rayPos.x / map->size);
			int rayBlockY = (rayPos.y / map->size);

			try {
				if (map->map.at(rayBlockY).at(rayBlockX) == 1)
					break;
			}
			catch (const std::out_of_range& d)
			{
				std::cout << "Vector out of range error!" << std::endl;
			}
			range++;
		}

		rays[i] = Vector2f(rayPos.x, rayPos.y);
		raysSide[i] = side;
		raysAngle[i] = atan2(rayDir.y, rayDir.x);
	}
}

void Raycaster::drawMap()
{
	int i = 0;
	for (Vector2f ray : rays)
	{
		glColor3f(1, 1, 0);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2f(player->position.x, player->position.y);
		glVertex2f(ray.x, ray.y);
		glEnd();
	}

}

void Raycaster::drawGame()
{
	std::vector<Vector2f>::iterator rayPtr;

	for (rayPtr = rays.begin(); rayPtr < rays.end(); rayPtr++)
	{
		float cosAngle = player->angle - raysAngle[rayPtr-rays.begin()];

		if (cosAngle < 0)
			cosAngle += 2 * M_PI;
		if (cosAngle > 2 * M_PI)
			cosAngle -= 2 * M_PI;

		Vector2f rayDir = *rayPtr - player->position;
		float rayLength = sqrt(rayDir.x * rayDir.x + rayDir.y * rayDir.y) * cos(cosAngle);

		if (rayLength <= 0.1f)
			rayLength = 0.0001f;

		float lineHeight = (1024 * 8) / rayLength;
		float lineOffset = 512 - lineHeight / 2;

		if (lineHeight > 1024) {
			lineHeight = 1024;
			lineOffset = 0;
		}
		if (raysSide[rayPtr - rays.begin()] == 0)
			glColor3f(0.7f, 0.7f, 0);
		else
			glColor3f(1, 1, 0);


		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2f(int(rayPtr - rays.begin()) * 2, lineOffset);
		glVertex2f(int(rayPtr - rays.begin()) * 2, lineHeight + lineOffset);
		glEnd();
	}
}
