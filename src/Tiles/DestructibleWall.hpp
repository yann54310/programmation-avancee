#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class DestructibleWall : public Tile
{
    private:

    public:
        DestructibleWall();
        DestructibleWall(const float x, const float y);
        ~DestructibleWall();
};