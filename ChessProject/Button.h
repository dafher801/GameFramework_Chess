#pragma once

#include <SDL.h>

#include "Sprite.h"

class Button : public Sprite
{
public:

	Button(SDL_Renderer * renderer, const char * fileName);

	static Button * create(SDL_Renderer * renderer, const char * fileName);

	virtual bool init();

	virtual void handleEvents();
	virtual void update();
	virtual void render();

	bool isClicked() const;

private:
	SDL_Point _mouse;
	bool _clicked;
};