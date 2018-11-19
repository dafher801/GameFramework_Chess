#include "MoveTo.h"
#include "Chess.h"

MoveTo::MoveTo(float duration, const Vector2D & position)
	: _duration(duration), _position(position)
{
	_duration = duration * DELAY_TIME;
}

MoveTo * MoveTo::create(float duration, const Vector2D & position)
{
	MoveTo * action = new MoveTo(duration, position);

	if (action && action->init())
	{
		return action;
	}
	else
	{
		delete action;
		action = nullptr;
		return nullptr;
	}
}

bool MoveTo::init()
{
	if (!Action::init())
		return false;

	_velocity = (_position - _target->getPosition()) / _duration;

	return true;
}

void MoveTo::update()
{
	_position += _velocity;
	_target->setPosition(_position.getX(), _position.getY());
	_duration -= DELAY_TIME;
}

bool MoveTo::isDone()
{
	return _duration > 0;
}
