#pragma once

#include <SDL.h>

#include "Unit.h"
#include "Button.h"

class Piece : public Object
{
public:

	Piece(SDL_Renderer * renderer, SDL_Point coord);

	static Piece * create(SDL_Renderer * renderer, SDL_Point coord);

	virtual bool init();

	virtual void update();
	virtual void render();

	void makeUnit(Unit::NAME name, Unit::TEAM team);
	void makeMoveButton(const char * fileName);
	void makeAttackButton(const char * fileName);

	Unit * getUnit() const;
	Button * getMoveButton() const;
	Button * getAttackButton() const;

private:
	Unit * _unit;
	Button * _move;
	Button * _attack;

	SDL_Point _coord;
	SDL_Renderer * _renderer;

	//칸을 맞추는 데 쓰이는 상수들
	const int _boardLength;			  //체스판 길이
	const int _oneStep;			      //체스판에서 한 칸의 길이
	const SDL_Point _leftHigh;        //체스판의 맨 좌측, 상단 좌표
	const SDL_Point _rightLow;        //체스판의 맨 우측, 하단 좌표

	const float _buttonScale;		  //버튼의 크기
};