#pragma once

#include <iostream>

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

        bool isWall();
        bool isGround();
        bool isHole();
        bool doesDamage();
        int nbDamage();
        bool isDestructible();
        bool isEnemy();
        int nbEnemy();
};