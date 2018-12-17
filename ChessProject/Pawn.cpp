#include "Pawn.h"
#include "Chess.h"
#include "Board.h"

#include <string>

Pawn::Pawn(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id)
	, _moved(false) {}

Pawn * Pawn::create(int coord, NAME name, TEAM team)
{
	Pawn * pawn = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		pawn = new Pawn(coord, "assets/images/BlackPawn.png", "BlackPawn");
		break;
	case Unit::TEAM::WHITE:
		pawn = new Pawn(coord, "assets/images/WhitePawn.png", "WhitePawn");
		break;
	}

	if (pawn && pawn->init())
	{
		pawn->_team = team;
		pawn->_name = name;
		return pawn;
	}
	else
	{
		delete pawn;
		pawn = nullptr;
		return pawn;
	}
}

bool Pawn::init()
{
	if ( !Unit::init() )
	{
		return false;
	}

	return true;
}

void Pawn::update()
{
	Unit::update();
}

void Pawn::draw()
{
	Unit::draw();
}

void Pawn::onVisibleButton()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	int direction;
	Unit::TEAM nowTurn = Chess::getInstance()->getNowTurn();

	switch (nowTurn)
	{
	case BLACK:
		direction = 1;
		break;
	case WHITE:
		direction = -1;
		break;
	}

	onMoveButton(x, y, direction, nowTurn);
}

void Pawn::move(int coord)
{
	Unit::move(coord);
	_moved = true;
}

bool Pawn::isChecking() const
{
	int direction;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	switch (_team)
	{
	case BLACK:
		direction = 1;
		break;
	case WHITE:
		direction = -1;
		break;
	}

	if (x > 0 && Board::getInstance()->getPieces()[x - 1][y + direction]->getUnit() &&
		Board::getInstance()->getPieces()[x - 1][y + direction]->getUnit()->getTeam() != _team &&
		Board::getInstance()->getPieces()[x - 1][y + direction]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	if (x < LENGTH - 1 && Board::getInstance()->getPieces()[x + 1][y + direction]->getUnit() &&
		Board::getInstance()->getPieces()[x + 1][y + direction]->getUnit()->getTeam() != _team &&
		Board::getInstance()->getPieces()[x + 1][y + direction]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	return false;
}

void Pawn::onMoveButton(int x, int y, int direction, Unit::TEAM nowTurn)
{
	if (Board::getInstance()->getPieces()[x][y]->getUnit()->getTeam() == nowTurn &&
		!Board::getInstance()->getPieces()[x][y + (1 * direction)]->getUnit())
	{
		Board::getInstance()->getPieces()[x][y + (1 * direction)]
			->getMoveButton()->setVisible(true);

		if (!_moved && !Board::getInstance()->getPieces()[x][y + (2 * direction)]->getUnit())
		{
			Board::getInstance()->getPieces()[x][y + (2 * direction)]
				->getMoveButton()->setVisible(true);
		}
	}

	if (Board::getInstance()->getPieces()[x][y]->getUnit()->getTeam() == nowTurn)
	{
		if (x > 0 && Board::getInstance()->getPieces()[x - 1][y + direction]->getUnit() &&
			Board::getInstance()->getPieces()[x - 1][y + direction]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x - 1][y + direction]->getMoveButton()->setVisible(true);
		}

		/*if (x > 0 &&
			trace->_unitTrace._unitInfo[_coord._x - 1][_coord._y - 1]._unit == PAWN &&
			trace->_unitTrace._unitInfo[_coord._x - 1][_coord._y - 1]._team != nowTurn)
		{
			button->GetAttackButton(_coord._x - 1, _coord._y - 1)->setVisible(true);
		}*/

		if (x < LENGTH - 1 &&
			Board::getInstance()->getPieces()[x + 1][y + direction]->getUnit() &&
			Board::getInstance()->getPieces()[x + 1][y + direction]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x + 1][y + direction]->getMoveButton()->setVisible(true);
		}

		/*if (_coord._x < _boardLength - 1 &&
			trace->_unitTrace._unitInfo[_coord._x + 1][_coord._y - 1]._unit == PAWN &&
			trace->_unitTrace._unitInfo[_coord._x + 1][_coord._y - 1]._team != nowTurn)
		{
			button->GetAttackButton(_coord._x + 1, _coord._y - 1)->setVisible(true);
		}*/
	}
}
