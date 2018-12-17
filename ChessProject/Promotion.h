#pragma once

#include "Command.h"

class Promotion : public Command
{
public:
	Promotion(int unitInfo);

	virtual void execute();

private:
	int _unitInfo;
};