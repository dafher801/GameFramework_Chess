#pragma once

#include "Unit.h"

#include <map>

class UnitManager
{
public:
	static UnitManager * getInstance();

	std::map<int, Unit*>& getUnits();

	Unit * searchUnitByCoord(int key);

private:
	UnitManager() {}

	static UnitManager * _instance;

	std::map<int, Unit*> _units;
};