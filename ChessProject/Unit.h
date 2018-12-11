#pragma once

#include <SDL.h>

#include "Button.h"

class Unit : public Button
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

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton() = 0;
	virtual void move(int coord);

	bool isSelected() const;
	void onSelected();
	void offSelected();

	NAME getName() const;
	TEAM getTeam() const;

	int getCoord() const;
	void setCoord(int coord);

protected:

	Unit(int coord, std::string fileName, std::string id);

	//유닛 이미지 배치에 쓰이는 변수들
	const float _scale;               //유닛 이미지 크기
	int _coord;				          //체스판 상에서의 좌표
	NAME _name;						  //유닛 이름
	TEAM _team;						  //유닛 색깔

	bool _selected;

	//체크 이미지에 쓰이는 변수들
	//Sprite * _makeCheck;			  //체크 이미지 파일
	//const float _makeCheckScale;    //체크 이미지 크기
	//const int _makeCheckOpacity;    //체크 이미지 투명도
};