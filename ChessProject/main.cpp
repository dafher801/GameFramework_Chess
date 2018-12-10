#include "Chess.h"

int main(int argc, char * argv[])
{
	Uint32 frameStart;
	Uint32 frameTime;

	if (Chess::getInstance()->init("ChessGame", 400, 100, 1100, 900, false))
	{
		while (Chess::getInstance()->running())
		{
			frameStart = SDL_GetTicks();

			Chess::getInstance()->handleEvents();
			Chess::getInstance()->update();
			Chess::getInstance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < 1000 / 60)
				SDL_Delay((int)(1000 / 60 - frameTime));
		}
	}

	Chess::getInstance()->quit();
	return 0;
}