#pragma once

#include <iostream>

#include "Tiles.hpp"
#include "Room.hpp"

class Generation{
    private:
        Tiles room[154];
        int with = 15;
        int hight = 9;
    public:
        Room generateRoom(int lvl);
        Room generateEnemies(int number);
        void clearRoom();
};