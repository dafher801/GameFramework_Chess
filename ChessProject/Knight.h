#pragma once

#include "Unit.h"

class Knight : public Unit
{
public:

	Knight(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	static Knight * create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	virtual bool init();

	virtual void update();
	virtual void render();

private:
};