#pragma once

#include <SDL.h>

#include "Timer.h"
#include "Map.h"

class Player
{
public:
	Player();

	void Update(std::vector<Box> collisionBoxes);

	double GetX();
	double GetY();

	int GetSpriteX();
	int GetSpriteY();

private:
	Timer movementTimer;
	Timer spriteTimer;

	double x = 5.0 * 48.0;
	double y = 48.0 + 12.0;

	int spriteX = 0;
	int spriteY = 0;

	int sprite = 0;
};