#pragma once

class StateManager;

class State{
    public:
        State(){}
        virtual ~State(){}

        virtual void Init() = 0;
        virtual void Stop() = 0;
        
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(StateManager &stateMan) = 0;
        virtual void Update(StateManager &stateMan, float dt) = 0;
        virtual void Draw(StateManager &stateMan) = 0;
};

#include "StateManager.hpp"