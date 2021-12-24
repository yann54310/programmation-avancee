#pragma once

#include <iostream>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Define.hpp"
#include "Time.hpp"
#include "Font.hpp"
#include "Error.hpp"

class StateManager;

#include "Tiles/Tile.hpp"

class Utils{
    private:
        bool _IMG_WasInit;
        static Utils* _instance;

        Utils();

    public:
        StateManager* _stateMan; //Use static var, no need to free
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        SDL_Event _events;
        Time _time;
        std::unordered_map<std::string, std::shared_ptr<Font>> _fonts;
        
        ~Utils();

        static Utils *GetInstance();
        Utils(Utils &other) = delete;
        void operator=(const Utils &) = delete;
        void Quit();
};

#include "States/StateManager.hpp"