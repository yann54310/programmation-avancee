#include "GraphicObject.hpp"

GraphicObject::GraphicObject() : _utils(Utils::GetInstance()), _texture(nullptr), _needUpdate(true)
{

}

GraphicObject::GraphicObject(SDL_Rect& rect) : _utils(Utils::GetInstance()), _rect(rect), _texture(nullptr), _needUpdate(true)
{

}

GraphicObject::~GraphicObject(){
    if(_texture) { SDL_DestroyTexture(_texture); _texture = nullptr; }
}

void GraphicObject::Load(SDL_Surface*& tmpSurf)
{
    if(_texture)
        SDL_DestroyTexture(_texture); _texture = nullptr;

    if(!(_texture = SDL_CreateTextureFromSurface(_utils->_renderer, tmpSurf)))
        ERROR_SDL(SDL_LOG_CATEGORY_VIDEO)

    SDL_FreeSurface(tmpSurf); tmpSurf = nullptr;
}

void GraphicObject::Draw()
{
    if(SDL_RenderCopy(_utils->_renderer, _texture, NULL, &_rect) != 0)
        ERROR_SDL(SDL_LOG_CATEGORY_RENDER);
}

void GraphicObject::SetPos(const int x, const int y)
{
    _rect.x = x;
    _rect.y = y;
}
void GraphicObject::SetRect(const SDL_Rect rect)
{
    _rect = rect;
}
void GraphicObject::SetRect(const int x, const int y, const int w, const int h)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
}
void GraphicObject::SetX(const int x)
{
    _rect.x = x;
}
void GraphicObject::SetY(const int y)
{
    _rect.y = y;
}
void GraphicObject::SetW(const int w)
{
    _rect.w = w;
}
void GraphicObject::SetH(const int h)
{
    _rect.h = h;
}
