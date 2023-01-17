#pragma once

#include <SDL_image.h>

#include "Player.h"
#include "Map.h"

class Game
{
public:
	bool Initialize();
	bool PollEvents();
	void Update();
	void RenderFrame();
	void Destroy();

private:
	Player player;
	Map map;

	bool showCollisionBoxes = false;

	SDL_Texture* spritesTexture = nullptr;
	SDL_Texture* playerTexture = nullptr;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};