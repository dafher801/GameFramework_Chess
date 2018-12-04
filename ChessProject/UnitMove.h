#pragma once

#include "Command.h"
#include "MoveTo.h"

class UnitMove : public Command
{
public:
	UnitMove(Button * button);

	virtual void execute();

private:
	Button * _button;
};