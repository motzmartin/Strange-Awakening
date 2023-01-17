#pragma once

#include <chrono>

class Timer
{
public:
	Timer();

	bool Start();
	bool Stop();
	void Restart();
	double GetMilisecondsElapsed();

private:
	bool isRunning = false;

	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> stop;
};