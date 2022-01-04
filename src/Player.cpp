#include "Player.hpp"

SDL_Point Player::_sprites[4] = {
    (SDL_Point){23, 21},
    (SDL_Point){24, 21},
    (SDL_Point){25, 21},
    (SDL_Point){26, 21}
};
int Player::UP = 0;
int Player::RIGHT = 1;
int Player::DOWN = 2;
int Player::LEFT = 3;

Player::Player(): Tile(_sprites[RIGHT]), vx(0), vy(0)
{

}

Player::Player(const float x, const float y) : Tile(x, y, _sprites[0]), vx(0), vy(0)
{

}

Player::~Player()
{

}

void Player::Draw()
{

    Tile::Draw();
}

void Player::moveUp()
{
    _rect.y -= _utils->_time.getDeltaTime() * PLAYER_SPEED;
    vy = -1;
    int yMap = abs((int)(_rect.y/SIZE_FACTOR - (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2/SIZE_FACTOR)/SIZE_OF_A_TILE)%HEIGHT_OF_ROOM;
    
    if(yMap <= 0)
        _rect.y = (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2 + SIZE_FACTOR*SIZE_OF_A_TILE;
    
    _tilemapRect.x = _sprites[UP].x * SIZE_OF_A_TILE;
    _tilemapRect.y = _sprites[UP].y * SIZE_OF_A_TILE;
}

void Player::moveRight()
{
    _rect.x += _utils->_time.getDeltaTime() * PLAYER_SPEED;
    vx = 1;
    int xMap = abs((int)((_rect.x + _rect.w)/SIZE_FACTOR - (int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2/SIZE_FACTOR)/SIZE_OF_A_TILE)%WIDTH_OF_ROOM;
        
    if(xMap >= WIDTH_OF_ROOM - 1)
        _rect.x = (int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2 + (WIDTH_OF_ROOM-2)*SIZE_FACTOR*SIZE_OF_A_TILE;
    _tilemapRect.x = _sprites[RIGHT].x * SIZE_OF_A_TILE;
    _tilemapRect.y = _sprites[RIGHT].y * SIZE_OF_A_TILE;
}

void Player::moveDown()
{
    _rect.y += _utils->_time.getDeltaTime() * PLAYER_SPEED;
    vy = 1;
    int yMap = abs((int)((_rect.y + _rect.h)/SIZE_FACTOR - (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2/SIZE_FACTOR)/SIZE_OF_A_TILE)%HEIGHT_OF_ROOM;
        
    if(yMap >= HEIGHT_OF_ROOM - 1)
        _rect.y = (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2 + (HEIGHT_OF_ROOM-2)*SIZE_FACTOR*SIZE_OF_A_TILE;
    _tilemapRect.x = _sprites[DOWN].x * SIZE_OF_A_TILE;
    _tilemapRect.y = _sprites[DOWN].y * SIZE_OF_A_TILE;
}

void Player::moveLeft()
{
    _rect.x -= _utils->_time.getDeltaTime() * PLAYER_SPEED;
    vx = -1;
    int xMap = abs((int)(_rect.x/SIZE_FACTOR - (int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2/SIZE_FACTOR)/SIZE_OF_A_TILE)%WIDTH_OF_ROOM;
    
    if(xMap <= 0)
        _rect.x = (int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2 + SIZE_FACTOR*SIZE_OF_A_TILE;
    _tilemapRect.x = _sprites[LEFT].x * SIZE_OF_A_TILE;
    _tilemapRect.y = _sprites[LEFT].y * SIZE_OF_A_TILE;
}

void Player::setTiles(std::shared_ptr<Room> _tiles)
{
    this->_tiles = _tiles;
}

int Player::getVx()
{
    return vx;
}

int Player::getVy()
{
    return vy;
}
