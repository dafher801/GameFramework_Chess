#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "UnitMove.h"
#include "UnitManager.h"

Piece::Piece(int x, int y)
	: _unit(nullptr)
	, _move(nullptr)
	, _buttonScale(1.3)
{
	_coord = (10 * (x + 1)) + (y + 1);
}

Piece * Piece::create(int x, int y)
{
	Piece * piece = new Piece(x, y);

	if (piece && piece->init())
	{
		return piece;
	}
	else
	{
		delete piece;
		piece = nullptr;
		return piece;
	}
}

bool Piece::init()
{
	if ( !(SDL_Init(SDL_INIT_EVERYTHING) >= 0) )
		return false;

	_move = Button::create("assets/images/MoveButton.png", "MoveButton");

	_move->setPosition(LEFT_HIGH_X + (ONE_STEP * ((_coord / 10) - 1)),
		LEFT_HIGH_Y + (ONE_STEP * ((_coord % 10) - 1)));

	_move->setCommand(new UnitMove(_move));
	_move->setScale(_buttonScale);
	_move->setVisible(false);

	return true;
}

void Piece::update()
{
	_move->update();

	if (_unit)
		_unit->update();
}

void Piece::draw()
{
	if (_unit)
		_unit->draw();

	_move->draw();
}

void Piece::makeUnit(Unit::NAME name, Unit::TEAM team)
{
	switch (name)
	{
	case Unit::NAME::PAWN:
		_unit = Pawn::create(_coord, name, team);
		break;
	case Unit::NAME::KNIGHT:
		_unit = Knight::create(_coord, name, team);
		break;
	case Unit::NAME::BISHOP:
		_unit = Bishop::create(_coord, name, team);
		break;
	case Unit::NAME::ROOK:
		_unit = Rook::create(_coord, name, team);
		break;
	case Unit::NAME::QUEEN:
		_unit = Queen::create(_coord, name, team);
		break;
	case Unit::NAME::KING:
		_unit = King::create(_coord, name, team);
		break;
	}

	UnitManager::getInstance()->getUnits().push_back(_unit);
}

void Piece::setUnit(Unit * unit)
{
	_unit = unit;
}

Unit * Piece::getUnit() const
{
	return _unit;
}

Button * Piece::getMoveButton() const
{
	return _move;
}