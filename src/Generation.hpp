#pragma once

#include <iostream>

#include "Tiles.hpp"
#include "Room.hpp"

#define NB_ROOM 154

class Generation{
    private:
        Tiles room[NB_ROOM];
        int with = 15;
        int hight = 9;
    public:
        Room generateRoom(int lvl); //YANIS : IL FAUDRA DISCUTER DU TYPE DE RETOUR
        Room generateEnemies(int number); //YANIS : IL FAUDRA DISCUTER DU TYPE DE RETOUR
        void clearRoom();
};