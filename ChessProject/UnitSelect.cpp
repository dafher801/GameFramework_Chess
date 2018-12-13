#include "Board.h"
#include "UnitSelect.h"
#include "UnitManager.h"
#include "Chess.h"

UnitSelect::UnitSelect(Unit * unit)
	: _unit(unit) {}

void UnitSelect::execute()
{
	int i, j;
	Command::execute();

	for (std::vector<Unit *>::iterator iter = UnitManager::getInstance()->getUnits().begin();
		iter != UnitManager::getInstance()->getUnits().end(); iter++)
	{
		if ((*iter)->isSelected())
			(*iter)->offSelected();
	}

	_unit->onSelected();
	_unit->onVisibleButton();
	
	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
			if (Board::getInstance()->getPieces()[i][j]->getMoveButton()->isVisible())
			{
				ExceptButton((i + 1) * 10 + j + 1);
			}
}

void UnitSelect::ExceptButton(int targetCoord)
{
	if (CheckBySimulation(targetCoord))
	{
		Board::getInstance()->hash(targetCoord)->getMoveButton()->setVisible(false);
	}
}

bool UnitSelect::CheckBySimulation(int targetCoord)
{
	Board::getInstance()->hash(targetCoord)->setUnit(_unit);
	Board::getInstance()->hash(_unit->getCoord())->setUnit(nullptr);

	//Chess::getInstance()->changeTurn();

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->isChecking())
		{
			Board::getInstance()->hash(_unit->getCoord())->setUnit(_unit);
			Board::getInstance()->hash(targetCoord)->setUnit(nullptr);
			return true;
		}
	}

	Board::getInstance()->hash(_unit->getCoord())->setUnit(_unit);
	Board::getInstance()->hash(targetCoord)->setUnit(nullptr);
	return false;
}
