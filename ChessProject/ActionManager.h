#pragma once

class ActionManager
{
public:
	static ActionManager * getInstance();

private:
	ActionManager();

	static ActionManager * _instance;
};