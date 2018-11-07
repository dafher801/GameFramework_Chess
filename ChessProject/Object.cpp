#include "Chess.h"
#include "Object.h"
#include "TextureManager.h"

Object::Object(std::string fileName, std::string id)
	: _position(0, 0)
	, _velocity(0, 0)
	, _acceleration(0, 0)
{
	SDL_Surface * surface = IMG_Load(fileName.c_str());

	if (!TextureManager::getInstance()->load(surface, id,
		Chess::getInstance()->getRenderer()))
	{
		delete this;
	}

	SDL_SetTextureBlendMode(
		TextureManager::getInstance()->getTextureMap()[id], SDL_BLENDMODE_BLEND);

	_srcRect.x = _srcRect.y = 0;
	_dstRect.w = _srcRect.w = surface->w;
	_dstRect.h = _srcRect.h = surface->h;

	setPosition(0, 0);
	setScale(1.0f);
}

bool Object::init()
{
	if ( !(SDL_Init(SDL_INIT_EVERYTHING) >= 0) )
		return false;
	
	return true;
}

void Object::update()
{
	_position += _velocity;
	_velocity += _acceleration;
}

void Object::draw()
{
	//TextureManager::getInstance()->draw(_x, _y, _width, _height, )
}

void Object::setPosition(int x, int y)
{
	_position.setX(x);
	_position.setY(y);

	_dstRect.x = _position.getX() - (_srcRect.w * _anchorX);
	_dstRect.y = _position.getY() - (_srcRect.h * _anchorY);
}

void Object::setAnchorPoint(float x, float y)
{
	_anchorX = x;
	_anchorY = y;

	setPosition(_position.getX(), _position.getY());
}

void Object::setScale(float scale)
{
	_scale = scale;

	_dstRect.x = _position.getX() - (float)(_position.getX() - _dstRect.x) * _scale;
	_dstRect.y = _position.getY() - (float)(_position.getY() - _dstRect.y) * _scale;
	_dstRect.w *= _scale;
	_dstRect.h *= _scale;
}

void Object::setScaleX(float scaleX)
{
	_dstRect.w = _surface->w * scaleX;
}

void Object::setScaleY(float scaleY)
{
	_dstRect.h = _surface->h * scaleY;
}

SDL_Rect Object::getRect() const
{
	return _dstRect;
}

void Object::setVisible(bool visible)
{
	_visible = visible;

	_opacity = _visible ? 255 : 0;

	SDL_SetTextureAlphaMod(_texture, _opacity);
}

bool Object::isVisible() const
{
	return _visible;
}
