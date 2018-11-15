#pragma once

#include "Object.h"

class Action
{
public:
	virtual bool init();
	virtual void update();
	virtual void draw();

	void setTarget(Object * target);
	Object * getTarget() const;

protected:
	Action();

	Object * _target;
};