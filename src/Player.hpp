#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Error.hpp"
#include "Define.hpp"
#include "Tiles/Tile.hpp"
#include "Utils.hpp"

class Player : public Tile
{
    private:
        static SDL_Point _sprites[5];
        static SDL_Point _die;
        static int nbSprite;
        int _timer;

    public:
        Player();
        Player(const float x, const float y);
        ~Player();

        void Draw();

        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
};
