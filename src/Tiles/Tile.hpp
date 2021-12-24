#pragma once

#include <array>

#include "../Define.hpp"

class Tile;
typedef std::array<std::array<std::unique_ptr<Tile>, WIDTH_OF_ROOM>, HEIGHT_OF_ROOM> Room;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Generation.hpp"
#include "../Utils.hpp"

class Tile{
    protected:
        Utils* _utils;
        SDL_Rect _rect;
        SDL_Rect _tilemapRect;
        SDL_Texture* _tilemap;
    public:
        Tile() = default;
        Tile(const SDL_Point& posInTilemap);
        ~Tile();

        void Draw();

        void SetPos(const int x, const int y);
        void SetX(const int x);
        void SetY(const int y);
};