#include "Board.h"
#include "Chess.h"

Board * Board::_board = nullptr;

Board::Board()
	: Object("assets/images/Board.jpg", "Board")
	, _boardScale(1.1) {}

Board * Board::getInstance()
{
	if (!_board)
		_board = Board::create();

	return _board;
}

bool Board::init()
{
	if ( !Object::init() )
	{
		return false;
	}

	int i, j;

	setPosition(Chess::getInstance()->getRect().w / 2,
		Chess::getInstance()->getRect().h / 2);

	setScale(_boardScale);

	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
			_pieces[i][j] = Piece::create(i, j);

	for (i = 0; i < LENGTH; i++)
	{
		_pieces[i][1]->makeUnit(Unit::NAME::PAWN, Unit::TEAM::BLACK);
		_pieces[i][6]->makeUnit(Unit::NAME::PAWN, Unit::TEAM::WHITE);
	}

	_pieces[1][0]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::BLACK);
	_pieces[6][0]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::BLACK);
	_pieces[1][7]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::WHITE);
	_pieces[6][7]->makeUnit(Unit::NAME::KNIGHT, Unit::TEAM::WHITE);

	_pieces[2][0]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::BLACK);
	_pieces[5][0]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::BLACK);
	_pieces[2][7]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::WHITE);
	_pieces[5][7]->makeUnit(Unit::NAME::BISHOP, Unit::TEAM::WHITE);

	_pieces[0][0]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::BLACK);
	_pieces[7][0]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::BLACK);
	_pieces[0][7]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::WHITE);
	_pieces[7][7]->makeUnit(Unit::NAME::ROOK, Unit::TEAM::WHITE);

	_pieces[3][0]->makeUnit(Unit::NAME::QUEEN, Unit::TEAM::BLACK);
	_pieces[3][7]->makeUnit(Unit::NAME::QUEEN, Unit::TEAM::WHITE);

	_pieces[4][0]->makeUnit(Unit::NAME::KING, Unit::TEAM::BLACK);
	_pieces[4][7]->makeUnit(Unit::NAME::KING, Unit::TEAM::WHITE);
	
	return true;
}

void Board::update()
{
	int i, j;
	Object::update();

	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
			_pieces[i][j]->update();
}

void Board::draw()
{
	int i, j;
	Object::draw();

	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
			_pieces[i][j]->draw();
}

Piece * (* Board::getPieces())[8]
{
	return _pieces;
}

Piece * Board::hash(int coord)
{
	if ((coord / 10 - 1 > LENGTH || coord % 10 - 1 < 0) ||
		(coord % 10 - 1 > LENGTH || coord % 10 - 1 < 0))
	{
		return nullptr;
	}

	return _pieces[coord / 10 - 1][coord % 10 - 1];
}
