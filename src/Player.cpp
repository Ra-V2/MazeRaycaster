#include "Player.h"

#include <iostream>
#include <GLFW/glfw3.h>

Player::Player()
	: position(100.0f, 50.0f), delta(0.0f, 0.0f), size(10), angle(0.1f)
{
}

Player::Player(float pX, float pY)
	: position(100.0f, 50.0f), delta(0.0f, 0.0f), size(10), angle(0.1f)
{
}

Player::~Player()
{
}

bool Player::init()
{
	delta.x = cos(angle) * 4;
	delta.y = sin(angle) * 4;

	return true;
}

void Player::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Player::draw()
{
	glColor3f(1, 1, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(position.x, position.y);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(position.x, position.y);
	glVertex2i(position.x + delta.x*4, position.y + delta.y*4);
	glEnd();
}

void Player::draw(float x, float y, int s)
{
	position.x = x;
	position.y = y;
	size = s;

	glColor3f(1, 1, 0);
	glPointSize(s);
	glBegin(GL_POINTS);
	glVertex2i(position.x, position.y);
	std::cout << position.x << " " << position.y << std::endl;
	glEnd();
}
