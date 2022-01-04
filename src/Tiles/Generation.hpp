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

#include "Void.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "DestructibleWall.hpp"
#include "HeartBonus.hpp"
#include "HealthBonus.hpp"
#include "Tree.hpp"
#include "DamageBonus.hpp"
#include "SpeedBonus.hpp"

class Tile;
class Game;

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

        std::shared_ptr<Room> generateRoom(Game* game, int lvl);
        //Generation generateEnemies(int number);
        //Generation updateGeneration(Generation salle);
        //void clearRoom(Generation salle);
};

#include "../States/Game.hpp"