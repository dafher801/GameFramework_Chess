#include "Rook.h"

Rook::Rook(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Unit(renderer, coord, name, team)
{
}

Rook * Rook::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	Rook * rook = new Rook(renderer, coord, name, team);

	if (rook && rook->init())
	{
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

	switch (_team)
	{
	case Unit::TEAM::BLACK:
		_unit = Button::create(_renderer, "assets/images/BlackRook.png");
		break;
	case Unit::TEAM::WHITE:
		_unit = Button::create(_renderer, "assets/images/WhiteRook.png");
		break;
	}

	dispose();

	return true;
}

void Rook::update()
{
	Unit::update();
}

void Rook::render()
{
	Unit::render();
}
