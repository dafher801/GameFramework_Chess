#pragma once

#include "Unit.h"

class King : public Unit
{
public:

	King(int coord, std::string fileName, std::string id);

	static King * create(int coord, NAME name, TEAM team);

	virtual bool init();
	virtual void update();
	virtual void draw();

	virtual void onVisibleButton();
	virtual bool isChecking() const;

private:
	void onVisibleHigh();
	void onVisibleRightHigh();
	void onVisibleRight();
	void onVisibleRightLow();
	void onVisibleLow();
	void onVisibleLeftLow();
	void onVisibleLeft();
	void onVisibleLeftHigh();

	bool isCheckingHigh() const;
	bool isCheckingRightHigh() const;
	bool isCheckingRight() const;
	bool isCheckingRightLow() const;
	bool isCheckingLow() const;
	bool isCheckingLeftLow() const;
	bool isCheckingLeft() const;
	bool isCheckingLeftHigh() const;
};