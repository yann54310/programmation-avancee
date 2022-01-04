#pragma once

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Error.hpp"
#include "Define.hpp"
#include "Tiles/Tile.hpp"
#include "Utils.hpp"

class Bullet;

class Player : public Tile
{
    private:
        static SDL_Point _sprites[4];
        static int UP;
        static int RIGHT;
        static int DOWN;
        static int LEFT;
        int vx, vy;
        std::shared_ptr<Room> _tiles;

    public:
        Player();
        Player(const float x, const float y);
        ~Player();

        void Draw();

        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

        void setTiles(std::shared_ptr<Room> _tiles);

        int getVx();
        int getVy();
};

#include "Bullet.hpp"