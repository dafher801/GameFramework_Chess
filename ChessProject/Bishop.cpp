#include "Bishop.h"
#include "Chess.h"
#include "Board.h"

Bishop::Bishop(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id) {}

Bishop * Bishop::create(int coord, NAME name, TEAM team)
{
	Bishop * bishop = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		bishop = new Bishop(coord, "assets/images/BlackBishop.png", "BlackBishop");
		break;
	case Unit::TEAM::WHITE:
		bishop = new Bishop(coord, "assets/images/WhiteBishop.png", "WhiteBishop");
		break;
	}

	if (bishop && bishop->init())
	{
		bishop->_team = team;
		bishop->_name = name;
		return bishop;
	}
	else
	{
		delete bishop;
		bishop = nullptr;
		return bishop;
	}
}

bool Bishop::init()
{
	if (!Unit::init())
	{
		return false;
	}

	return true;
}

void Bishop::update()
{
	Unit::update();
}

void Bishop::draw()
{
	Unit::draw();
}

void Bishop::onVisibleButton()
{
	if (Chess::getInstance()->getNowTurn() == _team)
	{
		onVisibleRightHigh(_team);
		onVisibleRightLow(_team);
		onVisibleLeftLow(_team);
		onVisibleLeftHigh(_team);
	}
}

void Bishop::onVisibleRightHigh(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x + 1, j = y + 1;
		i < LENGTH && j < LENGTH &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i++, j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && j < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Bishop::onVisibleRightLow(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x + 1, j = y - 1;
		i < LENGTH && j >= 0 &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i++, j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && j >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Bishop::onVisibleLeftLow(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x - 1, j = y - 1;
		i >= 0 && j >= 0 &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i--, j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && j >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Bishop::onVisibleLeftHigh(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x - 1, j = y + 1;
		i >= 0 && j < LENGTH &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i--, j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && j < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}
