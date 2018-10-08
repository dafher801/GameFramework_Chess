#include "Button.h"

Button::Button(SDL_Renderer * renderer, const char * fileName)
	: Sprite(renderer, fileName)
	, _clicked(false) {}

Button * Button::create(SDL_Renderer * renderer, const char * fileName)
{
	Button * button = new Button(renderer, fileName);

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
	if ( !Sprite::init() )
	{
		return false;
	}

	return true;
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
	_clicked = SDL_PointInRect(&_mouse, &Sprite::getRect());
	Sprite::update();
}

void Button::render()
{
	Sprite::render();
}

bool Button::isClicked() const
{
	return _clicked;
}
