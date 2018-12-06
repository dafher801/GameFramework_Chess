#include "MoveTo.h"
#include "Chess.h"
#include "ActionManager.h"

MoveTo::MoveTo(float duration, const Vector2D & position)
	: _duration(duration), _position(position), _operated(false)
{
	_duration = duration * DELAY_TIME;
}

MoveTo * MoveTo::create(float duration, const Vector2D & position)
{
	MoveTo * moveTo = new MoveTo(duration, position);

	if (moveTo && moveTo->init())
	{
		return moveTo;
	}
	else
	{
		delete moveTo;
		moveTo = nullptr;
		return nullptr;
	}
}

bool MoveTo::init()
{
	if (!Action::init())
		return false;

	return true;
}

void MoveTo::update()
{
	if (!_operated)
	{
		_operated = true;
		first();
	}

	_position += _velocity;
	_target->setPosition(_position.getX(), _position.getY());
	_duration -= DELAY_TIME;
}

bool MoveTo::isDone()
{
	return _duration > 0;
}

void MoveTo::first()
{
	_velocity = (_position - _target->getPosition()) / _duration;
}
