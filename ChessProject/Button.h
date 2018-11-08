#pragma once

#include <SDL.h>

#include "Object.h"

class Button
{
public:

	Button(const char * fileName);

	static Button * create(const char * fileName);

	virtual bool init();

	virtual void handleEvents();
	virtual void update();
	virtual void render();

	bool isClicked() const;

private:
	Object * _button;
	SDL_Point _mouse;
	bool _clicked;
};