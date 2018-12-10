#include "Unit.h"
#include "Board.h"
#include "Piece.h"
#include "UnitSelect.h"

Unit::Unit(int coord, std::string fileName, std::string id)
	: Button(fileName, id)
	, _scale(1.8)
	, _coord(coord)
	
	//체크 이미지에 쓰이는 변수들
	/*, _makeCheckScale(1.0f)
	, _makeCheckOpacity(0)*/ {}

bool Unit::init()
{
	if ( !Object::init() )
	{
		return false;
	}

	setPosition(LEFT_HIGH_X + (ONE_STEP * ((_coord / 10) - 1)),
		LEFT_HIGH_Y + (ONE_STEP * ((_coord % 10) - 1)));
	setAnchorPoint(0.5, 0.5);
	setScale(_scale);

	setCommand(new UnitSelect(this));

	return true;
}

void Unit::update()
{
	Button::update();
}

void Unit::draw()
{
	Button::draw();
}

bool Unit::isSelected() const
{
	return _selected;
}

void Unit::onSelected()
{
	_selected = true;
}

void Unit::offSelected()
{
	_selected = false;
}

Unit::NAME Unit::getName() const
{
	return _name;
}

Unit::TEAM Unit::getTeam() const
{
	return _team;
}

int Unit::getCoord() const
{
	return _coord;
}

void Unit::setCoord(int coord)
{
	_coord = coord;
}
