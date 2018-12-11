#include "Board.h"
#include "UnitMove.h"
#include "UnitManager.h"

UnitMove::UnitMove(Button * button)
	: _button(button) {}

void UnitMove::execute()
{
	int i, j;
	Command::execute();

	for (std::vector<Unit *>::iterator iter = UnitManager::getInstance()->getUnits().begin();
		iter != UnitManager::getInstance()->getUnits().end(); iter++)
	{
		if ((*iter)->isSelected())
		{
			for (i = 0; i < LENGTH; i++)
			{
				for (j = 0; j < LENGTH; j++)
				{
					if (Board::getInstance()->getPieces()[i][j]->getMoveButton() == _button)
					{
						(*iter)->move((i + 1) * 10 + j + 1);

						/*int x = (*iter)->getCoord() / 10 - 1;
						int y = (*iter)->getCoord() % 10 - 1;

						if (Board::getInstance()->getPieces()[i][j]->getUnit())
							delete Board::getInstance()->getPieces()[i][j]->getUnit();

						Board::getInstance()->getPieces()[x][y]->setUnit(nullptr);
						Board::getInstance()->getPieces()[i][j]->setUnit(*iter);

						Board::getInstance()->getPieces()[i][j]
							->getUnit()->setCoord((i + 1) * 10 + j + 1);

						MoveTo * moveTo = MoveTo::create(2, _button->getPosition());
						(*iter)->runAction(moveTo);*/
					}
				}
			}
		}
	}
}
