#include "Button.h"

Button::Button(std::string fileName, std::string id)
	: Object(fileName, id)
	, _selected(false) {}

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
	Object::update();
	handleInput();
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

	if (SDL_PointInRect(&_mousePoint, &_dstRect) && isVisible())
	{
		if (!_selected && InputHandler::getInstance()->getMouseButtonState(LEFT))
		{
			_selected = true;
		}

		if (_selected && !InputHandler::getInstance()->getMouseButtonState(LEFT))
		{
			for (Command * iter : _commands)
			{
				iter->execute();
			}

			_selected = false;
		}
	}

	if (!SDL_PointInRect(&_mousePoint, &_dstRect))
		_selected = false;
}

bool Button::isSelected() const
{
	return _selected;
}

void Button::setCommand(Command * newCommand)
{
	_commands.push_back(newCommand);
}

std::vector<Command *> Button::getCommand() const
{
	return _commands;
}
