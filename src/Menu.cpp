#include "Menu.hpp"

Menu::Menu()
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
        switch (utils._events.type)
        {
            case SDL_QUIT:
                utils._stateMan->Quit();
                break;
        }
    }
}

void Menu::Update(Utils& utils, float dt)
{

}

void Menu::Draw(Utils& utils)
{
    SDL_SetRenderDrawColor(utils._renderer, 0, 0, 0, 255);
    SDL_RenderClear(utils._renderer);   
}
