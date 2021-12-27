#include "DestructibleWall.hpp"

DestructibleWall::DestructibleWall(): Tile((SDL_Point){6, 13})
{
    
}

DestructibleWall::DestructibleWall(const float x, const float y): Tile(x, y, (SDL_Point){6, 13})
{
    
}

DestructibleWall::~DestructibleWall()
{

}
