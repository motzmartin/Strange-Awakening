#pragma once

#include <SDL.h>
#include <vector>
#include <map>

enum Sprites
{
	BEDROOM_FLOOR,
	BEDROOM_WALL,
	BATHROOM_FLOOR,
	BATHROOM_WALL,
	BED,
	BOOKCASE,
	RAILING,
	STAIRS,
	RED_CARPET,
	TEDDY_BEAR,
	MARBLES,
	TOILET,
	BATHTUB,
	SINK,
	DOOR,
	PURPLE_CARPET,
	BLACK
};

struct SpriteProperties
{
	int x;
	int y;
	int w;
	int h;
	bool relief;
};

struct Sprite
{
	int x;
	int y;
	Sprites item;
};

struct Box
{
	int x;
	int y;
	int w;
	int h;
};

class Map
{
public:
	Map();

	std::vector<Sprite> GetSprites();
	std::vector<Box> GetCollisionBoxes();

	std::map<Sprites, SpriteProperties> GetSpritesProperties();

private:
	void AddSprite(int x, int y, Sprites tile);
	void AddSprites(int x, int y, int w, int h, Sprites tile);
	void AddCollisionBox(int x, int y, int w, int h);

	std::vector<Sprite> sprites;
	std::vector<Box> collisionBoxes;

	std::map<Sprites, SpriteProperties> spritesProperties =
	{
		{ Sprites::BEDROOM_FLOOR, { 0, 0, 16, 16, false } },
		{ Sprites::BEDROOM_WALL, { 16, 0, 16, 16, false } },
		{ Sprites::BATHROOM_FLOOR, { 32, 0, 16, 16, false } },
		{ Sprites::BATHROOM_WALL, { 48, 0, 16, 16, false } },
		{ Sprites::BED, { 0, 16, 32, 32, false } },
		{ Sprites::BOOKCASE, { 32, 16, 16, 16, false } },
		{ Sprites::RAILING, { 48, 16, 16, 16, true } },
		{ Sprites::STAIRS, { 32, 32, 32, 16, false } },
		{ Sprites::RED_CARPET, { 64, 0, 64, 32, false } },
		{ Sprites::TEDDY_BEAR, { 64, 32, 16, 16, true } },
		{ Sprites::MARBLES, { 80, 32, 16, 16, false } },
		{ Sprites::TOILET, { 96, 32, 16, 16, true } },
		{ Sprites::BATHTUB, { 112, 32, 16, 32, false } },
		{ Sprites::SINK, { 96, 48, 16, 16, true } },
		{ Sprites::DOOR, { 64, 48, 16, 16, false } },
		{ Sprites::PURPLE_CARPET, { 80, 48, 16, 32, false } },
		{ Sprites::BLACK, { 48, 48, 16, 16, true } }
	};
};