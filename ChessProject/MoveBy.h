#pragma once

#include"Action.h"

class MoveBy : public Action
{
public:
	static MoveBy * create(float duration, const Vector2D& vec);

	virtual bool init();
	virtual void update();
	virtual void draw();

private:
	MoveBy();

	float _duration;
	Vector2D _vec;
};