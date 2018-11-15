#include "Button.h"

Button::Button(std::string fileName, std::string id)
	: Object(fileName, id)
	, _command(nullptr) {}

Button * Button::create(std::string fileName, std::string id)
{
	Button * button = new Button(fileName, id);

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
	if (!Object::init())
		return false;

	return true;
}

void Button::update()
{
	handleInput();
	Object::update();
}

void Button::draw()
{
	Object::draw();
}

void Button::handleInput()
{
	_mousePoint = {
		(int)InputHandler::getInstance()->getMousePosition()->getX(),
		(int)InputHandler::getInstance()->getMousePosition()->getY()
	};

	if (InputHandler::getInstance()->getMouseButtonState(LEFT) &&
		SDL_PointInRect(&_mousePoint, &_dstRect) && isVisible())
	{
		_command->execute();
	}
}

void Button::setCommand(Command * newCommand)
{
	_command = newCommand;
}

Command * Button::getCommand() const
{
	return _command;
}
