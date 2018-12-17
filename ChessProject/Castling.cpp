#include "CastlingManager.h"
#include "Castling.h"
#include "Chess.h"
#include "Board.h"

Castling::Castling(int kingCoord, int rookCoord)
	: _kingCoord(kingCoord)
	, _rookCoord(rookCoord) {}

void Castling::execute()
{
	Unit * rook = Board::getInstance()->hash(_rookCoord)->getUnit();

	Command::execute();

	if (CastlingManager::getInstance()->castlingPosible())
	{
		if (_kingCoord > _rookCoord)
			_rookCoord += 30;
		else
			_rookCoord -= 20;

		rook->move(_rookCoord);
		Chess::getInstance()->changeTurn();
	}
}
