#pragma once

#include <iostream>

#include "Tiles.hpp"
#include "Room.hpp"

class Generation{
    private:
        int with = 15;
        int hight = 9;
        Tiles room[hight][with];
    public:
        Room generateRoom(int lvl);
        Room generateEnemies(int number);
        void clearRoom();
};
