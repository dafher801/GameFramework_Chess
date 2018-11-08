#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	~TextureManager();

	static TextureManager * getInstance();

	std::map<std::string, SDL_Texture*> getTextureMap() const;

	bool load(SDL_Surface * surface, std::string id, SDL_Renderer * renderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}

	static TextureManager * _instance;

	std::map<std::string, SDL_Texture*> _textureMap;
};
