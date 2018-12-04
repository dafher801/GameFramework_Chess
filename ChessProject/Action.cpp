#include "Action.h"
#include "Object.h"

Action::Action()
	: _target(nullptr) {}

bool Action::init()
{
	if (!(SDL_Init(SDL_INIT_EVERYTHING) >= 0))
		return false;

	return true;
}

void Action::setTarget(Object * target)
{
	_target = target;
}

Object * Action::getTarget() const
{
	return _target;
}