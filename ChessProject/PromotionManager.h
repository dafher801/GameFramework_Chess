#pragma once

#include "Unit.h"
#include "Button.h"

class PromotionManager
{
public:

	static PromotionManager * getInstance();

	void update();
	void draw();

	void onPromotion();
	void offPromotion();

	Object * getPromotionMenu() const;

	Unit * getPromotionPawn() const;

private:
	PromotionManager();

	static PromotionManager * _instance;

	Button * _promotionButtons[8];

	Object * _promotionMenu;

	Unit * _promotionPawn;
};