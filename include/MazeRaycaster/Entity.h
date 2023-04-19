#pragma once
#include "Vector2f.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool init() = 0;

	virtual void setPosition(float x, float y);
	virtual Vector2f getPosition() const;

private:
	Vector2f position;

};