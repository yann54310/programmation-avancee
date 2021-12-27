#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class SpeedBonus : public Tile
{
    private:

    public:
        SpeedBonus();
        SpeedBonus(const float x, const float y);
        ~SpeedBonus();
};