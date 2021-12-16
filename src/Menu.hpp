#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "State.hpp"

#define NB_SELECTION 5

class Menu : public State
{
    private:
        int _selection;
        int _selectionMove;

        void _loadSelection();

    public:
        Menu();
        ~Menu();
        
        void Init() override;
        void Stop() override;
            
        void Pause() override;
        void Resume() override;

        void HandleEvents(Utils &utils) override;
        void Update(Utils &utils, float dt) override;
        void Draw(Utils &utils) override;
};