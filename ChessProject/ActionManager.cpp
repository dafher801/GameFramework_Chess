#include "ActionManager.h"

ActionManager * ActionManager::getInstance()
{
	if (!_instance)
		_instance = new ActionManager;

	return _instance;
}
