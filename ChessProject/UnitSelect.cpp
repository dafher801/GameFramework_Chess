#include "Board.h"
#include "UnitSelect.h"
#include "UnitManager.h"
#include "Chess.h"
#include "PromotionManager.h"

UnitSelect::UnitSelect(Unit * unit)
	: _unit(unit) {}

void UnitSelect::execute()
{
	if (Chess::getInstance()->getCheckmate()->isVisible() ||
		Chess::getInstance()->getStalemate()->isVisible() ||
		PromotionManager::getInstance()->getPromotionMenu()->isVisible())
	{
		return;
	}

	int i, j;
	Command::execute();

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->isSelected())
			iter->offSelected();
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
		Board::getInstance()->hash(targetCoord)->getMoveButton()->setVisible(false);
}

bool UnitSelect::CheckBySimulation(int targetCoord)
{
	bool isChecked = false;

	Unit * start = Board::getInstance()->hash(_unit->getCoord())->getUnit();
	Unit * target = Board::getInstance()->hash(targetCoord)->getUnit();

	Board::getInstance()->hash(targetCoord)->setUnit(start);
	Board::getInstance()->hash(_unit->getCoord())->setUnit(nullptr);

	Chess::getInstance()->changeTurn();

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter != target && iter->getTeam() != start->getTeam() && iter->isChecking())
		{
			isChecked = true;
			break;
		}
	}

	Chess::getInstance()->changeTurn();

	Board::getInstance()->hash(_unit->getCoord())->setUnit(start);
	Board::getInstance()->hash(targetCoord)->setUnit(target);

	return isChecked;
}
