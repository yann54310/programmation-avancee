#include "Button.hpp"

Button::Button(Font* font, SDL_Color color, SDL_Rect rect, const std::string& text):
                _font(font), _color(color), _text(text)
{
    _utils = Utils::GetInstance();
    _needUpdate = true;
    _rect = rect;

    this->Load();
}

Button::~Button()
{
    this->Stop();
}

void Button::Load()
{
    SDL_Surface* _tmpSurf = nullptr;
    if(!(_tmpSurf = TTF_RenderText_Solid(_font->getFont(), _text.c_str(), _color)))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return; 
    }
    
    if(!(_texture = SDL_CreateTextureFromSurface(_utils->_renderer, _tmpSurf)))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return;
    }

    SDL_FreeSurface(_tmpSurf);
}

void Button::addEvent(SDL_KeyCode kc, Event e)
{
    _eventsList[kc] = e;
}

void Button::HandleEvents(SDL_KeyCode kc)
{
    if(!_eventsList.contains(kc))
        return;
    
    switch(_eventsList[kc])
    {
        case Event::QUITTER:
            _utils->_stateMan->Quit();
            break;
        case Event::JOUER:
            //START GAME
            break;
        case Event::MENU:
            //GOTO MENU
            break;
        case Event::OPTION:
            //OPEN OPTION
            break;
        default:
            break;
    }
}

void Button::Stop()
{
    if(_font) { SDL_DestroyTexture(_texture); _texture = nullptr; }
}

void Button::Draw()
{
    if(!_needUpdate)
        return;

    this->Load();
    if(SDL_RenderCopy(_utils->_renderer, _texture, NULL, &_rect) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return;
    }
}

void Button::SetPos(const int x, const int y)
{
    _rect.x = x;
    _rect.y = y;

    _needUpdate = true;
}
void Button::SetRect(int x, int y, int w, int h)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;

    _needUpdate = true;
}
void Button::SetX(const int x)
{
    _rect.x = x;

    _needUpdate = true;
}
void Button::SetY(const int y)
{
    _rect.y = y;

    _needUpdate = true;
}
void Button::SetW(const int w)
{
    _rect.w = w;

    _needUpdate = true;
}
void Button::SetH(const int h)
{
    _rect.h = h;

    _needUpdate = true;
}

void Button::SetRGB(const Uint8 r, const Uint8 g, const Uint8 b)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;

    _needUpdate = true;
}
void Button::SetRGBA(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = a;

    _needUpdate = true;
}
void Button::SetColor(const SDL_Color color)
{
    _color = color;

    _needUpdate = true;
}
void Button::SetR(const Uint8 r)
{
    _color.r = r;

    _needUpdate = true;
}
void Button::SetG(const Uint8 g)
{
    _color.g = g;

    _needUpdate = true;
}
void Button::SetB(const Uint8 b)
{
    _color.b = b;

    _needUpdate = true;
}
void Button::SetA(const Uint8 a)
{
    _color.a = a;

    _needUpdate = true;
}

void Button::SetFont(Font* font)
{
    _font = font;

    _needUpdate = true;
}
void Button::SetText(const std::string& text)
{
    _text = text;

    _needUpdate = true;
}
