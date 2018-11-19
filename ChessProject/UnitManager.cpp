#include "UnitManager.h"
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

UnitManager * UnitManager::_instance = nullptr;

UnitManager * UnitManager::getInstance()
{
	if (!_instance)
		_instance = new UnitManager;

	return _instance;
}

std::map<int, Unit*>& UnitManager::getUnits()
{
	return _units;
}

Unit * UnitManager::searchUnitByCoord(int key)
{
	return _units[key];
}
