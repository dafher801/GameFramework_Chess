#include "MoveBy.h"

MoveBy * MoveBy::create(float duration, const Vector2D & vec)
{
	MoveBy * moveBy = new MoveBy();

	if (moveBy && moveBy->init())
	{
		return moveBy;
	}
	else
	{
		delete moveBy;
		moveBy = nullptr;
		return nullptr;
	}
}

bool MoveBy::init()
{
	if (!Action::init())
		return false;

	return true;
}

void MoveBy::update()
{
}

void MoveBy::draw()
{
}
