#include "CastlingManager.h"
#include "UnitManager.h"
#include "Castling.h"
#include "Chess.h"
#include "Piece.h"
#include "Rook.h"

CastlingManager * CastlingManager::_instance = nullptr;

CastlingManager::CastlingManager()
	: _castlingPosible(false)
{
	_castlingButtons[0] = Board::getInstance()->hash(31)->getMoveButton();
	_castlingButtons[1] = Board::getInstance()->hash(71)->getMoveButton();
	_castlingButtons[2] = Board::getInstance()->hash(38)->getMoveButton();
	_castlingButtons[3] = Board::getInstance()->hash(78)->getMoveButton();

	_castlingButtons[0]->setCommand(new Castling(51, 11));
	_castlingButtons[1]->setCommand(new Castling(51, 81));
	_castlingButtons[2]->setCommand(new Castling(58, 18));
	_castlingButtons[3]->setCommand(new Castling(58, 88));
}

CastlingManager * CastlingManager::getInstance()
{
	if (!_instance)
		_instance = new CastlingManager;

	return _instance;
}

void CastlingManager::update()
{
	for (int i = 0; i < 4; i++)
		_castlingButtons[i]->update();
}

void CastlingManager::draw()
{
	for (int i = 0; i < 4; i++)
		_castlingButtons[i]->draw();
}

void CastlingManager::onCastling(King * king)
{
	if (Chess::getInstance()->isChecked())
		return;

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->getName() == Unit::NAME::ROOK && king->getTeam() == iter->getTeam())
		{
			if (king->getCoord() > iter->getCoord())
			{
				if (!Board::getInstance()->hash(king->getCoord() - 10)->getUnit() &&
					!Board::getInstance()->hash(king->getCoord() - 20)->getUnit() &&
					!Board::getInstance()->hash(king->getCoord() - 30)->getUnit() &&
					Board::getInstance()->hash(king->getCoord() - 10)->getMoveButton()->isVisible())
				{
					switch (king->getTeam())
					{
					case Unit::TEAM::BLACK:
						_castlingButtons[0]->setVisible(true);
						break;
					case Unit::TEAM::WHITE:
						_castlingButtons[2]->setVisible(true);
						break;
					}

					_castlingPosible = true;
					return;
				}
			}

			if (king->getCoord() < iter->getCoord())
			{
				if (!Board::getInstance()->hash(king->getCoord() + 10)->getUnit() &&
					!Board::getInstance()->hash(king->getCoord() + 20)->getUnit() &&
					Board::getInstance()->hash(king->getCoord() + 10)->getMoveButton()->isVisible())
				{
					switch (king->getTeam())
					{
					case Unit::TEAM::BLACK:
						_castlingButtons[1]->setVisible(true);
						break;
					case Unit::TEAM::WHITE:
						_castlingButtons[3]->setVisible(true);
						break;
					}

					_castlingPosible = true;
					return;
				}
			}
		}
	}

	_castlingPosible = false;
}

void CastlingManager::offCastling()
{
	for (int i = 0; i < 4; i++)
		_castlingButtons[i]->setVisible(false);
}

bool CastlingManager::castlingPosible() const
{
	return _castlingPosible;
}
