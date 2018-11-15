#include "Knight.h"
#include "Chess.h"
#include "Board.h"

Knight::Knight(int coord, std::string fileName, std::string id)
	: Unit(coord, fileName, id) {}

Knight * Knight::create(int coord, NAME name, TEAM team)
{
	Knight * knight = nullptr;

	switch (team)
	{
	case Unit::TEAM::BLACK:
		knight = new Knight(coord, "assets/images/BlackKnight.png", "BlackKnight");
		break;
	case Unit::TEAM::WHITE:
		knight = new Knight(coord, "assets/images/WhiteKnight.png", "WhiteKnight");
		break;
	}

	if (knight && knight->init())
	{
		knight->_team = team;
		knight->_name = name;
		return knight;
	}
	else
	{
		delete knight;
		knight = nullptr;
		return knight;
	}
}

bool Knight::init()
{
	if ( !Unit::init() )
	{
		return false;
	}

	return true;
}

void Knight::update()
{
	Unit::update();
}

void Knight::draw()
{
	Unit::draw();
}

void Knight::onVisibleButton()
{
	Unit::TEAM nowTurn;

	if ((nowTurn = Chess::getInstance()->getNowTurn()) != _team)
		return;

	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;

	//坷弗率 1沫, 困率 2沫
	if (x + 1 < LENGTH && y - 2 >= 0)
	{
		if (!Board::getInstance()->getPieces()[x + 1][y - 2]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x + 1][y - 2]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x + 1][y - 2]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x + 1][y - 2]->getAttackButton()->setVisible(true);
		}
	}

	//坷弗率 2沫, 困率 1沫
	if (x + 2 < LENGTH && y - 1 >= 0)
	{
		if (!Board::getInstance()->getPieces()[x + 2][y - 1]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x + 2][y - 1]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x + 2][y - 1]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x + 2][y - 1]->getAttackButton()->setVisible(true);
		}
	}

	//哭率 1沫, 困率 2沫
	if (x - 1 >= 0 && y - 2 >= 0)
	{
		if (!Board::getInstance()->getPieces()[x - 1][y - 2]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x - 1][y - 2]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x - 1][y - 2]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x - 1][y - 2]->getAttackButton()->setVisible(true);
		}
	}

	//哭率 2沫, 困率 1沫
	if (x - 2 >= 0 && y - 1 >= 0)
	{
		if (!Board::getInstance()->getPieces()[x - 2][y - 1]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x - 2][y - 1]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x - 2][y - 1]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x - 2][y - 1]->getAttackButton()->setVisible(true);
		}
	}

	//坷弗率 1沫, 酒贰率 2沫
	if (x + 1 < LENGTH && y + 2 < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[x + 1][y + 2]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x + 1][y + 2]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x + 1][y + 2]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x + 1][y + 2]->getAttackButton()->setVisible(true);
		}
	}

	//坷弗率 2沫, 酒贰率 1沫
	if (x + 2 < LENGTH && y + 1 < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[x + 2][y + 1]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x + 2][y + 1]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x + 2][y + 1]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x + 2][y + 1]->getAttackButton()->setVisible(true);
		}
	}

	//哭率 1沫, 酒贰率 2沫
	if (x - 1 >= 0 && y + 2 < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[x - 1][y + 2]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x - 1][y + 2]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x - 1][y + 2]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x - 1][y + 2]->getAttackButton()->setVisible(true);
		}
	}

	//哭率 2沫, 酒贰率 1沫
	if (x - 2 >= 0 && y + 1 < LENGTH)
	{
		if (!Board::getInstance()->getPieces()[x - 2][y + 1]->getUnit())
		{
			Board::getInstance()->
				getPieces()[x - 2][y + 1]->getMoveButton()->setVisible(true);
		}
		else if (Board::getInstance()->
			getPieces()[x - 2][y + 1]->getUnit()->getTeam() != nowTurn)
		{
			Board::getInstance()->
				getPieces()[x - 2][y + 1]->getAttackButton()->setVisible(true);
		}
	}
}