#include "SpeedBonus.hpp"

SpeedBonus::SpeedBonus(): Tile((SDL_Point){40, 0})
{
    
}

SpeedBonus::SpeedBonus(const float x, const float y): Tile(x, y, (SDL_Point){40, 0})
{
    
}

SpeedBonus::~SpeedBonus()
{

}
