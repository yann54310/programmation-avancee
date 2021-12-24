#include "StateManager.hpp"

StateManager* StateManager::_instance = nullptr;

StateManager::StateManager()
{

}

StateManager::~StateManager()
{
    this->Quit();
    delete _instance;
}

StateManager *StateManager::GetInstance() {
    if(!_instance)
    {
        _instance = new StateManager();
    }
    return _instance;
}

void StateManager::ChangeState(std::shared_ptr<State> state)
{
    _actionForStackUpdate.push(2);
    _tmpPush.push(state);
}

void StateManager::PushState(std::shared_ptr<State> state)
{
    _actionForStackUpdate.push(1);
    _tmpPush.push(state);
}

void StateManager::PopState()
{
    _actionForStackUpdate.push(0);
}

void StateManager::UpdateStack(){
    while(!_actionForStackUpdate.empty())
    {
        switch(_actionForStackUpdate.front())
        {
            case 0: //POP
                if(!_states.empty())
                {
                    _states.top().get()->Stop();
                    _states.pop();
                    if(!_states.empty())
                        _states.top().get()->Resume();
                }
                break;
            
            case 1: //PUSH
                if(!_states.empty())
                    _states.top()->Pause();
                _states.push(_tmpPush.top()); _tmpPush.pop();
                _states.top().get()->Init();
                break;
            
            case 2: //CHANGE
                if(!_states.empty())
                {
                    _states.top().get()->Stop();
                    _states.pop();
                }
                _states.push(_tmpPush.top()); _tmpPush.pop();
                _states.top().get()->Init();
                break;
        }
        _actionForStackUpdate.pop();
    }
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
    return !_states.empty();
}

void StateManager::Quit()
{
    while(!_states.empty())
    {
        _states.top().get()->Stop();
        _states.pop();
    }
}