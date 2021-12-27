#include "DamageBonus.hpp"

DamageBonus::DamageBonus(): Tile((SDL_Point){36, 2})
{
    
}

DamageBonus::DamageBonus(const float x, const float y): Tile(x, y, (SDL_Point){36, 2})
{
    
}

DamageBonus::~DamageBonus()
{

}
