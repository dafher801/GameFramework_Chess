#pragma once

#include <SDL.h>

#define CREATE(__TYPE__) \
static __TYPE__* create() \
{ \
	__TYPE__ * ret = new __TYPE__(); \
 \
	if (ret && ret->init()) \
	{ \
		return ret; \
	} \
	else \
	{ \
		delete ret; \
		ret = nullptr; \
		return ret; \
	} \
 \
}

class Object
{
public:

	Object();
	Object(SDL_Renderer * renderer);

	CREATE(Object);

	virtual bool init();

	virtual void update();
	virtual void render();

protected:
	SDL_Renderer * _renderer;
};