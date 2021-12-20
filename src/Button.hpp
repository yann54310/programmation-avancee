#pragma once

#include <string>
#include <functional>

#include <SDL2/SDL_ttf.h>

#include "GraphicObject.hpp"
#include "Font.hpp"
#include "Event.hpp"

class Button : public GraphicObject
{
    private:
        Font* _font;
        SDL_Color _color;
        std::string _text;
        std::unordered_map<SDL_Keycode, Event> _eventsList;

    public:
        Button(Font* font, SDL_Color color, SDL_Rect rect, const std::string& text);
        ~Button();

        void Load();
        void Stop();

        void addEvent(SDL_KeyCode kc, Event e);
        void HandleEvents(SDL_KeyCode kc);
        void Draw();

        void SetPos(const int x, const int y);
        void SetRect(const int x, const int y, const int w, const int h);
        void SetX(const int x);
        void SetY(const int y);
        void SetW(const int w);
        void SetH(const int h);

        void SetRGB(const Uint8 r, const Uint8 g, const Uint8 b);
        void SetRGBA(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
        void SetColor(const SDL_Color color);
        void SetR(const Uint8 r);
        void SetG(const Uint8 g);
        void SetB(const Uint8 b);
        void SetA(const Uint8 a);

        void SetFont(Font* font);
        void SetText(const std::string& text);
};
