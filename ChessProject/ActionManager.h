#pragma once

#include "Action.h"

#include <vector>

class ActionManager
{
public:
	static ActionManager * getInstance();

	void update();

	void addAction(Action * action);

private:
	ActionManager() {}

	static ActionManager * _instance;

	std::vector<Action*> _actions;
};