#include "State.hpp"

State::State() : _utils(Utils::GetInstance())
{
    if(SDL_SetRenderDrawColor(_utils->_renderer, 0, 0, 0, 255) != 0)
        ERROR_SDL(SDL_LOG_CATEGORY_RENDER)
}

void State::Draw()
{
    SDL_RenderPresent(_utils->_renderer);

    if(SDL_RenderClear(_utils->_renderer) != 0)
        ERROR_SDL(SDL_LOG_CATEGORY_RENDER)
}