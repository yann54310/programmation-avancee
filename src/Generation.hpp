#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Tiles.hpp"

#define WIDTH_OF_ROOM 15
#define HEIGHT_OF_ROOM 9

class Generation{
    private:
        static constexpr int width = WIDTH_OF_ROOM;
        static constexpr int height = HEIGHT_OF_ROOM;
        Tiles room[height][width];
    public:
        Room generateRoom(int lvl);
        Room generateEnemies(int number);
        void clearRoom(Room salle);
};
