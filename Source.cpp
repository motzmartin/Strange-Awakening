#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;

	if (!game.Initialize())
	{
		return 1;
	}

	while (game.PollEvents())
	{
		game.Update();
		game.RenderFrame();
	}

	game.Destroy();

	return 0;
}