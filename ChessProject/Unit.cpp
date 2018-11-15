#include "Unit.h"
#include "Board.h"
#include "Piece.h"
#include "UnitButton.h"

Unit::Unit(int coord, std::string fileName, std::string id)
	: Button(fileName, id)
	, _scale(1.8)
	, _coord(coord)
	, _selected(false)
	
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

	setCommand(new UnitButton(_coord));

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

Unit::NAME Unit::getName() const
{
	return _name;
}

Unit::TEAM Unit::getTeam() const
{
	return _team;
}
