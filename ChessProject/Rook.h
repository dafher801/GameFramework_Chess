#pragma once

#include "Unit.h"

class Rook : public Unit
{
public:

	Rook(int coord, std::string fileName, std::string id);

	static Rook * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();

private:
	void onVisibleHigh(Unit::TEAM nowTurn);
	void onVisibleRight(Unit::TEAM nowTurn);
	void onVisibleLow(Unit::TEAM nowTurn);
	void onVisibleLeft(Unit::TEAM nowTurn);
};