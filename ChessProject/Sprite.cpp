#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>

Sprite::Sprite(SDL_Renderer * renderer, const char * fileName)
	: Object(renderer)
	, _point({ 0,0 })
	, _anchorX(0.5)
	, _anchorY(0.5)
	, _visible(true)
	, _scale(1.0f)
	, _opacity(255)
	, _surface(IMG_Load(fileName)) {}

Sprite::~Sprite()
{
	_renderer = nullptr;
	SDL_FreeSurface(_surface);
	SDL_DestroyTexture(_texture);
}

Sprite * Sprite::create(SDL_Renderer * renderer, const char * fileName)
{
	Sprite * sprite = new Sprite(renderer, fileName);

	if (sprite && sprite->init())
	{
		return sprite;
	}
	else
	{
		delete sprite;
		sprite = nullptr;
		return sprite;
	}
}

bool Sprite::init()
{
	if ( !Object::init() )
	{
		return false;
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);

	_srcRect.x = _srcRect.y = 0;
	_dstRect.w = _srcRect.w = _surface->w;
	_dstRect.h = _srcRect.h = _surface->h;

	setPosition(0, 0);
	setScale(1.0f);

	return true;
}

void Sprite::update()
{
	
}

void Sprite::render()
{
	SDL_RenderCopy(_renderer, _texture, &_srcRect, &_dstRect);
}

void Sprite::setPosition(int x, int y)
{
	_point.x = x;
	_point.y = y;

	_dstRect.x = _point.x - (_srcRect.w * _anchorX);
	_dstRect.y = _point.y - (_srcRect.h * _anchorY);
}

void Sprite::setAnchorPoint(float x, float y)
{
	_anchorX = x;
	_anchorY = y;

	setPosition(_point.x, _point.y);
}

void Sprite::setScale(float scale)
{
	_scale = scale;

	_dstRect.x = _point.x - (float)(_point.x - _dstRect.x) * _scale;
	_dstRect.y = _point.y - (float)(_point.y - _dstRect.y) * _scale;
	_dstRect.w *= _scale;
	_dstRect.h *= _scale;
}

void Sprite::setScaleX(float scaleX)
{
	_dstRect.w = _surface->w * scaleX;
}

void Sprite::setScaleY(float scaleY)
{
	_dstRect.h = _surface->h * scaleY;
}

SDL_Rect Sprite::getRect() const
{
	return _dstRect;
}

void Sprite::setVisible(bool visible)
{
	_visible = visible;

	_opacity = _visible ? 255 : 0;

	SDL_SetTextureAlphaMod(_texture, _opacity);
}

bool Sprite::isVisible() const
{
	return _visible;
}
