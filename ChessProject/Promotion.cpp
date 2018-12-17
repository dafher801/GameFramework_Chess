#include "PromotionManager.h"
#include "Promotion.h"
#include "UnitManager.h"
#include "Chess.h"
#include "Board.h"
#include "Unit.h"

Promotion::Promotion(int unitInfo)
	: _unitInfo(unitInfo) {}

void Promotion::execute()
{
	int unit = _unitInfo % 4 + 1;
	int team = _unitInfo / 4;

	Command::execute();

	Board::getInstance()->hash(PromotionManager::getInstance()->
		getPromotionPawn()->getCoord())->makeUnit((Unit::NAME)unit, (Unit::TEAM)team);

	PromotionManager::getInstance()->offPromotion();

	if (Chess::getInstance()->gameOver())
	{
		for (Unit * iter : UnitManager::getInstance()->getUnits())
		{
			if (iter->isChecking())
				Chess::getInstance()->getCheckmate()->setVisible(true);
		}

		Chess::getInstance()->getStalemate()->setVisible(true);
	}
}
