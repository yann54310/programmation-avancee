#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class Floor : public Tile
{
    private:

    public:
        Floor();
        Floor(const float x, const float y);
        ~Floor();
};