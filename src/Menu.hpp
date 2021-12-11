#pragma once

#include <SDL2/SDL.h>

#include "State.hpp"

class Menu : public State
{
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