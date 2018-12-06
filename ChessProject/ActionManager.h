#pragma once

#include "Action.h"

#include <vector>

class ActionManager
{
public:
	static ActionManager * getInstance();

	void update();

	void addAction(Action * action, Object * object);

	std::vector<Action *> getActions() const;

private:
	ActionManager() {}

	static ActionManager * _instance;

	std::vector<Action *> _actions;
};