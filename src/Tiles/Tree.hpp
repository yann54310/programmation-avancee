#pragma once

#include <SDL2/SDL.h>

#include "Tile.hpp"

class Tree : public Tile
{
    private:

    public:
        Tree();
        Tree(const float x, const float y);
        ~Tree();
};