#pragma once

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include "Time.hpp"
#include "Utils.hpp"
#include "Generation.hpp"
#include "Tiles.hpp"
#include "Menu.hpp"

#define GOLD_NUMBER 1.618033988749894

#define WINDOW_WIDTH 2*GOLD_NUMBER*SIZE_OF_TILES*WIDTH_OF_ROOM
#define WINDOW_HEIGHT 2*GOLD_NUMBER*SIZE_OF_TILES*HEIGHT_OF_ROOM

class Game{
    private:
        bool _isPlaying;
        Utils* _utils; //Use static var, no need to free

    public:
        Game();
        ~Game();

        bool isPlaying() const;
        void start();
};