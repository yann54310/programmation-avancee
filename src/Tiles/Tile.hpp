#pragma once

#include <array>

#include "../Define.hpp"

#include "../Utils.hpp"

class Tile{
    protected:
        Utils* _utils;
        SDL_FRect _rect;
        SDL_Rect _drawRect;
        SDL_Rect _tilemapRect;
        SDL_Texture* _tilemap;
    public:
        //Tile() = default;
        Tile(const SDL_Point& posInTilemap);
        Tile(const float x, const float y, const SDL_Point& posInTilemap);
        ~Tile();

        void Draw();

        void SetPos(const float x, const float y);
        void SetX(const float x);
        void SetY(const float y);
};

typedef std::array<std::array<std::unique_ptr<Tile>, WIDTH_OF_ROOM>, HEIGHT_OF_ROOM> Room;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Generation.hpp"