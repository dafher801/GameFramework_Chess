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
	virtual void move(int targetCoord);

	bool isSelected() const;
	void onSelected();
	void offSelected();

	NAME getName() const;
	TEAM getTeam() const;

	int getCoord() const;
	void setCoord(int coord);

	virtual bool isChecking() const = 0;

protected:

	Unit(int coord, std::string fileName, std::string id);

	//���� �̹��� ��ġ�� ���̴� ������
	const float _scale;               //���� �̹��� ũ��
	int _coord;				          //ü���� �󿡼��� ��ǥ
	NAME _name;						  //���� �̸�
	TEAM _team;						  //���� ����

	bool _selected;
};