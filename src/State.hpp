#pragma once

class Utils;

class State
{
    protected:
        Utils* _utils;

    public:
        State() = default;
        virtual ~State() = default;

        virtual void Init() = 0;
        virtual void Stop() = 0;
        
        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
};

#include "Utils.hpp"