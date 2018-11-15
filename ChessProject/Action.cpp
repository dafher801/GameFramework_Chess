#include "Action.h"

bool Action::init()
{
	if (!(SDL_Init(SDL_INIT_EVERYTHING) >= 0))
		return false;

	return true;
}

void Action::update()
{
}

void Action::draw()
{
}

void Action::setTarget(Object * target)
{
	_target = target;
}

Object * Action::getTarget() const
{
	return _target;
}

Action::Action()
	: _target(nullptr) {}