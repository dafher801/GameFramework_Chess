#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>

#include "Vector2D.h"
#include "Action.h"

#define CREATE(__TYPE__) \
static __TYPE__ * create() \
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
}

class Object
{
public:
	virtual bool init();
	virtual void update();
	virtual void draw();

	void addChild(Object * object);
	void removeChild(Object * object);

	void setPosition(int x, int y);
	Vector2D getPosition() const;

	void setAnchorPoint(float x, float y);

	void setScale(float scale);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);

	SDL_Rect getRect() const;

	void setVisible(bool visible);
	bool isVisible() const;

	//Action * runAction(Action * action);

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
	int _opacity;

	float _scaleX;
	float _scaleY;

	std::vector<Object*> _objects;
};