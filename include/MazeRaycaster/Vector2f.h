#pragma once

class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Vector2f& obj);
	~Vector2f();

	Vector2f operator+= (Vector2f& const obj);
	Vector2f operator-= (Vector2f& const obj);
	Vector2f operator- (Vector2f& const obj);
	Vector2f operator+ (Vector2f& const obj);

	float x;
	float y;
private:
};