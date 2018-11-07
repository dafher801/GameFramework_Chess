#pragma once

#include <math.h>

class Vector2D
{
public:
	Vector2D() {}
	Vector2D(float x, float y);

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);

	Vector2D operator+(const Vector2D& v2) const;
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);

	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);

	Vector2D operator-(const Vector2D& v2) const;
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);

	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);

	float getLength() const;
	void normalize();

private:
	float _x;
	float _y;
};

struct Rect
{
	Vector2D _coord;
	Vector2D _length;
};