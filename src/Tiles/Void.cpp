#include "Void.hpp"

Void::Void() : Tile((SDL_Point){0, 0})
{

}

Void::Void(const float x, const float y) : Tile(x, y, (SDL_Point){0, 0})
{

}

Void::~Void()
{

}
