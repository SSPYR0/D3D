#include "MyTimer.h"

using namespace std::chrono;

MyTimer::MyTimer() noexcept
{
	last = steady_clock::now();
}

float MyTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float MyTimer::Peek() const noexcept
{
	return duration<float>( steady_clock::now() - last ).count();
}
