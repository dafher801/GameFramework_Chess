#pragma once

#include "Unit.h"

#include <vector>

class UnitManager
{
public:
	static UnitManager * getInstance();

	std::vector<Unit*>& getUnits();

	Unit * searchUnitByCoord(int key);

	void DeleteUnit(Unit * unit);

private:
	UnitManager() {}

	static UnitManager * _instance;

	std::vector<Unit*> _units;
};