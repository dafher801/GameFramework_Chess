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
						return;
					}
				}
			}
		}
	}
}
