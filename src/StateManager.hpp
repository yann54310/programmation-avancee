#pragma once

#include <stack>
#include <memory>

#include "State.hpp"
#include "Time.hpp"

//http://gamedevgeek.com/tutorials/managing-game-states-in-c/
class StateManager
{
    private:
        bool _isRunning;
        std::stack<std::shared_ptr<State>> _states;
        Utils* _utils;
        static StateManager _instance;

    public:
        StateManager();
        ~StateManager();

        static StateManager *GetInstance();
        StateManager(StateManager &other) = delete;
        void operator=(const StateManager &) = delete;

        void ChangeState(std::shared_ptr<State> state);
        void PushState(std::shared_ptr<State> state);
        void PopState();

        void HandleEvents();
        void Update();
        void Draw();

        bool isRunning();
        void Quit();
};