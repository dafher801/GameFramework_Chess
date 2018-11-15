#pragma once

#include "Object.h"
#include "Piece.h"

#define LENGTH 8

class Board : public Object
{
public:
	static Board * getInstance();

	virtual bool init();
	virtual void update();
	virtual void draw();

	Piece * (* getPieces())[8];

private:
	Board();

	CREATE(Board);

	static Board * _board;

	Piece * _pieces[LENGTH][LENGTH];

	const float _boardScale;
};