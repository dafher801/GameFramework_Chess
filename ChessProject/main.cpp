#include "Chess.h"

int main(int argc, char * argv[])
{
	Chess * chess = new Chess;
	
	chess->init("ChessGame", 400, 100, 1100, 900, false);

	while (chess->running())
	{
		chess->handleEvents();
		chess->update();
		chess->render();
	}

	chess->clean();
	return 0;
}