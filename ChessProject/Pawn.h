#pragma once

#include "Unit.h"

class Pawn : public Unit
{
public:

	Pawn(int coord, std::string fileName, std::string id);

	static Pawn * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();
	virtual void move(int coord);
	virtual bool isChecking() const;

private:
	void onMoveButton(int x, int y, int direction, Unit::TEAM nowTurn);

	bool _moved;
};