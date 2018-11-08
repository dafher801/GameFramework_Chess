#include "Chess.h"
#include "Object.h"
#include "TextureManager.h"

Object::Object(std::string fileName, std::string id)
	: _ID(id)
	, _fileName(fileName)
	, _position(0, 0)
	, _velocity(0, 0)
	, _acceleration(0, 0) {}

Object * Object::create(std::string fileName, std::string id)
{
	Object * object = new Object(fileName, id);

	if (object && object->init())
	{
		return object;
	}
	else
	{
		delete object;
		object = nullptr;
		return object;
	}
}

bool Object::init()
{
	SDL_Surface * surface = IMG_Load(_fileName.c_str());

	if (!(SDL_Init(SDL_INIT_EVERYTHING) >= 0) ||
		!TextureManager::getInstance()->load(surface, _ID, Chess::getInstance()->getRenderer()))
	{
		SDL_FreeSurface(surface);
		return false;
	}

	/*SDL_SetTextureBlendMode(
		TextureManager::getInstance()->getTextureMap()[_ID], SDL_BLENDMODE_BLEND);*/

	_srcRect.x = _srcRect.y = 0;
	_dstRect.w = _srcRect.w = surface->w;
	_dstRect.h = _srcRect.h = surface->h;

	setPosition(0, 0);
	setScale(1.0f);

	SDL_FreeSurface(surface);
	return true;
}

void Object::update()
{
}

void Object::draw()
{
	TextureManager::getInstance()->draw(_ID, _dstRect.x,
		_dstRect.y, _dstRect.w, _dstRect.h, Chess::getInstance()->getRenderer());
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
	_dstRect.w = _srcRect.w * scaleX;
}

void Object::setScaleY(float scaleY)
{
	_dstRect.h = _srcRect.h * scaleY;
}

SDL_Rect Object::getRect() const
{
	return _dstRect;
}

void Object::setVisible(bool visible)
{
	_visible = visible;

	_opacity = _visible ? 255 : 0;

	SDL_SetTextureAlphaMod(
		TextureManager::getInstance()->getTextureMap()[_ID], _opacity);
}

bool Object::isVisible() const
{
	return _visible;
}
