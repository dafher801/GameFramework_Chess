#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Board.h"
#include "TextureManager.h"

#define FPS 60
#define DELAY_TIME 1000.0f / FPS

typedef std::vector<Object*> ObjectManager;

class Chess
{
public:
	~Chess() {}

	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void quit();
	bool running();

	static Chess * getInstance();

	SDL_Renderer * getRenderer() const;

	SDL_Rect getRect() const;

	Unit::TEAM getNowTurn() const;

private:
	Chess();

	static Chess * _chess;

	SDL_Window * _window;
	SDL_Renderer * _renderer;
	SDL_Rect _rect;

	bool _running;
	Unit::TEAM _nowTurn;
	ObjectManager _objects;
};