#pragma once
#include "Vector2f.h"
#include "Entity.h"

class Player : private Entity
{
public:
	Player();
	Player(float pX, float pY);
	~Player();

	bool init();

	void setPosition(float x, float y);

	void draw();
	void draw(float x, float y, int s);

	friend class Input;
	friend class Raycaster;

private:
	Vector2f position;
	Vector2f delta;

	int size;
	float angle;
};