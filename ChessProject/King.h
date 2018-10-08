#pragma once

#include "Unit.h"

class King : public Unit
{
public:

	King(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	static King * create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	virtual bool init();

	virtual void update();
	virtual void render();

private:
};