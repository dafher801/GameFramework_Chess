#pragma once

#include "Unit.h"

class Bishop : public Unit
{
public:

	Bishop(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	static Bishop * create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	virtual bool init();

	virtual void update();
	virtual void render();

private:
};