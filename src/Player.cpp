#include "Player.hpp"

SDL_Point Player::_sprites[5] = {
    (SDL_Point){18, 7},
    (SDL_Point){19, 7},
    (SDL_Point){20, 7},
    (SDL_Point){21, 7},
    (SDL_Point){22, 7}
};
SDL_Point Player::_die = (SDL_Point){23, 7};
int Player::nbSprite = 6;

Player::Player(): Tile(_sprites[0]), _timer(0)
{

}

Player::Player(const float x, const float y) : Tile(x, y, _sprites[0])
{

}

Player::~Player()
{

}

void Player::Draw()
{
    if((int)_utils->_time.getElapsedTime() / 2500 > _timer)
    {
        _timer++;
        int randVal = rand() % nbSprite;
        if(randVal == 5)
        {
            _tilemapRect.x = _die.x * SIZE_OF_A_TILE;
            _tilemapRect.y = _die.y * SIZE_OF_A_TILE;
        }  
        else
        {
            _tilemapRect.x = _sprites[randVal].x * SIZE_OF_A_TILE;
            _tilemapRect.y = _sprites[randVal].y * SIZE_OF_A_TILE;
        }
    }
    Tile::Draw();
}

void Player::moveUp()
{
    _rect.y -= _utils->_time.getDeltaTime() * PLAYER_SPEED;
}

void Player::moveRight()
{
    _rect.x += _utils->_time.getDeltaTime() * PLAYER_SPEED;
}

void Player::moveDown()
{
    _rect.y += _utils->_time.getDeltaTime() * PLAYER_SPEED;
}

void Player::moveLeft()
{
    _rect.x -= _utils->_time.getDeltaTime() * PLAYER_SPEED;
}
