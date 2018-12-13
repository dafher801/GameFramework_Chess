#include "King.h"
#include "Chess.h"

King::King(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id) {}

King * King::create(int coord, NAME name, TEAM team)
{
	King * king = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		king = new King(coord, "assets/images/BlackKing.png", "BlackKing");
		break;
	case Unit::TEAM::WHITE:
		king = new King(coord, "assets/images/WhiteKing.png", "WhiteKing");
		break;
	}

	if (king && king->init())
	{
		king->_team = team;
		king->_name = name;
		return king;
	}
	else
	{
		delete king;
		king = nullptr;
		return king;
	}
}

bool King::init()
{
	if (!Unit::init())
	{
		return false;
	}

	return true;
}

void King::update()
{
	Unit::update();
}

void King::draw()
{
	Unit::draw();
}

void King::onVisibleButton()
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

void King::onVisibleHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x;
	int j = y - 1;

	if (j >= 0)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (j >= 0 &&
			Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleRightHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x + 1;
	int j = y - 1;

	if (i < LENGTH && j >= 0)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleRight()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x + 1;
	int j = y;

	if (i < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleRightLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x + 1;
	int j = y + 1;

	if (i < LENGTH && j < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if(Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x;
	int j = y + 1;

	if (j < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleLeftLow()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x - 1;
	int j = y + 1;

	if (i >= 0 && j < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleLeft()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x - 1;
	int j = y;

	if (i >= 0)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}

void King::onVisibleLeftHigh()
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = x - 1;
	int j = y - 1;

	if (i >= 0 && j >= 0)
	{
		if (!Board::getInstance()->getPieces()[i][j]->getUnit())
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
		{
			Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
		}
	}
}
