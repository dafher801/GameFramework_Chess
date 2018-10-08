#include "King.h"

King::King(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Unit(renderer, coord, name, team)
{
}

King * King::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	King * king = new King(renderer, coord, name, team);

	if (king && king->init())
	{
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
	if ( !Unit::init() )
	{
		return false;
	}

	switch (_team)
	{
	case Unit::TEAM::BLACK:
		_unit = Button::create(_renderer, "assets/images/BlackKing.png");
		break;
	case Unit::TEAM::WHITE:
		_unit = Button::create(_renderer, "assets/images/WhiteKing.png");
		break;
	}

	dispose();

	return true;
}

void King::update()
{
	Unit::update();
}

void King::render()
{
	Unit::render();
}
