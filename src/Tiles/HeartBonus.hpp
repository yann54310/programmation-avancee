#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class HeartBonus : public Tile
{
    private:

    public:
        HeartBonus();
        HeartBonus(const float x, const float y);
        ~HeartBonus();
};