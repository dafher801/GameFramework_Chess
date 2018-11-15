#include "Chess.h"
#include "InputHandler.h"

Chess * Chess::_chess = nullptr;

Chess::Chess()
	: _running(true) 
	, _nowTurn(Unit::TEAM::WHITE) {}

bool Chess::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		_rect.x = xpos;
		_rect.y = ypos;
		_rect.w = width;
		_rect.h = height;

		if (_window != nullptr)
			_renderer = SDL_CreateRenderer(_window, -1, 0);
	}
	else
		return false;

	_objects.push_back(Board::getInstance());
	return true;
}

void Chess::handleEvents()
{
	InputHandler::getInstance()->update();
}

void Chess::update()
{
	for (Object * object : _objects)
		object->update();
}

void Chess::render()
{
	SDL_RenderClear(_renderer);

	for (Object * object : _objects)
		object->draw();

	SDL_RenderPresent(_renderer);
}

void Chess::quit()
{
	_running = false;
	InputHandler::getInstance()->clean();

	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

bool Chess::running()
{
	return _running;
}

Chess * Chess::getInstance()
{
	if (!_chess)
		_chess = new Chess;

	return _chess;
}

SDL_Renderer * Chess::getRenderer() const
{
	return _renderer;
}

SDL_Rect Chess::getRect() const
{
	return _rect;
}

Unit::TEAM Chess::getNowTurn() const
{
	return _nowTurn;
}
