#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class Void : public Tile
{
    private:

    public:
        Void();
        Void(const float x, const float y);
        ~Void();
};