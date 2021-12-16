#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Tiles.hpp"

#define WIDTH_OF_ROOM 15
#define HEIGHT_OF_ROOM 9

class Generation{
    private:
        static constexpr int width = WIDTH_OF_ROOM;
        static constexpr int height = HEIGHT_OF_ROOM;
        Tiles room[height][width];
        //enemies 
    public:
        Generation generateRoom(int lvl);
        Generation generateEnemies(int number);
        Generation updateGeneration(Generation salle);
        void clearRoom(Generation salle);
};
