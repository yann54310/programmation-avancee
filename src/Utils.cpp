#include "Utils.hpp"

Utils::Utils() : _stateMan(StateManager::GetInstance()), _window(nullptr), _renderer(nullptr)
{

}

Utils::~Utils()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

Utils *Utils::GetInstance() { 
    static Utils _instance;
    return &_instance;
}