#pragma once

#include <iostream>
#include <ctime>
#include <sys/time.h>

typedef unsigned long msec_t;

class Game{
    private:
        msec_t _tStart;
        msec_t _tLastFrame;
        bool _isPlaying;

    public:
        Game();
        ~Game();

        void start();
        inline msec_t getElapsedTime() const;
        inline msec_t getActualTime() const;
        inline msec_t getDeltaTime() const;
        inline bool isPlaying() const;
};