#include "StateManager.hpp"

StateManager::StateManager() : _isRunning(true)
{

}

StateManager::~StateManager()
{

}

StateManager *StateManager::GetInstance() {
    static StateManager _instance;
    return &_instance;
}

void StateManager::Init()
{
    
}

void StateManager::Stop()
{
    
}

void StateManager::ChangeState(State& state)
{
    
}

void StateManager::PushState(State& state)
{
    
}

void StateManager::PopState()
{
    
}

void StateManager::HandleEvents()
{
    
}


void StateManager::Update()
{
    
}

void StateManager::Draw()
{

}

bool StateManager::isRunning() { return _isRunning; }

void StateManager::Quit() { _isRunning = false; }