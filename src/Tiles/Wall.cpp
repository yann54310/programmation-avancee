#include "Wall.hpp"

Wall::Wall(): Tile((SDL_Point){10, 17})
{
    
}

Wall::Wall(const float x, const float y) : Tile(x, y, (SDL_Point){10, 17})
{

}

Wall::~Wall()
{

}
