#include "Bullet.hpp"

Bullet::Bullet(std::shared_ptr<Player> player) : Tile(player.get()->getRect()->x/SIZE_FACTOR/SIZE_OF_A_TILE , player.get()->getRect()->y/SIZE_FACTOR/SIZE_OF_A_TILE, (SDL_Point){27, 21}), _player(player)
{

}

Bullet::~Bullet()
{

}

bool Bullet::Update()
{
    _rect.x += _player.get()->getVx() * _utils->_time.getDeltaTime() * PLAYER_SPEED;
    _rect.y += _player.get()->getVy() * _utils->_time.getDeltaTime() * PLAYER_SPEED;

    if(_rect.x + _rect.w >= WINDOW_WIDTH || _rect.y + _rect.h >= WINDOW_HEIGHT || _rect.x < 0 || _rect.y < 0)
        return false;
    else
        return true; //delete Bullet;
}

void Bullet::Draw()
{
    Tile::Draw();
}
