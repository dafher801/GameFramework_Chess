#include "Board.h"
#include "UnitSelect.h"
#include "UnitManager.h"

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
	int x = targetCoord / 10 - 1;
	int y = targetCoord % 10 - 1;
	int i = _unit->getCoord() / 10 - 1;
	int j = _unit->getCoord() % 10 - 1;

	if (CheckBySimulation(targetCoord))
	{
		Board::getInstance()->getPieces()[x][y]->getMoveButton()->setVisible(false);
	}
}

bool UnitSelect::CheckBySimulation(int targetCoord)
{
	int x = targetCoord / 10 - 1;
	int y = targetCoord % 10 - 1;
	int i = _unit->getCoord() / 10 - 1;
	int j = _unit->getCoord() % 10 - 1;

	Unit * king = nullptr;

	Board::getInstance()->getPieces()[x][y]->setUnit(_unit);
	Board::getInstance()->getPieces()[i][j]->setUnit(nullptr);

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->getName() == Unit::NAME::KING && iter->getTeam() == _unit->getTeam())
		{
			king = iter;
			break;
		}
	}

	return false;
}
