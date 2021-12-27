#include "HealthBonus.hpp"

HealthBonus::HealthBonus(): Tile((SDL_Point){33, 19})
{
    
}

HealthBonus::HealthBonus(const float x, const float y): Tile(x, y, (SDL_Point){33, 19})
{
    
}

HealthBonus::~HealthBonus()
{

}
