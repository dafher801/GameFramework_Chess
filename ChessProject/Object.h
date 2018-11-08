#pragma once

#include <SDL.h>
#include "Vector2D.h"

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
	virtual bool init();
	virtual void update();
	virtual void draw();

	void setPosition(int x, int y);

	void setAnchorPoint(float x, float y);

	void setScale(float scale);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);

	SDL_Rect getRect() const;

	void setVisible(bool visible);
	bool isVisible() const;

protected:
	Object(std::string fileName, std::string id);

	static Object * create(std::string fileName, std::string id);

	std::string _ID;
	std::string _fileName;

	Vector2D _position;
	Vector2D _velocity;
	Vector2D _acceleration;

	float _anchorX;
	float _anchorY;

	SDL_Rect _srcRect;
	SDL_Rect _dstRect;

	bool _visible;
	float _scale;
	int _opacity;
};