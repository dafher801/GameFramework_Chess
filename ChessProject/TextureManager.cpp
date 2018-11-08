#include "TextureManager.h"

TextureManager * TextureManager::_instance = nullptr;

TextureManager::~TextureManager()
{
	for (std::pair<std::string, SDL_Texture*> iter : _textureMap)
	{
		SDL_DestroyTexture(iter.second);
		_textureMap.erase(iter.first);
	}
}

TextureManager * TextureManager::getInstance()
{
	if (!_instance)
		_instance = new TextureManager;

	return _instance;
}

std::map<std::string, SDL_Texture*> TextureManager::getTextureMap() const
{
	return _textureMap;
}

bool TextureManager::load(SDL_Surface * surface, std::string id, SDL_Renderer * renderer)
{
	if (!surface)
		return false;

	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture != nullptr)
	{
		_textureMap[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
