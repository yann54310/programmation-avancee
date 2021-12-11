#pragma once

class Utils;

class State
{
    public:
        State() = default;
        virtual ~State() = default;

        virtual void Init() = 0;
        virtual void Stop() = 0;
        
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(Utils &stateMan) = 0;
        virtual void Update(Utils &stateMan, float dt) = 0;
        virtual void Draw(Utils &stateMan) = 0;
};

#include "Utils.hpp"