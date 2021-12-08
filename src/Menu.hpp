#pragma once

#include "State.hpp"

class Menu : public State
{
    public:
        Menu();
        ~Menu();
        
        void Init();
        void Stop();
            
        void Pause();
        void Resume();

        void HandleEvents(StateManager &stateMan);
        void Update(StateManager &stateMan, float dt);
        void Draw(StateManager &stateMan);
};