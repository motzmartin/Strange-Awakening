#include "Timer.h"

Timer::Timer()
{
	auto now = std::chrono::high_resolution_clock::now();

	start = now;
	stop = now;
}

bool Timer::Start()
{
	if (isRunning)
	{
		return false;
	}

	start = std::chrono::high_resolution_clock::now();
	isRunning = true;

	return true;
}

bool Timer::Stop()
{
	if (!isRunning)
	{
		return false;
	}

	stop = std::chrono::high_resolution_clock::now();
	isRunning = false;

	return true;
}

void Timer::Restart()
{
	start = std::chrono::high_resolution_clock::now();
	isRunning = true;
}

double Timer::GetMilisecondsElapsed()
{
	std::chrono::duration<double, std::milli> elasped;

	if (isRunning)
	{
		elasped = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - start);
	}
	else
	{
		elasped = std::chrono::duration<double, std::milli>(stop - start);
	}

	return elasped.count();
}