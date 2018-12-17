#pragma once

#include "Button.h"
#include "King.h"

class CastlingManager
{
public:
	static CastlingManager * getInstance();

	void update();
	void draw();

	void onCastling(King * king);
	void offCastling();

	bool castlingPosible() const;

private:
	CastlingManager();

	static CastlingManager * _instance;

	Button * _castlingButtons[4];

	bool _castlingPosible;
};