#pragma once

#include <iostream>

class Tiles{
    private:
        bool wall;
        bool ground;
        bool destrucible;

        bool damage;
        int damageNb;
        
        bool enemie;
        int enemieNb;
    public:

        bool isWall();
        bool isGround();
        bool isHole();
        bool doesDamage();
        int  nbDamage();
        bool isDestructible();
        bool isEnemie();
        int  enemieNb();
};