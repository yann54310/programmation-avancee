#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "Time.hpp"

#define FRAME_PER_SECOND 60

class StateManager;

class Utils{
    protected:
        Utils();

    public:
        StateManager* _stateMan; //Use static var, no need to free
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        SDL_Event _events;
        Time _time;
        
        ~Utils();

        static Utils *GetInstance();
        Utils(Utils &other) = delete;
        void operator=(const Utils &) = delete;
};

#include "StateManager.hpp"