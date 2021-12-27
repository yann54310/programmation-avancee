#include "Game.hpp"

Game::Game() : State(), _player(std::make_unique<Player>()), _tiles(Generation::GetInstance()->generateRoom(this, 0))
{

}

Game::~Game()
{

}

void Game::setPlayer(const int x, const int y)
{
    _player->SetPos(x, y);
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
    const Uint8* states = SDL_GetKeyboardState(NULL);

    if(states[SDL_GetScancodeFromKey(SDLK_ESCAPE)])
        _utils->_stateMan->PopState();
    if(states[SDL_GetScancodeFromKey(SDLK_UP)])
        _player->moveUp();
    if(states[SDL_GetScancodeFromKey(SDLK_RIGHT)])
        _player->moveRight();
    if(states[SDL_GetScancodeFromKey(SDLK_DOWN)])
        _player->moveDown();
    if(states[SDL_GetScancodeFromKey(SDLK_LEFT)])
        _player->moveLeft();
    if(states[SDL_GetScancodeFromKey(SDLK_0)])
        _tiles = Generation::GetInstance()->generateRoom(this, 0);
    if(states[SDL_GetScancodeFromKey(SDLK_1)])
        _tiles = Generation::GetInstance()->generateRoom(this, 1);
    if(states[SDL_GetScancodeFromKey(SDLK_2)])
        _tiles = Generation::GetInstance()->generateRoom(this, 2);
    if(states[SDL_GetScancodeFromKey(SDLK_3)])
        _tiles = Generation::GetInstance()->generateRoom(this, 3);
    if(states[SDL_GetScancodeFromKey(SDLK_4)])
        _tiles = Generation::GetInstance()->generateRoom(this, 4);
    if(states[SDL_GetScancodeFromKey(SDLK_5)])
        _tiles = Generation::GetInstance()->generateRoom(this, 5);
    if(states[SDL_GetScancodeFromKey(SDLK_6)])
        _tiles = Generation::GetInstance()->generateRoom(this, 6);
    if(states[SDL_GetScancodeFromKey(SDLK_7)])
        _tiles = Generation::GetInstance()->generateRoom(this, 7);

    while (SDL_PollEvent(&_utils->_events))
    {
        switch(_utils->_events.type)
        {
            case SDL_QUIT:
                _utils->_stateMan->Quit();
                break;
        }
    }
}

void Game::Update()
{

}

void Game::Draw()
{
    for(auto& line : (*_tiles.get()))
        for(auto& tile : line)
            tile->Draw();
    _player->Draw();

    State::Draw();
}