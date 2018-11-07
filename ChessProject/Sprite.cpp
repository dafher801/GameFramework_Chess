#include "Sprite.h"
#include "Chess.h"
#include <SDL.h>
#include <SDL_image.h>

Sprite::Sprite(std::string fileName, std::string id)
	: Object(fileName, id)
{
	
}

Sprite::~Sprite()
{
	/*SDL_FreeSurface(_surface);
	SDL_DestroyTexture(_texture);*/
}

Sprite * Sprite::create(std::string fileName, std::string id)
{
	Sprite * sprite = new Sprite(fileName, id);

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



	
	return true;
}

void Sprite::update()
{
	
}

void Sprite::render()
{
	SDL_RenderCopy(Chess::getInstance()->getRenderer(), _texture, &_srcRect, &_dstRect);
}
