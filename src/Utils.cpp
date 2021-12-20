#include "Utils.hpp"

Utils Utils::_instance;

Utils::Utils() : _stateMan(StateManager::GetInstance()), _window(nullptr), _renderer(nullptr), _time(FRAME_PER_SECOND)
{
}

Utils::~Utils()
{
    this->Quit();
}

Utils *Utils::GetInstance() { 
    return &_instance;
}

void Utils::Quit()
{
    _stateMan->Quit();

    for(auto &font : _fonts)
        font.second.reset();

    if(_renderer) { SDL_DestroyRenderer(_renderer); _renderer = nullptr; }
    if(_window) { SDL_DestroyWindow(_window); _window = nullptr; }
}