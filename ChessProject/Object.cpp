#include "Object.h"

Object::Object()
	: _renderer(nullptr) {}

Object::Object(SDL_Renderer * renderer)
	: _renderer(renderer) {}

bool Object::init()
{
	if ( !(SDL_Init(SDL_INIT_EVERYTHING) >= 0) )
	{
		return false;
	}
	
	return true;
}

void Object::update()
{
}

void Object::render()
{
}
