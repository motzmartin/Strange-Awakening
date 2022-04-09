#include "Game.h"

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	int flags = IMG_INIT_PNG;

	int initted = IMG_Init(flags);

	if ((initted & flags) != flags)
	{
		return false;
	}

	if (TTF_Init() == -1)
	{
		return false;
	}

	if (Mix_OpenAudio(44100,
		MIX_DEFAULT_FORMAT,
		MIX_DEFAULT_CHANNELS,
		1024) == -1)
	{
		return false;
	}

	window = SDL_CreateWindow("Strange Awakening",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		return false;
	}

	return true;
}

bool Game::PollEvents()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			return false;
		}
	}

	return true;
}

void Game::Update()
{
}

void Game::RenderFrame()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}
