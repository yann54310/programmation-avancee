#pragma once

#include <iostream>
#include <memory>
#include <fstream>
#include <cstdlib>
#include <array>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Define.hpp"
#include "../Utils.hpp"
#include "Tile.hpp"

class Tile;

class Generation{
    private:
        static Generation* _instance;

        Utils* _utils;
        SDL_Texture* _tilemap;
        std::ifstream _room;

        std::string _filePathTilemap;
        std::string _filePathRoom;

        Generation();

    public:
        ~Generation();

        static Generation *GetInstance();
        Generation(Generation &other) = delete;
        void operator=(const StateManager &) = delete;

        void LoadData();
        SDL_Texture* getTilemap();

        std::unique_ptr<Room> generateRoom(int lvl);
        //Generation generateEnemies(int number);
        //Generation updateGeneration(Generation salle);
        //void clearRoom(Generation salle);
};
