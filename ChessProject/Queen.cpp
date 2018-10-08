#include "Queen.h"

Queen::Queen(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Unit(renderer, coord, name, team)
{
}

Queen * Queen::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	Queen * queen = new Queen(renderer, coord, name, team);

	if (queen && queen->init())
	{
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

	switch (_team)
	{
	case Unit::TEAM::BLACK:
		_unit = Button::create(_renderer, "assets/images/BlackQueen.png");
		break;
	case Unit::TEAM::WHITE:
		_unit = Button::create(_renderer, "assets/images/WhiteQueen.png");
		break;
	}

	dispose();

	return true;
}

void Queen::update()
{
	Unit::update();
}

void Queen::render()
{
	Unit::render();
}
