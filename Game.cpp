#include "Game.h"

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if ((IMG_Init(flags) & flags) != flags)
	{
		return false;
	}

	window = SDL_CreateWindow("Strange Awakening",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0);

	if (window == nullptr)
	{
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		return false;
	}
	
	{
		SDL_Surface* surface = IMG_Load("sprites.png");
		if (surface == nullptr)
		{
			return false;
		}
		spritesTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}

	{
		SDL_Surface* surface = IMG_Load("player.png");
		if (surface == nullptr)
		{
			return false;
		}
		playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
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
	player.Update(map.GetCollisionBoxes());
}

void Game::RenderFrame()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	int cameraX = -(int)player.GetX() + (640 / 2 - 48 / 2);
	int cameraY = -(int)player.GetY() + (480 / 2 - 48 / 2);

	std::vector<Sprite> sprites = map.GetSprites();
	std::vector<Box> collisionBoxes = map.GetCollisionBoxes();

	std::map<Sprites, SpriteProperties> spritesProperties = map.GetSpritesProperties();

	// Sprites behind the player
	for (int i = 0; i < sprites.size(); i++)
	{
		SpriteProperties sprite = spritesProperties[sprites[i].item];
		if (!sprite.relief || sprites[i].y < player.GetY())
		{
			SDL_Rect srcRect = { sprite.x, sprite.y, sprite.w, sprite.h };
			SDL_Rect dstRect = { sprites[i].x + cameraX, sprites[i].y + cameraY, srcRect.w * 3, srcRect.h * 3 };
			SDL_RenderCopy(renderer, spritesTexture, &srcRect, &dstRect);
		}
	}

	// Player
	SDL_Rect srcRect = { player.GetSpriteX(), player.GetSpriteY(), 16, 16};
	SDL_Rect dstRect = { 640 / 2 - 48 / 2, 480 / 2 - 48 / 2, 48, 48 };
	SDL_RenderCopy(renderer, playerTexture, &srcRect, &dstRect);

	// Sprites in front of the player
	for (int i = 0; i < sprites.size(); i++)
	{
		SpriteProperties sprite = spritesProperties[sprites[i].item];
		if (sprite.relief && sprites[i].y >= player.GetY())
		{
			SDL_Rect srcRect = { sprite.x, sprite.y, sprite.w, sprite.h };
			SDL_Rect dstRect = { sprites[i].x + cameraX, sprites[i].y + cameraY, srcRect.w * 3, srcRect.h * 3 };
			SDL_RenderCopy(renderer, spritesTexture, &srcRect, &dstRect);
		}
	}

	// Collision boxes
	if (showCollisionBoxes)
	{
		for (int i = 0; i < collisionBoxes.size(); i++)
		{
			SDL_Rect rect =
			{
				collisionBoxes[i].x + cameraX,
				collisionBoxes[i].y + cameraY,
				collisionBoxes[i].w,
				collisionBoxes[i].h
			};
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}

	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyTexture(spritesTexture);
	SDL_DestroyTexture(playerTexture);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();
}