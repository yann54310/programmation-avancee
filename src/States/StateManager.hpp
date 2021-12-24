#pragma once

#include <queue>
#include <stack>
#include <memory>

#include "State.hpp"
#include "../Time.hpp"

//http://gamedevgeek.com/tutorials/managing-game-states-in-c/
class StateManager
{
    private:
        std::stack<std::shared_ptr<State>> _states;
        std::stack<std::shared_ptr<State>> _tmpPush;
        std::queue<int> _actionForStackUpdate; //1 = Push, 0 = Pop, 2 = Change
        static StateManager* _instance;

        StateManager();

    public:
        ~StateManager();

        static StateManager *GetInstance();
        StateManager(StateManager &other) = delete;
        void operator=(const StateManager &) = delete;

        void ChangeState(std::shared_ptr<State> state);
        void PushState(std::shared_ptr<State> state);
        void PopState();
        void UpdateStack();

        void HandleEvents();
        void Update();
        void Draw();

        bool isRunning();
        void Quit();
};