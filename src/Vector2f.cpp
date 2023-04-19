#include "Vector2f.h"

Vector2f::Vector2f()
	: x(0.0f), y(0.0f)
{
}

Vector2f::Vector2f(float x, float y)
	: x(x), y(y)
{
	
}

Vector2f::~Vector2f()
{
}

Vector2f::Vector2f(const Vector2f& obj)
{
	this->x = obj.x;
	this->y = obj.y;
}

Vector2f Vector2f::operator+=(Vector2f& const obj)
{
	this->x += obj.x;
	this->y += obj.y;

	return *this;
}

Vector2f Vector2f::operator-=(Vector2f& const obj)
{
	this->x += obj.x;
	this->y += obj.y;

	return *this;
}

Vector2f Vector2f::operator-(Vector2f& const obj)
{
	Vector2f vect;
	vect.x = this->x - obj.x;
	vect.y = this->y - obj.y;

	return vect;
}

Vector2f Vector2f::operator+(Vector2f& const obj)
{
	Vector2f vect;
	vect.x = this->x + obj.x;
	vect.y = this->y + obj.y;

	return vect;
}
