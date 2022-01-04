#include "Tile.hpp"

Tile::Tile(const SDL_Point& posInTilemap)
            : _utils(Utils::GetInstance())
            , _rect((SDL_FRect){0, 0, SIZE_FACTOR * SIZE_OF_A_TILE, SIZE_FACTOR * SIZE_OF_A_TILE})
            , _drawRect((SDL_Rect){0, 0, SIZE_FACTOR * SIZE_OF_A_TILE, SIZE_FACTOR * SIZE_OF_A_TILE})
            , _tilemapRect((SDL_Rect){posInTilemap.x * SIZE_OF_A_TILE
                                    , posInTilemap.y * SIZE_OF_A_TILE
                                    , SIZE_OF_A_TILE, SIZE_OF_A_TILE})
            , _tilemap(Generation::GetInstance()->getTilemap())
{
    
}

Tile::Tile(const float x, const float y, const SDL_Point& posInTilemap)
            : _utils(Utils::GetInstance())
            , _rect((SDL_FRect){(int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2 + x * SIZE_FACTOR *  SIZE_OF_A_TILE,
                                (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2 + y * SIZE_FACTOR * SIZE_OF_A_TILE,
                                SIZE_FACTOR * SIZE_OF_A_TILE, SIZE_FACTOR * SIZE_OF_A_TILE})
            , _drawRect((SDL_Rect){0, 0, SIZE_FACTOR * SIZE_OF_A_TILE, SIZE_FACTOR * SIZE_OF_A_TILE})
            , _tilemapRect((SDL_Rect){posInTilemap.x * SIZE_OF_A_TILE
                                    , posInTilemap.y * SIZE_OF_A_TILE
                                    , SIZE_OF_A_TILE, SIZE_OF_A_TILE})
            , _tilemap(Generation::GetInstance()->getTilemap())
{

}

void Tile::Draw()
{
    _drawRect.x = (int)_rect.x;
    _drawRect.y = (int)_rect.y;
    if(SDL_RenderCopy(_utils->_renderer, _tilemap, &_tilemapRect, &_drawRect) != 0) ERROR_SDL(SDL_LOG_CATEGORY_RENDER)
}

void Tile::SetPos(const float x, const float y)
{
    _rect.x = x;
    _rect.y = y;
}
void Tile::SetX(const float x)
{
    _rect.x = x;
}
void Tile::SetY(const float y)
{
    _rect.y = y;
}

SDL_FRect* Tile::getRect()
{
    return &_rect;
}