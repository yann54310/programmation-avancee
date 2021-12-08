#pragma once

#include <iostream>

class Generation{
    private:
        Tiles room[154];
        int with = 15;
        int hight = 9;
    public:
        room generateRoom(int lvl);
        room generateEnemies(int number);
        void clearRoom();
};