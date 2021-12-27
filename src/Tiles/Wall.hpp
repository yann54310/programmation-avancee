#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class Wall : public Tile
{
    private:

    public:
        Wall();
        Wall(const float x, const float y);
        ~Wall();
};