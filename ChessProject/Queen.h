#pragma once

#include "Unit.h"

class Queen : public Unit
{
public:

	Queen(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	static Queen * create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	virtual bool init();

	virtual void update();
	virtual void render();

private:
};