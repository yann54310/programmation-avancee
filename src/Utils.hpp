#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "StateManager.hpp"

class Utils{
    protected:
        Utils();

    public:
        StateManager* _stateMan; //Use static var, no need to free
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        SDL_Event _events;
        
        ~Utils();

        static Utils *GetInstance();
        Utils(Utils &other) = delete;
        void operator=(const Utils &) = delete;
};