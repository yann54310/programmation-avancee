#pragma once

#include <SDL2/SDL.h>

#include "../Utils.hpp"
#include "../Error.hpp"

class GraphicObject
{
    protected:
        Utils* _utils;
        SDL_Rect _rect;
        SDL_Texture* _texture;
        bool _needUpdate;

        GraphicObject();
        GraphicObject(SDL_Rect& rect);
        ~GraphicObject();

    public:
        void Load(SDL_Surface*& tmpSurf);
        void Draw();

        void SetPos(const int x, const int y);
        void SetRect(const int x, const int y, const int w, const int h);
        void SetRect(const SDL_Rect rect);
        void SetX(const int x);
        void SetY(const int y);
        void SetW(const int w);
        void SetH(const int h);
};
