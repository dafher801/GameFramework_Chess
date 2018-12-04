#pragma once

class Object;

class Action
{
public:
	Action();

	virtual bool init();
	virtual void update() = 0;
	virtual bool isDone() = 0;

	void setTarget(Object * target);
	Object * getTarget() const;

protected:
	Object * _target;
};