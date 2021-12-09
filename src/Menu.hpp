#pragma once

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

        void HandleEvents(StateManager &stateMan) override;
        void Update(StateManager &stateMan, float dt) override;
        void Draw(StateManager &stateMan) override;
};