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
		onVisibleHigh();
		onVisibleRightHigh();
		onVisibleRight();
		onVisibleRightLow();
		onVisibleLow();
		onVisibleLeftLow();
		onVisibleLeft();
		onVisibleLeftHigh();
	}
}

void Queen::onVisibleHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x, j = y - 1;
		j >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit(); j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (j >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleRightHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x + 1, j = y - 1;
		i < LENGTH && j >= 0 &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i++, j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && j >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleRight()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x + 1, j = y;
		i < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit(); i++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleRightLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x + 1, j = y + 1;
		i < LENGTH && j < LENGTH &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i++, j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i < LENGTH && j < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x, j = y + 1;
		j < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit(); j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (j < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleLeftLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x - 1, j = y + 1;
		i >= 0 && j < LENGTH &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i--, j++)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && j < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleLeft()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x - 1, j = y;
		i >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit(); i--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Queen::onVisibleLeftHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i;
	int j;

	for (i = x - 1, j = y - 1;
		i >= 0 && j >= 0 &&
		!Board::getInstance()->getPieces()[i][j]->getUnit(); i--, j--)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}

	if (i >= 0 && j >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}
