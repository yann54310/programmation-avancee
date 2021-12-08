#include "Time.hpp"

Time::Time() : _tStart(getActualTime()), _tLastFrame(_tStart)
{

}

Time::~Time()
{

}

std::chrono::time_point<std::chrono::system_clock> Time::getActualTime() const
{
    return std::chrono::system_clock::now();
}

double Time::getElapsedTime() const
{
    return ((std::chrono::duration<double>)(getActualTime() - _tStart)).count()*1000;
}

double Time::getDeltaTime() const
{
    return ((std::chrono::duration<double>)(getActualTime() - _tLastFrame)).count()*1000;
}

void Time::setLastFrame()
{
    _tLastFrame = std::chrono::system_clock::now();
}
