#pragma once

#include <SDL2/SDL.h>

#include "Utils.hpp"

class GraphicObject
{
    protected:
        Utils* _utils;
        SDL_Rect _rect;
        SDL_Texture* _texture;
        bool _needUpdate;

    public:
        GraphicObject() = default;
        virtual ~GraphicObject() = default;
};
