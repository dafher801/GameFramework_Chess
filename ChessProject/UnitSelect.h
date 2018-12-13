#pragma once

#include "Command.h"
#include "Unit.h"

class UnitSelect : public Command
{
public:
	UnitSelect(Unit * unit);

	virtual void execute();
	void ExceptButton(int targetCoord);
	bool CheckBySimulation(int targetCoord);
	
private:
	Unit * _unit;
};