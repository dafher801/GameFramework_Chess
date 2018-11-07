#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Piece.h"
#include "Sprite.h"
#include "TextureManager.h"

#define LENGTH 8

typedef std::vector<Object*> ObjectManager;

class Chess
{
public:
	Chess();
	~Chess() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

	static Chess * getInstance();

	SDL_Renderer * getRenderer() const;

private:

	static Chess * _chessGame;

	SDL_Window * _window;
	SDL_Renderer * _renderer;
	bool _running;

	Sprite * _board;

	Sprite * sample[LENGTH][LENGTH];

	Piece * _pieces[LENGTH][LENGTH];

	ObjectManager _objects;
};