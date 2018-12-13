#include "Chess.h"
#include "InputHandler.h"
#include "ActionManager.h"
#include "UnitManager.h"

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
	Unit * king = nullptr;

	for (Unit * iter : UnitManager::getInstance()->getUnits())
	{
		if (iter->getName() == Unit::NAME::KING && iter->getTeam() == _nowTurn)
		{
			king = iter;
			break;
		}
	}

	return isCheckedByPawn(king) || isCheckedByKnight(king) || isCheckedByBishop(king) ||
		isCheckedByRook(king) || isCheckedByQueen(king) || isCheckedByKing(king);
}

bool Chess::isCheckedByPawn(Unit * king) const
{
	int direction;
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;

	switch (_nowTurn)
	{
	case Unit::TEAM::BLACK:
		direction = 1;
		break;
	case Unit::TEAM::WHITE:
		direction = -1;
		break;
	}

	if (x > 0 && _board->getPieces()[x - 1][y + direction]->getUnit() &&
		_board->getPieces()[x - 1][y + direction]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x - 1][y + direction]->getUnit()->getName() == Unit::NAME::PAWN)
	{
		return true;
	}

	if (x < LENGTH - 1 && _board->getPieces()[x + 1][y + direction]->getUnit() &&
		_board->getPieces()[x + 1][y + direction]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x + 1][y + direction]->getUnit()->getName() == Unit::NAME::PAWN)
	{
		return true;
	}

	return false;
}

bool Chess::isCheckedByKnight(Unit * king) const
{
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;

	//오른쪽 1칸, 위쪽 2칸
	if (x + 1 < LENGTH && y - 2 >= 0 &&
		_board->getPieces()[x + 1][y - 2]->getUnit() &&
		_board->getPieces()[x + 1][y - 2]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x + 1][y - 2]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//오른쪽 2칸, 위쪽 1칸
	if (x + 2 < LENGTH && y - 1 >= 0 &&
		_board->getPieces()[x + 2][y - 1]->getUnit() &&
		_board->getPieces()[x + 2][y - 1]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x + 2][y - 1]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//왼쪽 1칸, 위쪽 2칸
	if (x - 1 >= 0 && y - 2 >= 0 &&
		_board->getPieces()[x - 1][y - 2]->getUnit() &&
		_board->getPieces()[x - 1][y - 2]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x - 1][y - 2]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//왼쪽 2칸, 위쪽 1칸
	if (x - 2 >= 0 && y - 1 >= 0 &&
		_board->getPieces()[x - 2][y - 1]->getUnit() &&
		_board->getPieces()[x - 2][y - 1]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x - 2][y - 1]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//오른쪽 1칸, 아래쪽 2칸
	if (x + 1 < LENGTH && y + 2 < LENGTH &&
		_board->getPieces()[x + 1][y + 2]->getUnit() &&
		_board->getPieces()[x + 1][y + 2]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x + 1][y + 2]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//오른쪽 2칸, 아래쪽 1칸
	if (x + 2 < LENGTH && y + 1 < LENGTH &&
		_board->getPieces()[x + 2][y + 1]->getUnit() &&
		_board->getPieces()[x + 2][y + 1]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x + 2][y + 1]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//왼쪽 1칸, 아래쪽 2칸
	if (x - 1 >= 0 && y + 2 < LENGTH &&
		_board->getPieces()[x - 1][y + 2]->getUnit() &&
		_board->getPieces()[x - 1][y + 2]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x - 1][y + 2]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	//왼쪽 2칸, 아래쪽 1칸
	if (x - 2 >= 0 && y + 1 < LENGTH &&
		_board->getPieces()[x - 2][y + 1]->getUnit() &&
		_board->getPieces()[x - 2][y + 1]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[x - 2][y + 1]->getUnit()->getName() == Unit::NAME::KNIGHT)
	{
		return true;
	}

	return false;
}

