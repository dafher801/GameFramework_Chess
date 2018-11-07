#pragma once

#include <SDL.h>
#include <iostream>
#include "Object.h"

class Sprite : public Object
{
public:
	~Sprite();

	static Sprite * create(std::string fileName, std::string id);

	virtual bool init();
	virtual void update();
	virtual void render();

private:
	Sprite(std::string fileName, std::string id);
};
