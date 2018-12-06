#include "ActionManager.h"

ActionManager * ActionManager::_instance = nullptr;

ActionManager * ActionManager::getInstance()
{
	if (!_instance)
		_instance = new ActionManager;

	return _instance;
}

void ActionManager::update()
{
	for (std::vector<Action *>::iterator iter = _actions.begin();
		iter != _actions.end(); iter++)
	{
		if ((*iter)->isDone())
			(*iter)->update();
		else
			_actions.erase(iter);
	}
}

void ActionManager::addAction(Action * action, Object * object)
{
	_actions.push_back(action);
	action->setTarget(object);
}

std::vector<Action *> ActionManager::getActions() const
{
	return _actions;
}
