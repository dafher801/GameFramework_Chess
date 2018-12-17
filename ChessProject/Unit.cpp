#include "Unit.h"
#include "Board.h"
#include "Piece.h"
#include "UnitSelect.h"
#include "UnitManager.h"
#include "MoveTo.h"
#include "Chess.h"

Unit::Unit(int coord, std::string fileName, std::string id)
	: Button(fileName, id)
	, _scale(1.8)
	, _coord(coord) {}

bool Unit::init()
{
	if (!Object::init())
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

void Unit::move(int targetCoord)
{
	int x = _coord / 10 - 1;
	int y = _coord % 10 - 1;
	int i = targetCoord / 10 - 1;
	int j = targetCoord % 10 - 1;

	Chess::getInstance()->changeTurn();

	if (Board::getInstance()->getPieces()[i][j]->getUnit())
		UnitManager::getInstance()->DeleteUnit(
			Board::getInstance()->getPieces()[i][j]->getUnit());

	Board::getInstance()->getPieces()[x][y]->setUnit(nullptr);
	Board::getInstance()->getPieces()[i][j]->setUnit(this);

	Board::getInstance()->getPieces()[i][j]
		->getUnit()->setCoord((i + 1) * 10 + j + 1);

	MoveTo * moveTo = MoveTo::create(2,
		Vector2D(LEFT_HIGH_X + (ONE_STEP * i), LEFT_HIGH_Y + (ONE_STEP * j)));
	this->runAction(moveTo);

	if (Chess::getInstance()->gameOver())
	{
		for (Unit * iter : UnitManager::getInstance()->getUnits())
		{
			if (iter->isChecking())
			{
				Chess::getInstance()->getCheckmate()->setVisible(true);
				return;
			}
		}

		Chess::getInstance()->getStalemate()->setVisible(true);
	}
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
