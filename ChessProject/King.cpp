#include "King.h"

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
}
