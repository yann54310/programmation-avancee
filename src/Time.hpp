#pragma once

#include <iostream>
#include <chrono>

class Time{
    private:
        std::chrono::time_point<std::chrono::system_clock> _tStart;
        std::chrono::time_point<std::chrono::system_clock> _tLastFrame;

    public:
        Time();
        ~Time();

        double getElapsedTime() const;
        std::chrono::time_point<std::chrono::system_clock> getActualTime() const;
        double getDeltaTime() const;
        void setLastFrame();
};