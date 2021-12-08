#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "Time.hpp"

#define FRAME_PER_SECOND 1

class Game{
    private:
        Time _time;
        bool _isPlaying;

    public:
        Game();
        ~Game();

        void start();
        bool isPlaying() const;
};