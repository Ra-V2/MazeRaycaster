#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

Vector2f Entity::getPosition() const
{
	return position;
}
