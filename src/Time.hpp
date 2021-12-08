#pragma once

#include <iostream>
#include <ctime>
#include <sys/time.h>

typedef unsigned long msec_t;

class Time{
    private:
        msec_t _tStart;
        msec_t _tLastFrame;

    public:
        Time();
        ~Time();

        msec_t getElapsedTime() const;
        msec_t getActualTime() const;
        msec_t getDeltaTime() const;
};