#include "Chess.h"

Chess * Chess::_chessGame = nullptr;

Chess::Chess()
	: _running(true) {}

bool Chess::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (_window != nullptr)
			_renderer = SDL_CreateRenderer(_window, -1, 0);
	}
	else
		return false;

	SDL_Surface * surface = IMG_Load("assets/images/Board.jpg");

	if (!TextureManager::getInstance()->load(surface, "Board", _renderer))
		return false;



	for (int i = 0; i < LENGTH; i++)
	{
		_pieces[i][LENGTH - 2]->makeUnit(Unit::NAME::PAWN, Unit::TEAM::WHITE);
		_pieces[i][1]->makeUnit(Unit::NAME::PAWN, Unit::TEAM::BLACK);
	}

	_pieces[1][LENGTH - 1]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::WHITE);
	_pieces[6][LENGTH - 1]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::WHITE);
	_pieces[1][0]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::BLACK);
	_pieces[6][0]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::BLACK);

	_pieces[2][LENGTH - 1]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::WHITE);
	_pieces[5][LENGTH - 1]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::WHITE);
	_pieces[2][0]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::BLACK);
	_pieces[5][0]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::BLACK);

	_pieces[LENGTH - 1][LENGTH - 1]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::WHITE);
	_pieces[0][LENGTH - 1]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::WHITE);
	_pieces[LENGTH - 1][0]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::BLACK);
	_pieces[0][0]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::BLACK);

	_pieces[3][LENGTH - 1]->makeUnit(Unit::NAME::QUEEN, Unit::TEAM::WHITE);
	_pieces[3][0]->makeUnit(Unit::NAME::QUEEN, Unit::TEAM::BLACK);

	_pieces[4][LENGTH - 1]->makeUnit(Unit::NAME::KING, Unit::TEAM::WHITE);
	_pieces[4][0]->makeUnit(Unit::NAME::KING, Unit::TEAM::BLACK);

	return true;
}

void Chess::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_running = false;
			break;
		default:
			break;
		}
	}
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

void Chess::clean()
{
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
	if (!_chessGame)
		_chessGame = new Chess;

	return _chessGame;
}

SDL_Renderer * Chess::getRenderer() const
{
	return _renderer;
}