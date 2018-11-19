#pragma once

#include "Command.h"
#include "MoveTo.h"

class UnitMove : public Command
{
public:
	virtual void execute();

private:
	MoveTo * _action;
};