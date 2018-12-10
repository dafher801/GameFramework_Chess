#include "Chess.h"
#include "Object.h"
#include "TextureManager.h"
#include "ActionManager.h"

Object::Object(std::string fileName, std::string id)
	: _ID(id)
	, _fileName(fileName)
	, _position(0, 0)
	, _velocity(0, 0)
	, _acceleration(0, 0)
	, _visible(true)
	, _opacity(255) {}

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

	SDL_SetTextureBlendMode(
		TextureManager::getInstance()->getTextureMap()[_ID], SDL_BLENDMODE_BLEND);

	_srcRect.x = _srcRect.y = 0;
	_dstRect.w = _srcRect.w = surface->w;
	_dstRect.h = _srcRect.h = surface->h;

	setAnchorPoint(0.5, 0.5);
	setPosition(0, 0);
	setScale(1.0f);

	SDL_FreeSurface(surface);
	return true;
}

void Object::update()
{
	for (Object * iter : _objects)
		iter->update();
}

void Object::draw()
{
	TextureManager::getInstance()->draw(_ID, _dstRect.x,
		_dstRect.y, _dstRect.w, _dstRect.h, Chess::getInstance()->getRenderer());

	for (Object * iter : _objects)
		iter->draw();
}

void Object::addChild(Object * object)
{
	_objects.push_back(object);
}

void Object::removeChild(Object * object)
{
	for (std::vector<Object*>::iterator iter = _objects.begin();
		object->_ID == (*iter)->_ID; iter++)
	{
		_objects.erase(iter);
	}
}

void Object::setPosition(float x, float y)
{
	_position.setX(x);
	_position.setY(y);

	_dstRect.x = x - (_srcRect.w * _anchorX);
	_dstRect.y = y - (_srcRect.h * _anchorY);

	setScaleX(_scaleX);
	setScaleY(_scaleY);

	for (Object * iter : _objects)
		iter->setPosition(x, y);
}

Vector2D Object::getPosition() const
{
	return _position;
}

void Object::setAnchorPoint(float x, float y)
{
	_anchorX = x;
	_anchorY = y;

	setPosition(_position.getX(), _position.getY());
}

void Object::setScale(float scale)
{
	setScaleX(scale);
	setScaleY(scale);
}

void Object::setScaleX(float scaleX)
{
	if (scaleX)
		_scaleX = scaleX;

	_dstRect.w = _srcRect.w * scaleX;
	_dstRect.x = _position.getX() - (float)(_srcRect.w * _anchorX * scaleX);

	for (Object * iter : _objects)
		iter->setScaleX(scaleX);
}

void Object::setScaleY(float scaleY)
{
	if (scaleY)
		_scaleY = scaleY;

	_dstRect.h = _srcRect.h * scaleY;
	_dstRect.y = _position.getY() - (float)(_srcRect.h * _anchorY * scaleY);

	for (Object * iter : _objects)
		iter->setScaleY(scaleY);
}

SDL_Rect Object::getRect() const
{
	return _dstRect;
}

void Object::setVisible(bool visible)
{
	_visible = visible;

	if (_visible)
	{
		setScaleX(_scaleX);
		setScaleY(_scaleY);
	}
	else
		setScale(0);

	for (Object * iter : _objects)
		iter->setVisible(_visible);
}

bool Object::isVisible() const
{
	return _visible;
}

Action * Object::runAction(Action * action)
{
	ActionManager::getInstance()->addAction(action, this);
	return action;
}