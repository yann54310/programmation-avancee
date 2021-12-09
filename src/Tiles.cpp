#include "Tiles.hpp"


bool Tiles::isWall()
{
    return wall;
}

bool Tiles::isGround()
{
    return ground;
}

bool Tiles::isHole()
{
    if(ground||wall){
        return false;
    }
    return true;
}

bool Tiles::doesDamage()
{
    return damage;
}

int Tiles::nbDamage()
{
    if(damageNb<0||!damage){
        return 0;
    }
    return damageNb;
}

bool Tiles::isDestructible()
{
    return destrucible;
}

bool Tiles::isEnemy()
{
    return enemy;
}

int Tiles::nbEnemy()
{
    if(enemyNb<0||!enemy){
        return 0;
    }
    return enemyNb;
}