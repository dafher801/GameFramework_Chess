#pragma once

#include "Unit.h"

class Bishop : public Unit
{
public:

	Bishop(int coord, std::string fileName, std::string id);

	static Bishop * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();

private:
	void onVisibleRightHigh();
	void onVisibleRightLow();
	void onVisibleLeftLow();
	void onVisibleLeftHigh();
};