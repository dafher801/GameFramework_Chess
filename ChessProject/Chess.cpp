#include <SDL_image.h>

#include "Chess.h"

Chess::Chess()
	: _running(true) {}

bool Chess::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (_window != nullptr)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
		}
	}
	else
	{
		return false;
	}

	_board = Sprite::create(_renderer, "assets/images/Board.jpg");
	_board->setPosition(width / 2, height / 2);
	_objects.push_back(_board);
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_pieces[i][j] = Piece::create(_renderer, { i,j });
			_objects.push_back(_pieces[i][j]);

			/*_pieces[i][j]->makeMoveButton("assets/images/MoveButton.png");
			_pieces[i][j]->makeAttackButton("assets/images/AttackButton.png");
			_pieces[i][j]->getMoveButton()->setVisible(false);
			_pieces[i][j]->getAttackButton()->setVisible(false);*/
		}
	}

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

void Chess::render()
{
	SDL_RenderClear(_renderer);

	for (Object * object : _objects)
		object->render();

	SDL_RenderPresent(_renderer);
}

void Chess::update()
{
	for (Object * object : _objects)
		object->update();
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

void Chess::clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}