#include "Menu.hpp"

Menu::Menu() : _selection(0),
            _selectionMove(true)
{

}

Menu::~Menu()
{
    
}

void Menu::Init()
{
    
}

void Menu::Stop()
{
    
}

        
void Menu::Pause()
{
    
}

void Menu::Resume()
{
    
}


void Menu::HandleEvents(Utils& utils)
{
    while (SDL_PollEvent(&utils._events))
    {
        switch(utils._events.type)
        {
            case SDL_QUIT:
                utils._stateMan->Quit();
                break;
            case SDL_KEYDOWN:
                switch(utils._events.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        if(_selection < NB_SELECTION) { _selection++; _selectionMove = -1; };
                        break;
                    case SDLK_UP:
                        if(_selection > 0) { _selection++; _selectionMove = 1; };
                        break;
                    default:
                        _selectionMove = 0;
                        break;
                }
                break;
        }
    }
}

void Menu::Update(Utils& utils, float dt)
{

}

void Menu::_loadSelection()
{
    
}

void Menu::Draw(Utils& utils)
{
    _loadSelection();

    if(SDL_SetRenderDrawColor(utils._renderer,
                                0,
                                0,
                                0,
                                255) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        utils._stateMan->Quit();
        return;
    }

    SDL_RenderPresent(utils._renderer);

    if(SDL_RenderClear(utils._renderer) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        utils._stateMan->Quit();
        return;
    }
}
