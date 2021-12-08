#include "Time.hpp"

Time::Time(unsigned int fps) : _tStart(getActualTime()), _tLastFrame(_tStart), _timeFrame(1000/fps)
{

}

Time::~Time()
{

}

std::chrono::time_point<std::chrono::system_clock> Time::getActualTime() const
{
    return std::chrono::system_clock::now();
}

float Time::getElapsedTime() const
{
    return ((std::chrono::duration<float>)(getActualTime() - _tStart)).count()*1000;
}

float Time::getDeltaTime() const
{
    return ((std::chrono::duration<float>)(getActualTime() - _tLastFrame)).count()*1000;
}

void Time::startFrame()
{
    _tLastFrame = std::chrono::system_clock::now();
}

inline void Time::sleep(unsigned int time) const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Time::sleepUntilNextFrame() const
{
    if(getDeltaTime() < _timeFrame)
        sleep(_timeFrame - getDeltaTime());
}