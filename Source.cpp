#include "Game.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")

int SDL_main(int argc, char* argv[])
{
	Game game;

	if (game.Initialize())
	{
		while (game.PollEvents())
		{
			game.Update();
			game.RenderFrame();
		}

		game.Destroy();
	}

	return 0;
}