#include "Rook.h"
#include "Chess.h"
#include "Board.h"

Rook::Rook(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id) {}

Rook * Rook::create(int coord, NAME name, TEAM team)
{
	Rook * rook = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		rook = new Rook(coord, "assets/images/BlackRook.png", "BlackRook");
		break;
	case Unit::TEAM::WHITE:
		rook = new Rook(coord, "assets/images/WhiteRook.png", "WhiteRook");
		break;
	}

	if (rook && rook->init())
	{
		rook->_team = team;
		rook->_name = name;
		return rook;
	}
	else
	{
		delete rook;
		rook = nullptr;
		return rook;
	}
}

bool Rook::init()
{
	if (!Unit::init())
	{
		return false;
	}

	return true;
}

void Rook::update()
{
	Unit::update();
}

void Rook::draw()
{
	Unit::draw();
}

void Rook::onVisibleButton()
{
	if (Chess::getInstance()->getNowTurn() == _team)
	{
		onVisibleHigh();
		onVisibleRight();
		onVisibleLow();
		onVisibleLeft();
	}
}

bool Rook::isChecking() const
{
	return false;
}

void Rook::onVisibleHigh()
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

	if (j >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Rook::onVisibleRight()
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

	if (i < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Rook::onVisibleLow()
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

	if (j < LENGTH &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

void Rook::onVisibleLeft()
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

	if (i >= 0 &&
		Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(true);
	}
}

bool Rook::isCheckingHigh() const
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	i = x;
	j = y - 1;

	while (
		j >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit())
	{
		j--;
	}

	if (j >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		return true;
	}

	return false;
}

bool Rook::isCheckingRight() const
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	i = x + 1;
	j = y;

	while (i < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit())
	{
		i++;
	}

	if (i < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		return true;
	}

	return false;
}

bool Rook::isCheckingLow() const
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	i = x;
	j = y + 1;

	while (j < LENGTH && !Board::getInstance()->getPieces()[i][j]->getUnit())
	{
		j++;
	}

	if (j < LENGTH && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		return true;
	}

	return false;
}

bool Rook::isCheckingLeft() const
{
	int i;
	int j;
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	i = x - 1;
	j = y;

	while (i >= 0 && !Board::getInstance()->getPieces()[i][j]->getUnit())
	{
		i--;
	}

	if (i >= 0 && Board::getInstance()->getPieces()[i][j]->getUnit()->getTeam() != _team)
	{
		return true;
	}

	return false;
}
