#include "Knight.h"

Knight::Knight(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Unit(renderer, coord, name, team)
{
}

Knight * Knight::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	Knight * knight = new Knight(renderer, coord, name, team);

	if (knight && knight->init())
	{
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
	if (!Unit::init())
	{
		return false;
	}

	switch (_team)
	{
	case Unit::TEAM::BLACK:
		_unit = Button::create(_renderer, "assets/images/BlackKnight.png");
		break;
	case Unit::TEAM::WHITE:
		_unit = Button::create(_renderer, "assets/images/WhiteKnight.png");
		break;
	}

	dispose();

	return true;
}

void Knight::update()
{
	Unit::update();
}

void Knight::render()
{
	Unit::render();
}
