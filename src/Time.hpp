#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class Time{
    private:
        std::chrono::time_point<std::chrono::system_clock> _tStart;
        std::chrono::time_point<std::chrono::system_clock> _tLastFrame;
        float _timeFrame;

        inline void sleep(unsigned int time) const;

    public:
        Time(unsigned int fps);
        ~Time();

        float getElapsedTime() const;
        std::chrono::time_point<std::chrono::system_clock> getActualTime() const;
        float getDeltaTime() const;
        void startFrame() ;
        void sleepUntilNextFrame() const;
};