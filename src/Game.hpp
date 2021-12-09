#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "Time.hpp"
#include "Utils.hpp"

#define FRAME_PER_SECOND 1

class Game{
    private:
        Time _time;
        bool _isPlaying;
        Utils* _utils; //Use static var, no need to free

    public:
        Game();
        ~Game();

        void start();
        bool isPlaying() const;
};