#include "Chess.h"

int main(int argc, char * argv[])
{
	if (Chess::getInstance()->init("ChessGame", 400, 100, 1100, 900, false))
	{
		while (Chess::getInstance()->running())
		{
			Chess::getInstance()->handleEvents();
			Chess::getInstance()->update();
			Chess::getInstance()->render();
		}
	}

	Chess::getInstance()->clean();
	return 0;
}