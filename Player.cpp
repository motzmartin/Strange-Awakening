#include "Player.h"

Player::Player()
{
	movementTimer.Start();
	spriteTimer.Start();
}

void Player::Update(std::vector<Box> collisionBoxes)
{
	double elasped = movementTimer.GetMilisecondsElapsed();
	movementTimer.Restart();

	double coefficient = 0.15 * elasped;

	const Uint8* keyboard = SDL_GetKeyboardState(nullptr);

	int xTemp = (int)x;
	int yTemp = (int)y;

	if (keyboard[SDL_SCANCODE_A] != keyboard[SDL_SCANCODE_D])
	{
		double accelerationX = 0.0;

		if (keyboard[SDL_SCANCODE_A]) accelerationX = -coefficient;
		else accelerationX = coefficient;

		x += accelerationX;

		for (int i = 0; i < collisionBoxes.size(); i++)
		{
			if ((int)x + 48 > collisionBoxes[i].x &&
				(int)y + 48 > collisionBoxes[i].y &&
				(int)x < collisionBoxes[i].x + collisionBoxes[i].w &&
				(int)y < collisionBoxes[i].y + collisionBoxes[i].h)
			{
				if (accelerationX < 0.0)
				{
					x = (double)(collisionBoxes[i].x + collisionBoxes[i].w);
				}
				else
				{
					x = (double)(collisionBoxes[i].x - 48);
				}

				break;
			}
		}
	}

	if (keyboard[SDL_SCANCODE_W] != keyboard[SDL_SCANCODE_S])
	{
		double accelerationY = 0.0;

		if (keyboard[SDL_SCANCODE_W]) accelerationY = -coefficient;
		else accelerationY = coefficient;

		y += accelerationY;

		for (int i = 0; i < collisionBoxes.size(); i++)
		{
			if ((int)x + 48 > collisionBoxes[i].x &&
				(int)y + 48 > collisionBoxes[i].y &&
				(int)x < collisionBoxes[i].x + collisionBoxes[i].w &&
				(int)y < collisionBoxes[i].y + collisionBoxes[i].h)
			{
				if (accelerationY < 0.0)
				{
					y = (double)(collisionBoxes[i].y + collisionBoxes[i].h);
				}
				else
				{
					y = (double)(collisionBoxes[i].y - 48);
				}

				break;
			}
		}
	}

	double spriteElapsed = spriteTimer.GetMilisecondsElapsed();
	if (spriteElapsed >= 150.0)
	{
		spriteX += 16;
		if (spriteX > 4 * 16)
		{
			spriteX = 16;
		}
		spriteTimer.Restart();
	}

	if ((int)x < xTemp)
	{
		spriteY = 16;
	}
	else if ((int)x > xTemp)
	{
		spriteY = 48;
	}
	else if ((int)y < yTemp)
	{
		spriteY = 32;
	}
	else if ((int)y > yTemp)
	{
		spriteY = 0;
	}
	else
	{
		spriteX = 0;
	}
}

double Player::GetX()
{
	return x;
}

double Player::GetY()
{
	return y;
}

int Player::GetSpriteX()
{
	return spriteX;
}

int Player::GetSpriteY()
{
	return spriteY;
}