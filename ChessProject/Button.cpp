#include "Button.h"

Button::Button(const char * fileName)
	: _clicked(false) {}

Button * Button::create(const char * fileName)
{
	Button * button = new Button(fileName);

	if (button && button->init())
	{
		return button;
	}
	else
	{
		delete button;
		button = nullptr;
		return button;
	}
}

bool Button::init()
{

}

void Button::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			_mouse.x = event.motion.x;
			_mouse.y = event.motion.y;
			break;

		default:
			break;
		}
	}
}

void Button::update()
{
	//_clicked = SDL_PointInRect(&_mouse, &Sprite::getRect());
}

void Button::render()
{
	//Sprite::render();
}

bool Button::isClicked() const
{
	return _clicked;
}
