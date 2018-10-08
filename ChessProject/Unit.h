#pragma once

#include <SDL.h>

#include "Button.h"

class Unit : public Object
{
public:

	enum NAME
	{
		PAWN,
		KNIGHT,
		BISHOP,
		ROOK,
		QUEEN,
		KING
	};

	enum TEAM
	{
		BLACK,
		WHITE
	};

	Unit(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	static Unit * create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team);

	virtual bool init();

	virtual void update();
	virtual void render();

	void dispose();

protected:

	//ĭ�� ���ߴ� �� ���̴� �����
	const int _boardLength;			  //ü���� ����
	const float _oneStep;			  //ü���ǿ��� �� ĭ�� ����
	const SDL_Point _leftHigh;        //ü������ �� ����, ��� ��ǥ
	const SDL_Point _rightLow;        //ü������ �� ����, �ϴ� ��ǥ

	//���� �̹��� ��ġ�� ���̴� ������
	Button * _unit;					  //���� �̹��� ����
	const float _scale;               //���� �̹��� ũ��
	SDL_Point _coord;				  //ü���� �󿡼��� ��ǥ
	NAME _name;						  //���� �̸�
	TEAM _team;						  //���� ����

	////üũ �̹����� ���̴� ������
	//Sprite * _makeCheck;			  //üũ �̹��� ����
	//const float _makeCheckScale;      //üũ �̹��� ũ��
	//const int _makeCheckOpacity;      //üũ �̹��� ����
};