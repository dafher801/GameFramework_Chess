#include "Pawn.h"

Pawn::Pawn(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Unit(renderer, coord, name, team)
{
}

Pawn * Pawn::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	Pawn * pawn = new Pawn(renderer, coord, name, team);

	if (pawn && pawn->init())
	{
		return pawn;
	}
	else
	{
		delete pawn;
		pawn = nullptr;
		return pawn;
	}
}

bool Pawn::init()
{
	if (!Unit::init())
	{
		return false;
	}

	switch (_team)
	{
	case Unit::TEAM::BLACK:
		_unit = Button::create("assets/images/BlackPawn.png");
		break;
	case Unit::TEAM::WHITE:
		_unit = Button::create("assets/images/WhitePawn.png");
		break;
	}

	dispose();

	return true;
}

void Pawn::update()
{
	Unit::update();
}

void Pawn::render()
{
	Unit::render();
}
