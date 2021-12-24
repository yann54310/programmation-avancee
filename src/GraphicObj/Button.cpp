#include "Button.hpp"

Button::Button(Font* font, SDL_Color color, SDL_Rect rect, const std::string& text):
                GraphicObject(rect), _font(font), _color(color), _text(text)
{
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
        ERROR_SDL(SDL_LOG_CATEGORY_RENDER)
    
    GraphicObject::Load(_tmpSurf);
}

void Button::addEvent(SDL_KeyCode kc, Event e)
{
    _eventsList[kc] = e;
}

void Button::HandleEvents(SDL_KeyCode kc)
{
    if(!_eventsList.count(kc))
        return;
    
    switch(_eventsList[kc])
    {
        case Event::QUITTER:
            _utils->_stateMan->Quit();
            break;
        case Event::JOUER:
            _utils->_stateMan->PushState(std::make_shared<Game>());
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
    
}

void Button::Draw()
{
    if(_needUpdate)
        this->Load();
    _needUpdate = false;

    GraphicObject::Draw();
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
