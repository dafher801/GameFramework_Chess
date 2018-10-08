#pragma once

#include <SDL.h>

#include "Object.h"

class Sprite : public Object
{
public:

	Sprite(SDL_Renderer * renderer, const char * fileName);

	~Sprite();

	static Sprite * create(SDL_Renderer * renderer, const char * fileName);

	virtual bool init();

	virtual void update();
	virtual void render();

	void setPosition(int x, int y);

	void setAnchorPoint(float x, float y);

	void setScale(float scale);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);

	SDL_Rect getRect() const;

	void setVisible(bool visible);
	bool isVisible() const;

protected:
	
	SDL_Surface * _surface;
	SDL_Texture * _texture;

	SDL_Point _point;
	float _anchorX;
	float _anchorY;

	SDL_Rect _srcRect;
	SDL_Rect _dstRect;

	bool _visible;
	float _scale;
	int _opacity;
};