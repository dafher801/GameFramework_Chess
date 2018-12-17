#include "Chess.h"
#include "InputHandler.h"
#include "ActionManager.h"
#include "UnitManager.h"
#include "CastlingManager.h"
#include "PromotionManager.h"

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

	_board = Board::getInstance();
	_objects.push_back(_board);

	_checkmate = Object::create("assets/images/Checkmate.png", "Checkmate");
	_checkmate->setPosition(getRect().w / 2, getRect().h / 12);
	_checkmate->setVisible(false);
	_objects.push_back(_checkmate);

	_stalemate = Object::create("assets/images/Stalemate.png", "Stalemate");
	_stalemate->setPosition(getRect().w / 2, getRect().h / 12);
	_stalemate->setVisible(false);
	_objects.push_back(_stalemate);
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

	ActionManager::getInstance()->update();
	CastlingManager::getInstance()->update();
	PromotionManager::getInstance()->update();
}

void Chess::render()
{
	SDL_RenderClear(_renderer);

	for (Object * object : _objects)
		object->draw();

	CastlingManager::getInstance()->draw();
	PromotionManager::getInstance()->draw();

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

void Chess::changeTurn()
{
	switch (_nowTurn)
	{
	case Unit::TEAM::BLACK:
		_nowTurn = Unit::TEAM::WHITE;
		break;
	case Unit::TEAM::WHITE:
		_nowTurn = Unit::TEAM::BLACK;
		break;
	}
}

bool Chess::isChecked() const
{
	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->isChecking())
			return true;
	}

	return false;
}

bool Chess::gameOver()
{
	int i;
	int j;
	bool gameOver = true;

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (_nowTurn == iter->getTeam())
		{
			iter->getCommand().front()->execute();

			for (i = 0; i < LENGTH; i++)
			{
				for (j = 0; j < LENGTH; j++)
				{
					if (Board::getInstance()->getPieces()[i][j]->getMoveButton()->isVisible())
					{
						Board::getInstance()->getPieces()[i][j]->getMoveButton()->setVisible(false);
						gameOver = false;
					}
				}
			}
		}
	}

	return gameOver;
}

Object * Chess::getCheckmate() const
{
	return _checkmate;
}

Object * Chess::getStalemate() const
{
	return _stalemate;
}
