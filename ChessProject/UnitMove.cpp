#include "Board.h"
#include "UnitMove.h"

UnitMove::UnitMove(Button * button)
	: _button(button) {}

void UnitMove::execute()
{
	int i, j;

	Command::execute();

	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < LENGTH; j++)
		{
			if (Board::getInstance()->getPieces()[i][j]->getUnit() &&
				Board::getInstance()->getPieces()[i][j]->getUnit()->isSelected())
			{
				MoveTo * moveTo = MoveTo::create(2, _button->getPosition());
				Board::getInstance()->getPieces()[i][j]->getUnit()->runAction(moveTo);
			}
		}
	}
}
