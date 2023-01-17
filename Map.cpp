#include "Map.h"

Map::Map()
{
	AddSprites(5 * 48, 48, 7, 4, Sprites::BEDROOM_FLOOR);
	AddSprites(5 * 48, 0, 7, 1, Sprites::BEDROOM_WALL);

	AddSprites(0, 3 * 48, 3, 2, Sprites::BATHROOM_FLOOR);
	AddSprites(0, 2 * 48, 3, 1, Sprites::BATHROOM_WALL);
	
	AddSprites(3 * 48, 4 * 48, 2, 1, Sprites::BATHROOM_FLOOR);
	AddSprites(3 * 48, 3 * 48 + 24, 2, 1, Sprites::BATHROOM_WALL);

	AddSprite(5 * 48, 24, Sprites::BED);
	AddSprite(7 * 48, 24, Sprites::TEDDY_BEAR);
	AddSprite(6 * 48, 2 * 48, Sprites::RED_CARPET);
	AddSprite(8 * 48, 2 * 48, Sprites::MARBLES);
	AddSprite(11 * 48, 0, Sprites::BOOKCASE);
	AddSprite(10 * 48, 4 * 48, Sprites::STAIRS);
	AddSprite(11 * 48, 3 * 48, Sprites::RAILING);
	AddSprites(10 * 48, 4 * 48, 2, 1, Sprites::RAILING);

	AddSprite(0, 2 * 48 + 24, Sprites::TOILET);
	AddSprite(0, 4 * 48, Sprites::SINK);
	AddSprite(48, 3 * 48, Sprites::PURPLE_CARPET);
	AddSprite(2 * 48, 2 * 48 + 24, Sprites::BATHTUB);
	AddSprite(4 * 48, 3 * 48 + 24, Sprites::DOOR);

	AddSprites(0, 5 * 48, 12, 1, Sprites::BLACK);

	AddCollisionBox(7 * 48, 0, 5 * 48, 12);
	AddCollisionBox(48, 5 * 48 + 12, 11 * 48, 12);
	AddCollisionBox(12, 4 * 48 + 12, 12, 36);
	AddCollisionBox(-12, 3 * 48, 12, 48);
	AddCollisionBox(48, 2 * 48, 48, 12);
	AddCollisionBox(0, 2 * 48 + 24, 36, 12);
	AddCollisionBox(2 * 48, 2 * 48 + 24, 12, 48 + 12);
	AddCollisionBox(3 * 48, 3 * 48 + 24, 2 * 48, 12);
	AddCollisionBox(5 * 48 - 12, 48 + 12, 12, 2 * 48 - 12);
	AddCollisionBox(5 * 48, 48 - 12, 2 * 48, 12);
	AddCollisionBox(11 * 48, 4 * 48, 36, 12);
	AddCollisionBox(12 * 48, 48, 12, 4 * 48);
}

std::vector<Sprite> Map::GetSprites()
{
	return sprites;
}

std::vector<Box> Map::GetCollisionBoxes()
{
	return collisionBoxes;
}

std::map<Sprites, SpriteProperties> Map::GetSpritesProperties()
{
	return spritesProperties;
}

void Map::AddSprite(int x, int y, Sprites tile)
{
	sprites.push_back({ x, y, tile });
}

void Map::AddSprites(int x, int y, int w, int h, Sprites tile)
{
	SpriteProperties sprite = spritesProperties[tile];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			AddSprite(x + j * sprite.w * 3, y + i * sprite.h * 3, tile);
		}
	}
}

void Map::AddCollisionBox(int x, int y, int w, int h)
{
	collisionBoxes.push_back({ x, y, w, h });
}