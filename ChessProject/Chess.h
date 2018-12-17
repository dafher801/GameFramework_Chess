#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Board.h"
#include "TextureManager.h"

#define FPS 60
#define DELAY_TIME 0.06f

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

	void changeTurn();

	bool isChecked() const;

	bool gameOver();

	Object * getCheckmate() const;
	Object * getStalemate() const;

private:
	Chess();

	static Chess * _chess;

	SDL_Window * _window;
	SDL_Renderer * _renderer;
	SDL_Rect _rect;

	Board * _board;

	bool _running;
	Unit::TEAM _nowTurn;
	ObjectManager _objects;

	Object * _checkmate;
	Object * _stalemate;
};