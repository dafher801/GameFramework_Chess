#pragma once

#include "Action.h"
#include "Vector2D.h"

class MoveTo : public Action
{
public:
	static MoveTo * create(float duration, const Vector2D & position);

	virtual bool init();
	virtual void update();
	virtual bool isDone();

	void first();

private:
	MoveTo(float duration, const Vector2D & position);

	bool _operated;

	float _duration;
	Vector2D _position;
	Vector2D _velocity;
};