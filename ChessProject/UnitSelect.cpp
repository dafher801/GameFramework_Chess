#include "Board.h"
#include "UnitSelect.h"
#include "UnitManager.h"

UnitSelect::UnitSelect(Unit * unit)
	: _unit(unit) {}

void UnitSelect::execute()
{
	Command::execute();

	for (std::vector<Unit *>::iterator iter = UnitManager::getInstance()->getUnits().begin();
		iter != UnitManager::getInstance()->getUnits().end(); iter++)
	{
		if ((*iter)->isSelected())
			(*iter)->offSelected();
	}

	_unit->onSelected();
	_unit->onVisibleButton();
}
