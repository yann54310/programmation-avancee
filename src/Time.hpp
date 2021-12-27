#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include "Define.hpp"

class Time{
    private:
        std::chrono::time_point<std::chrono::system_clock> _tStart;
        std::chrono::time_point<std::chrono::system_clock> _tLastFrame;
        float _timePerFrame;

        inline void sleep(unsigned int time) const;

    public:
        Time(float fps);
        ~Time();

        float getElapsedTime() const;
        std::chrono::time_point<std::chrono::system_clock> getActualTime() const;
        float getDeltaTime() const;
        float getTimePerFrame() const;
        void startFrame();
        void sleepUntilNextFrame() const;
};