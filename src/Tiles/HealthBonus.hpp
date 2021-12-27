#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class HealthBonus : public Tile
{
    private:

    public:
        HealthBonus();
        HealthBonus(const float x, const float y);
        ~HealthBonus();
};