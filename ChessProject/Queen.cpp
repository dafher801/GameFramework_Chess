#include "Queen.h"
#include "Chess.h"
#include "Board.h"

Queen::Queen(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id) {}

Queen * Queen::create(int coord, NAME name, TEAM team)
{
	Queen * queen = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		queen = new Queen(coord, "assets/images/BlackQueen.png", "BlackQueen");
		break;
	case Unit::TEAM::WHITE:
		queen = new Queen(coord, "assets/images/WhiteQueen.png", "WhiteQueen");
		break;
	}

	if (queen && queen->init())
	{
		queen->_team = team;
		queen->_name = name;
		return queen;
	}
	else
	{
		delete queen;
		queen = nullptr;
		return queen;
	}
}

bool Queen::init()
{
	if (!Unit::init())
	{
		return false;
	}

	return true;
}

void Queen::update()
{
	Unit::update();
}

void Queen::draw()
{
	Unit::draw();
}

void Queen::onVisibleButton()
{
	if (Chess::getInstance()->getNowTurn() == _team)
	{
		onVisibleHigh(_team);
		onVisibleRightHigh(_team);
		onVisibleRight(_team);
		onVisibleRightLow(_team);
		onVisibleLow(_team);
		onVisibleLeftLow(_team);
		onVisibleLeft(_team);
		onVisibleLeftHigh(_team);
	}
}

void Queen::onVisibleHigh(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x, j = y - 1;
		j >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit(); j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (j >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Queen::onVisibleRightHigh(Unit::TEAM nowTurn)
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

void Queen::onVisibleRight(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x + 1, j = y;
		i < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit(); i++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Queen::onVisibleRightLow(Unit::TEAM nowTurn)
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

void Queen::onVisibleLow(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x, j = y + 1;
		j < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit(); j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (j < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Queen::onVisibleLeftLow(Unit::TEAM nowTurn)
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

void Queen::onVisibleLeft(Unit::TEAM nowTurn)
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	for (i = x - 1, j = y;
		i >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit(); i--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != nowTurn)
	{
		Board::getInstance()->getPieces()[i][j]->getAttackButton()->setVisible(true);
	}
}

void Queen::onVisibleLeftHigh(Unit::TEAM nowTurn)
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
