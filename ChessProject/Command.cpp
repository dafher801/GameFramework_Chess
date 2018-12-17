#include "Board.h"
#include "Command.h"

void Command::execute()
{
	int i, j;

	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(false);
}
