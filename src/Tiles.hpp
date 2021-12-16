#pragma once

#include <iostream>

#define SIZE_OF_TILES 16

class Tiles{
    private:
        bool wall;
        bool ground;
        bool destrucible;

        bool damage;
        int damageNb;
        
        bool enemy;
        int enemyNb;
    public:

        //fonction de création de tile
        Tiles setWall();
        Tiles setGround();
        Tiles setHole(int dmg);
        Tiles setDestrucible();
        Tiles setEnemy(int number);

        //fonction de test de type
        bool isWall();
        bool isGround();
        bool isHole();
        bool doesDamage();
        int nbDamage();
        bool isDestructible();
        bool isEnemy();
        int nbEnemy();
};