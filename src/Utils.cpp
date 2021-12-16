#include "Utils.hpp"

Utils::Utils() : _stateMan(StateManager::GetInstance(*this)), _window(nullptr), _renderer(nullptr), _time(FRAME_PER_SECOND)
{

}

Utils::~Utils()
{
    this->Quit();
}

Utils *Utils::GetInstance() { 
    static Utils _instance;
    return &_instance;
}

void Utils::Quit()
{
    for(auto &font : _fonts)
    {
        TTF_CloseFont(font.second);
        font.second = nullptr;
    }

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}