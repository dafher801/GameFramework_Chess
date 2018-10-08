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

	//ĭ�� ���ߴ� �� ���̴� �����
	const int _boardLength;			  //ü���� ����
	const int _oneStep;			      //ü���ǿ��� �� ĭ�� ����
	const SDL_Point _leftHigh;        //ü������ �� ����, ��� ��ǥ
	const SDL_Point _rightLow;        //ü������ �� ����, �ϴ� ��ǥ

	const float _buttonScale;		  //��ư�� ũ��
};