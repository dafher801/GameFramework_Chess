#include "Board.h"
#include "UnitButton.h"

UnitButton::UnitButton(int coord)
	: _coord(coord) {}

void UnitButton::execute()
{
	int i, j;

	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(false);
			Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(false);
		}
	}

	onVisibleButton();
}

void UnitButton::onVisibleButton()
{
	Board::getInstance()->getPieces()[_coord / 10 - 1][_coord % 10 - 1]
		->getUnit()->onVisibleButton();
}
