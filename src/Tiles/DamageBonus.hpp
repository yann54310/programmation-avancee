#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class DamageBonus : public Tile
{
    private:

    public:
        DamageBonus();
        DamageBonus(const float x, const float y);
        ~DamageBonus();
};