#pragma once

#include "Command.h"

class Castling : public Command
{
public:
	Castling(int kingCoord, int rookCoord);

	virtual void execute();

private:
	int _kingCoord;
	int _rookCoord;
};