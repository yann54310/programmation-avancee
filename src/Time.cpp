#include "Time.hpp"

Time::Time() : _tStart(getActualTime()), _tLastFrame(_tStart)
{

}

Time::~Time()
{

}

msec_t Time::getActualTime() const
{
    static struct timeval _tempTimeval{};

    gettimeofday(&_tempTimeval, nullptr);
    return (_tempTimeval.tv_sec * 1000) + (_tempTimeval.tv_usec / 1000);
}

msec_t Time::getElapsedTime() const
{
    return getActualTime() - _tStart;
}

msec_t Time::getDeltaTime() const
{
    return getActualTime() - _tLastFrame;
}
