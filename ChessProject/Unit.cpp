#include <SDL.h>
#include "Unit.h"

Unit::Unit(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
	: Object(renderer)

	//ĭ�� ���ߴ� �� ���̴� �����
	, _boardLength(8)
	, _oneStep(73.5f)
	, _leftHigh({ 295,195 })
	, _rightLow({ 335 + (int)(_oneStep * _boardLength - 1),
		212 + (int)(_oneStep * _boardLength - 1) })

	//���� �̹��� ��ġ�� ���̴� ������
	, _scale(1.8)
	, _coord(coord)
	, _name(name)
	, _team(team)
	
	//üũ �̹����� ���̴� ������
	/*, _makeCheckScale(1.0f)
	, _makeCheckOpacity(0)*/
{
}

Unit * Unit::create(SDL_Renderer * renderer, SDL_Point coord, NAME name, TEAM team)
{
	Unit * unit = new Unit(renderer, coord, name, team);

	if (unit && unit->init())
	{
		return unit;
	}
	else
	{
		delete unit;
		unit = nullptr;
		return unit;
	}
}

bool Unit::init()
{
	if ( !Object::init() )
	{
		return false;
	}

	return true;
}

void Unit::update()
{
	_unit->update();
}

void Unit::render()
{
	_unit->render();
}

void Unit::dispose()
{
	_unit->setPosition(_leftHigh.x + (_oneStep * _coord.x), _leftHigh.y + (_oneStep * _coord.y));
	_unit->setAnchorPoint(0.5 , 0.5);
	_unit->setScale(_scale);
}
