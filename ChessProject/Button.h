#pragma once

#include <SDL.h>
#include "Object.h"
#include "Command.h"
#include "InputHandler.h"

class Button : public Object
{
public:

	Button(std::string fileName, std::string id);

	static Button * create(std::string fileName, std::string id);

	virtual bool init();
	virtual void update();
	virtual void draw();

	void handleInput();

	void setCommand(Command * newCommand);
	Command * getCommand() const;

private:
	Command * _command;
	SDL_Point _mousePoint;
};