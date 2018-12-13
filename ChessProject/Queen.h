#pragma once

#include "Unit.h"

class Queen : public Unit
{
public:

	Queen(int coord, std::string fileName, std::string id);

	static Queen * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();

private:
	void onVisibleHigh();
	void onVisibleRightHigh();
	void onVisibleRight();
	void onVisibleRightLow();
	void onVisibleLow();
	void onVisibleLeftLow();
	void onVisibleLeft();
	void onVisibleLeftHigh();
};