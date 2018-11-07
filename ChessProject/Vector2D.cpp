#include "Vector2D.h"

Vector2D::Vector2D(float x, float y)
	: _x(x), _y(y) {}

float Vector2D::getX() const
{
	return _x;
}

float Vector2D::getY() const
{
	return _y;
}

void Vector2D::setX(float x)
{
	_x = x;
}

void Vector2D::setY(float y)
{
	_y = y;
}

Vector2D Vector2D::operator+(const Vector2D & v2) const
{
	return Vector2D(_x + v2._x, _y + v2._y);
}

Vector2D & operator+=(Vector2D & v1, const Vector2D & v2)
{
	v1._x += v2._x;
	v1._y += v2._y;
	return v1;
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(_x * scalar, _y * scalar);
}

Vector2D & Vector2D::operator*=(float scalar)
{
	_x *= scalar;
	_y *= scalar;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D & v2) const
{
	return Vector2D(_x - v2._x, _y - v2._y);
}

Vector2D & operator-=(Vector2D & v1, const Vector2D & v2)
{
	v1._x -= v2._x;
	v1._y -= v2._y;
	return v1;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(_x / scalar, _y / scalar);
}

Vector2D & Vector2D::operator/=(float scalar)
{
	_x /= scalar;
	_y /= scalar;
	return *this;
}

float Vector2D::getLength() const
{
	return sqrt(_x * _x + _y * _y);
}

void Vector2D::normalize()
{
	float length = getLength();

	if (length > 0)
		*this *= 1 / length;
}