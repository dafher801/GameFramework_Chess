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

	//칸을 맞추는 데 쓰이는 상수들
	const int _boardLength;			  //체스판 길이
	const float _oneStep;			  //체스판에서 한 칸의 길이
	const SDL_Point _leftHigh;        //체스판의 맨 좌측, 상단 좌표
	const SDL_Point _rightLow;        //체스판의 맨 우측, 하단 좌표

	//유닛 이미지 배치에 쓰이는 변수들
	Button * _unit;					  //유닛 이미지 파일
	const float _scale;               //유닛 이미지 크기
	SDL_Point _coord;				  //체스판 상에서의 좌표
	NAME _name;						  //유닛 이름
	TEAM _team;						  //유닛 색깔

	////체크 이미지에 쓰이는 변수들
	//Sprite * _makeCheck;			  //체크 이미지 파일
	//const float _makeCheckScale;      //체크 이미지 크기
	//const int _makeCheckOpacity;      //체크 이미지 투명도
};