#include "Timer.hpp"
#include <iostream>

void Timer::start()
{
    startTime = std::chrono::steady_clock::now();
}

void Timer::stop()
{
    stopTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
    elapsedTimeNs = elapsed.count();
}

void Timer::print()
{
    printf("%lu ns\n", elapsedTimeNs);
}

unsigned long Timer::getElapsedMs()
{
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();
}

unsigned long Timer::getElapsedNs()
{
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now - startTime).count();
}
