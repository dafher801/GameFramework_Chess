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
	void onVisibleHigh(Unit::TEAM nowTurn);
	void onVisibleRightHigh(Unit::TEAM nowTurn);
	void onVisibleRight(Unit::TEAM nowTurn);
	void onVisibleRightLow(Unit::TEAM nowTurn);
	void onVisibleLow(Unit::TEAM nowTurn);
	void onVisibleLeftLow(Unit::TEAM nowTurn);
	void onVisibleLeft(Unit::TEAM nowTurn);
	void onVisibleLeftHigh(Unit::TEAM nowTurn);
};