#include "Floor.hpp"

Floor::Floor(): Tile((SDL_Point){2, 0})
{
    
}

Floor::Floor(const float x, const float y): Tile(x, y, (SDL_Point){2, 0})
{
    
}

Floor::~Floor()
{

}
