#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Game
{
public:
	bool Initialize();
	bool PollEvents();
	void Update();
	void RenderFrame();
	void Destroy();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};
