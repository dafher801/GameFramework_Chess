#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Piece::Piece(SDL_Renderer * renderer, SDL_Point coord)
	: _renderer(renderer)
	, _coord(coord)
	, _unit(nullptr)
	, _move(nullptr)
	, _attack(nullptr)

	//칸을 맞추는 데 쓰이는 상수들
	, _boardLength(8)
	, _oneStep(73)
	, _leftHigh({ 335,212 })
	, _rightLow({ 335 + (_oneStep * _boardLength - 1), 212 + (_oneStep * _boardLength - 1) })

	, _buttonScale(1.5)
{
}

Piece * Piece::create(SDL_Renderer * renderer, SDL_Point coord)
{
	Piece * piece = new Piece(renderer, coord);

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
	if ( !Object::init() )
	{
		return false;
	}

	return true;
}

void Piece::update()
{
	if (_unit)
		_unit->update();

	if (_move)
		_move->update();

	if (_attack)
		_attack->update();
}

void Piece::render()
{
	if (_unit)
		_unit->render();

	if (_move)
		_move->render();

	if (_attack)
		_attack->render();
}

void Piece::makeUnit(Unit::NAME name, Unit::TEAM team)
{
	switch (name)
	{
	case Unit::NAME::PAWN:
		_unit = Pawn::create(_renderer, _coord, name, team);
		break;
	case Unit::NAME::KNIGHT:
		_unit = Knight::create(_renderer, _coord, name, team);
		break;
	case Unit::NAME::BISHOP:
		_unit = Bishop::create(_renderer, _coord, name, team);
		break;
	case Unit::NAME::ROOK:
		_unit = Rook::create(_renderer, _coord, name, team);
		break;
	case Unit::NAME::QUEEN:
		_unit = Queen::create(_renderer, _coord, name, team);
		break;
	case Unit::NAME::KING:
		_unit = King::create(_renderer, _coord, name, team);
		break;
	}
}

void Piece::makeMoveButton(const char * fileName)
{
	_move = Button::create(_renderer, fileName);
	_move->setPosition(_leftHigh.x +
		(_oneStep * _coord.x), _leftHigh.y + (_oneStep * _coord.y));
	_move->setAnchorPoint(0.5, 0.5);
	_move->setScale(_buttonScale);
}

void Piece::makeAttackButton(const char * fileName)
{
	_attack = Button::create(_renderer, fileName);
	_attack->setPosition(_leftHigh.x +
		(_oneStep * _coord.x), _leftHigh.y + (_oneStep * _coord.y));
	_attack->setAnchorPoint(0.5, 0.5);
	_attack->setScale(_buttonScale);
}

Unit * Piece::getUnit() const
{
	return _unit;
}

Button * Piece::getMoveButton() const
{
	return _move;
}

Button * Piece::getAttackButton() const
{
	return _attack;
}
