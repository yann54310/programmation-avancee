#pragma once

#include "../Error.hpp"

class Utils;

class State
{
    protected:
        Utils* _utils;

    public:
        State();
        virtual ~State() = default;

        virtual void Init() = 0;
        virtual void Stop() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw();
};

#include "../Utils.hpp"