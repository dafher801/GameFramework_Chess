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

std::vector<Unit*>& UnitManager::getUnits()
{
	return _units;
}

Unit * UnitManager::searchUnitByCoord(int key)
{
	for (std::vector<Unit *>::iterator iter = _units.begin();
		iter != _units.end(); iter++)
	{
		if (key == (*iter)->getCoord())
			return *iter;
	}

	return nullptr;
}

void UnitManager::DeleteUnit(Unit * unit)
{
	for (std::vector<Unit *>::iterator iter = _units.begin();
		iter != _units.end(); iter++)
	{
		if (*iter == unit)
		{
			_units.erase(iter);
			break;
		}
	}
}
