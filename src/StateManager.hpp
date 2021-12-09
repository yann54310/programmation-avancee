#pragma once

#include <stack>

#include "State.hpp"

//http://gamedevgeek.com/tutorials/managing-game-states-in-c/
class StateManager
{
    private:
        std::stack<State> states;
        bool _isRunning;

    public:
        StateManager();
        ~StateManager();

        static StateManager *GetInstance();
        StateManager(StateManager &other) = delete;
        void operator=(const StateManager &) = delete;

        void Init();
        void Stop();

        void ChangeState(State& state);
        void PushState(State& state);
        void PopState();

        void HandleEvents();
        void Update();
        void Draw();

        bool isRunning();
        void Quit();
};