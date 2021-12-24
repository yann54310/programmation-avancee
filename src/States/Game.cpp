#include "Game.hpp"

Game::Game() : State()
{
    _tiles[0][0] = std::make_unique<Wall>();
    _tiles[0][1] = std::make_unique<Wall>();
    _tiles[0][0]->SetPos(160, 160);
    _tiles[0][1]->SetPos(40, 100);
}

Game::~Game()
{

}

void Game::Init()
{

}

void Game::Stop()
{

}

void Game::Pause()
{

}

void Game::Resume()
{

}

void Game::HandleEvents()
{
    while (SDL_PollEvent(&_utils->_events))
    {
        switch(_utils->_events.type)
        {
            case SDL_QUIT:
                _utils->_stateMan->Quit();
                break;
            case SDL_KEYDOWN:
                switch(_utils->_events.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        _utils->_stateMan->PopState();
                        break;
                }
                break;
        }
    }
}

void Game::Update()
{

}

void Game::Draw()
{
    _tiles[0][0]->Draw();
    _tiles[0][1]->Draw();
    State::Draw();
}