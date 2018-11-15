#pragma once

#include <SDL.h>

#include "Unit.h"
#include "Button.h"

#define ONE_STEP 81
#define LEFT_HIGH_X 268
#define LEFT_HIGH_Y 169
#define RIGHT_ROW_X 835
#define RIGHT_ROW_Y 736

class Piece
{
public:

	Piece(int x, int y);

	static Piece * create(int x, int y);

	virtual bool init();
	virtual void update();
	virtual void draw();

	void makeUnit(Unit::NAME name, Unit::TEAM team);

	Unit * getUnit() const;
	Button * getMoveButton() const;
	Button * getAttackButton() const;

private:
	Unit * _unit;
	Button * _move;
	Button * _attack;

	int _coord;

	const float _buttonScale;		  //버튼의 크기
};