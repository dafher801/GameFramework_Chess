#pragma once

#include "Unit.h"

class Knight : public Unit
{
public:

	Knight(int coord, std::string fileName, std::string id);

	static Knight * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();
	virtual bool isChecking() const;
};