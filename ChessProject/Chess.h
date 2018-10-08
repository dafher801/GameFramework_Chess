#pragma once

#include <SDL.h>
#include <vector>

#include "Piece.h"
#include "Sprite.h"

#define LENGTH 8

typedef std::vector<Object*> ObjectManager;

class Chess
{
public:
	Chess();
	~Chess() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return _running; }

private:
	SDL_Window * _window;
	SDL_Renderer * _renderer;
	bool _running;

	Sprite * _board;

	Sprite * sample[LENGTH][LENGTH];

	Piece * _pieces[LENGTH][LENGTH];

	ObjectManager _objects;
};