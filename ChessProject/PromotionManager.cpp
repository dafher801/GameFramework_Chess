#include "PromotionManager.h"
#include "UnitManager.h"
#include "Promotion.h"
#include "Chess.h"
#include "Piece.h"

PromotionManager * PromotionManager::_instance = nullptr;

PromotionManager::PromotionManager()
	: _promotionPawn(nullptr)
{
	_promotionMenu = Object::create("assets/images/PromotionMenu.png", "PromotionMenu");
	_promotionMenu->setPosition(
		Chess::getInstance()->getRect().w / 2, Chess::getInstance()->getRect().h / 2);
	_promotionMenu->setVisible(false);

	_promotionButtons[0] = Button::create("assets/images/BlackKnight.png", "BlackKnight");
	_promotionButtons[0]->setPosition(LEFT_HIGH_X + (ONE_STEP * 2), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[0]->setScale(1.8);

	_promotionButtons[1] = Button::create("assets/images/BlackBishop.png", "BlackBishop");
	_promotionButtons[1]->setPosition(LEFT_HIGH_X + (ONE_STEP * 3), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[1]->setScale(1.8);

	_promotionButtons[2] = Button::create("assets/images/BlackRook.png", "BlackRook");
	_promotionButtons[2]->setPosition(LEFT_HIGH_X + (ONE_STEP * 4), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[2]->setScale(1.8);

	_promotionButtons[3] = Button::create("assets/images/BlackQueen.png", "BlackQueen");
	_promotionButtons[3]->setPosition(LEFT_HIGH_X + (ONE_STEP * 5), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[3]->setScale(1.8);

	_promotionButtons[4] = Button::create("assets/images/WhiteKnight.png", "WhiteKnight");
	_promotionButtons[4]->setPosition(LEFT_HIGH_X + (ONE_STEP * 2), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[4]->setScale(1.8);

	_promotionButtons[5] = Button::create("assets/images/WhiteBishop.png", "WhiteBishop");
	_promotionButtons[5]->setPosition(LEFT_HIGH_X + (ONE_STEP * 3), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[5]->setScale(1.8);

	_promotionButtons[6] = Button::create("assets/images/WhiteRook.png", "WhiteRook");
	_promotionButtons[6]->setPosition(LEFT_HIGH_X + (ONE_STEP * 4), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[6]->setScale(1.8);

	_promotionButtons[7] = Button::create("assets/images/WhiteQueen.png", "WhiteQueen");
	_promotionButtons[7]->setPosition(LEFT_HIGH_X + (ONE_STEP * 5), LEFT_HIGH_Y + (ONE_STEP * 4));
	_promotionButtons[7]->setScale(1.8);

	for (int i = 0; i < 8; i++)
	{
		_promotionButtons[i]->setCommand(new Promotion(i));
		_promotionButtons[i]->setVisible(false);
	}
}

PromotionManager * PromotionManager::getInstance()
{
	if (!_instance)
		_instance = new PromotionManager;

	return _instance;
}

void PromotionManager::update()
{
	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if ((iter->getCoord() % 10 == 1 &&
			iter->getName() == Unit::NAME::PAWN &&
			iter->getTeam() == Unit::TEAM::WHITE) ||

			(iter->getCoord() % 10 == 8 &&
			iter->getName() == Unit::NAME::PAWN &&
			iter->getTeam() == Unit::TEAM::BLACK))
		{
			_promotionPawn = iter;
			onPromotion();
			break;
		}

		_promotionPawn = nullptr;
	}

	_promotionMenu->update();

	for (int i = 0; i < 8; i++)
		_promotionButtons[i]->update();
}

void PromotionManager::draw()
{
	_promotionMenu->draw();

	for (int i = 0; i < 8; i++)
		_promotionButtons[i]->draw();
}

void PromotionManager::onPromotion()
{
	int i;

	_promotionMenu->setVisible(true);

	switch (Chess::getInstance()->getNowTurn())
	{
	case Unit::TEAM::BLACK:
		i = 4;
		break;
	case Unit::TEAM::WHITE:
		i = 0;
		break;
	}

	for (int j = 0; j < 4; j++)
		_promotionButtons[i + j]->setVisible(true);
}

void PromotionManager::offPromotion()
{
	_promotionMenu->setVisible(false);

	for (int i = 0; i < 8; i++)
		_promotionButtons[i]->setVisible(false);
}

Object * PromotionManager::getPromotionMenu() const
{
	return _promotionMenu;
}

Unit * PromotionManager::getPromotionPawn() const
{
	return _promotionPawn;
}
