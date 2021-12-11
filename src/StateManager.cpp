#include "StateManager.hpp"

StateManager::StateManager(Utils& utils) : _isRunning(true), _utils(utils)
{

}

StateManager::~StateManager()
{
    this->Quit();
}

StateManager *StateManager::GetInstance(Utils& utils) {
    static StateManager _instance(utils);
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
        _states.top().get()->HandleEvents(_utils);
}


void StateManager::Update()
{
    if(!_states.empty())
        _states.top().get()->Update(_utils, _utils._time.getDeltaTime());
}

void StateManager::Draw()
{
    if(!_states.empty())
        _states.top().get()->Draw(_utils);
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