bool Chess::isCheckedByBishop(Unit * king) const
{
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;
	int i;
	int j;

	//오른쪽 위 방향

	i = x + 1;
	j = y - 1;

	while (i < LENGTH && j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
		j--;
	}

	if (i < LENGTH && j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::BISHOP)
	{
		return true;
	}

	//오른쪽 아래 방향

	i = x + 1;
	j = y + 1;

	while (i < LENGTH && j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
		j++;
	}

	if (i < LENGTH && j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::BISHOP)
	{
		return true;
	}

	//왼쪽 아래 방향

	i = x - 1;
	j = y + 1;

	while (i >= 0 && j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
		j++;
	}

	if (i >= 0 && j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::BISHOP)
	{
		return true;
	}

	//왼쪽 위 방향

	i = x - 1;
	j = y - 1;

	while (i >= 0 && j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
		j--;
	}

	if (i >= 0 && j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::BISHOP)
	{
		return true;
	}

	return false;
}

bool Chess::isCheckedByRook(Unit * king) const
{
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;
	int i;
	int j;

	//위쪽 방향

	i = x;
	j = y - 1;

	while (j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		j--;
	}

	if (j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::ROOK)
	{
		return true;
	}

	//오른쪽 방향

	i = x + 1;
	j = y;

	while (i < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
	}

	if (i < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::ROOK)
	{
		return true;
	}

	//아래쪽 방향

	i = x;
	j = y + 1;

	while (j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		j++;
	}

	if (j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::ROOK)
	{
		return true;
	}

	//왼쪽 방향

	i = x - 1;
	j = y;

	while (i >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
	}

	if (i >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::ROOK)
	{
		return true;
	}

	return false;
}

bool Chess::isCheckedByQueen(Unit * king) const
{
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;
	int i;
	int j;

	//위쪽 방향

	i = x;
	j = y - 1;

	while (j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		j--;
	}

	if (j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//오른쪽 위 방향

	i = x + 1;
	j = y - 1;

	while (i < LENGTH && j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
		j--;
	}

	if (i < LENGTH && j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//오른쪽 방향

	i = x + 1;
	j = y;

	while (i < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
	}

	if (i < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//오른쪽 아래 방향

	i = x + 1;
	j = y + 1;

	while (i < LENGTH && j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i++;
		j++;
	}

	if (i < LENGTH && j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//아래쪽 방향

	i = x;
	j = y + 1;

	while (j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		j++;
	}

	if (j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//왼쪽 아래 방향

	i = x - 1;
	j = y + 1;

	while (i >= 0 && j < LENGTH && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
		j++;
	}

	if (i >= 0 && j < LENGTH &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//왼쪽 방향

	i = x - 1;
	j = y;

	while (i >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
	}

	if (i >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	//왼쪽 위 방향

	i = x - 1;
	j = y - 1;

	while (i >= 0 && j >= 0 && !_board->getPieces()[i][j]->getUnit())
	{
		i--;
		j--;
	}

	if (i >= 0 && j >= 0 &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::QUEEN)
	{
		return true;
	}

	return false;
}

bool Chess::isCheckedByKing(Unit * king) const
{
	int x = king->getCoord() / 10 - 1;
	int y = king->getCoord() % 10 - 1;
	int i;
	int j;

	//위쪽 방향

	i = x;
	j = y - 1;

	if (j >= 0 && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//오른쪽 위 방향

	i = x + 1;
	j = y - 1;

	if (i < LENGTH && j >= 0 && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//오른쪽 방향

	i = x + 1;
	j = y;

	if (i < LENGTH && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//오른쪽 아래 방향

	i = x + 1;
	j = y + 1;

	if (i < LENGTH && j < LENGTH && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//아래쪽 방향

	i = x;
	j = y + 1;

	if (j < LENGTH && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//왼쪽 아래 방향

	i = x - 1;
	j = y + 1;

	if (i >= 0 && j < LENGTH && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//왼쪽 방향

	i = x - 1;
	j = y;

	if (i >= 0 && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	//왼쪽 위 방향

	i = x - 1;
	j = y - 1;

	if (i >= 0 && j >= 0 && _board->getPieces()[i][j]->getUnit() &&
		_board->getPieces()[i][j]->getUnit()->getTeam() != _nowTurn &&
		_board->getPieces()[i][j]->getUnit()->getName() == Unit::NAME::KING)
	{
		return true;
	}

	return false;
}
