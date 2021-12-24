#include "Tile.hpp"

Tile::Tile(const SDL_Point& posInTilemap)
            : _utils(Utils::GetInstance())
            , _rect((SDL_Rect){0, 0, SIZE_OF_A_TILE, SIZE_OF_A_TILE})
            , _tilemapRect((SDL_Rect){posInTilemap.x * SIZE_OF_A_TILE
                                    , posInTilemap.y * SIZE_OF_A_TILE
                                    , SIZE_OF_A_TILE, SIZE_OF_A_TILE})
            , _tilemap(Generation::GetInstance()->getTilemap())
{
    
}

Tile::~Tile()
{

}

void Tile::Draw()
{
    if(SDL_RenderCopy(_utils->_renderer, _tilemap, &_tilemapRect, &_rect) != 0) ERROR_SDL(SDL_LOG_CATEGORY_RENDER)
}

void Tile::SetPos(const int x, const int y)
{
    _rect.x = x;
    _rect.y = y;
}
void Tile::SetX(const int x)
{
    _rect.x = x;
}
void Tile::SetY(const int y)
{
    _rect.y = y;
}
