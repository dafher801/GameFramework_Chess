#pragma once

#include "Object.h"
#include "Command.h"
#include "InputHandler.h"

#include <SDL.h>
#include <vector>

class Button : public Object
{
public:

	Button(std::string fileName, std::string id);

	static Button * create(std::string fileName, std::string id);

	virtual bool init();
	virtual void update();
	virtual void draw();

	void handleInput();

	bool isSelected() const;

	void setCommand(Command * newCommand);
	std::vector<Command *> getCommand() const;

protected:
	bool _selected;

private:
	std::vector<Command *> _commands;
	SDL_Point _mousePoint;
};