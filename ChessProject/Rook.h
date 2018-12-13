#pragma once

#include "Unit.h"

class Rook : public Unit
{
public:

	Rook(int coord, std::string fileName, std::string id);

	static Rook * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();
	virtual bool isChecking() const;

private:
	void onVisibleHigh();
	void onVisibleRight();
	void onVisibleLow();
	void onVisibleLeft();

	bool isCheckingHigh() const;
	bool isCheckingRight() const;
	bool isCheckingLow() const;
	bool isCheckingLeft() const;
};