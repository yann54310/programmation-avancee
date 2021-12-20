#include "StateManager.hpp"

StateManager StateManager::_instance;

StateManager::StateManager() : _isRunning(true), _utils(Utils::GetInstance())
{

}

StateManager::~StateManager()
{
    this->Quit();
}

StateManager *StateManager::GetInstance() {
    return &_instance;
}

void StateManager::ChangeState(std::shared_ptr<State> state)
{
    if(!_states.empty())
    {
        _states.top().get()->Stop();
        _states.pop();
    }
    _states.push(std::move(state));
    _states.top().get()->Init();
}

void StateManager::PushState(std::shared_ptr<State> state)
{
    if(!_states.empty())
        _states.top()->Pause();
    _states.push(std::move(state));
    _states.top().get()->Init();
}

void StateManager::PopState()
{
    if(!_states.empty())
    {
        _states.top().get()->Stop();
        _states.pop();
        if(!_states.empty())
            _states.top().get()->Resume();
        else
            _isRunning = false;
    }
    else
        _isRunning = false;
}

void StateManager::HandleEvents()
{
    if(!_states.empty())
        _states.top().get()->HandleEvents();
}


void StateManager::Update()
{
    if(!_states.empty())
        _states.top().get()->Update();
}

void StateManager::Draw()
{
    if(!_states.empty())
        _states.top().get()->Draw();
}

bool StateManager::isRunning()
{
    return _isRunning;
}

void StateManager::Quit()
{
    while(!_states.empty())
    {
        _states.top().get()->Stop();
        _states.pop();
    }

    _isRunning = false;
}