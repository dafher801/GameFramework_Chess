#include "InputHandler.h"
#include "Chess.h"

InputHandler * InputHandler::_instance = 0;

InputHandler::InputHandler()
{
	_mousePosition = new Vector2D(0, 0);

	for (int i = 0; i < 3; i++)
		_mouseButtonStates.push_back(false);
}

void InputHandler::onMouseMove(SDL_Event event)
{
	_mousePosition->setX(event.motion.x);
	_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		_mouseButtonStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		_mouseButtonStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		_mouseButtonStates[RIGHT] = true;
		break;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		_mouseButtonStates[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		_mouseButtonStates[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		_mouseButtonStates[RIGHT] = false;
		break;
	}
}

InputHandler * InputHandler::getInstance()
{
	if (!_instance)
		_instance = new InputHandler;

	return _instance;
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Chess::getInstance()->quit();
			break;

		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;

		case SDL_KEYDOWN:
			_keyStates = SDL_GetKeyboardState(0);
			break;

		case SDL_KEYUP:
			_keyStates = SDL_GetKeyboardState(0);
			break;

		default:
			break;
		}
	}
}

void InputHandler::clean()
{

}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (_keyStates && _keyStates[key] == 1)
		return true;

	return false;
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return _mouseButtonStates[buttonNumber];
}

Vector2D * InputHandler::getMousePosition()
{
	return _mousePosition;
}
