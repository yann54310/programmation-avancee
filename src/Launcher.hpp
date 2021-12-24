#pragma once

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Error.hpp"
#include "Time.hpp"
#include "Utils.hpp"
#include "Tiles/Tile.hpp"
#include "Tiles/Generation.hpp"
#include "States/Menu.hpp"

class Launcher{
    private:
        bool _isPlaying;
        Utils* _utils; //Use static var, no need to free

    public:
        Launcher();
        ~Launcher();

        bool isPlaying() const;
        void start();
};