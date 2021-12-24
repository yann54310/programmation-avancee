#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "State.hpp"
#include "../GraphicObj/Button.hpp"
#include "../Event.hpp"

class Menu : public State
{
    private:
        int _selection;
        int _deltaMove;

        std::vector<std::shared_ptr<Button>> _buttons;

        inline void _loadSelection();

    public:
        Menu();
        ~Menu();
        
        void Init() override;
        void Stop() override;

        void Pause() override;
        void Resume() override;

        void HandleEvents() override;
        void Update() override;
        void Draw() override;
};