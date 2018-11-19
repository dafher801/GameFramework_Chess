#pragma once

#include "Command.h"
#include "Unit.h"

class UnitSelect : public Command
{
public:
	UnitSelect(Unit * unit);

	virtual void execute();

	void onVisibleButton();
	
private:
	Unit * _unit;
};