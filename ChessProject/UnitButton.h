#pragma once

#include "Command.h"

class UnitButton : public Command
{
public:
	UnitButton(int coord);

	virtual void execute();

	void onVisibleButton();
	
private:
	int _coord;
};