#include "Game.hpp"

Game::Game() : State(), _player(std::make_shared<Player>()), _tiles(Generation::GetInstance()->generateRoom(this, 0))
{
    _player->setTiles(_tiles);
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
    if(states[SDL_GetScancodeFromKey(SDLK_SPACE)])
        if(_bullets.size() < 17) _bullets.push_back(std::make_unique<Bullet>(_player));
    if(states[SDL_GetScancodeFromKey(SDLK_0)])
        _tiles = Generation::GetInstance()->generateRoom(this, 0); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_1)])
        _tiles = Generation::GetInstance()->generateRoom(this, 1); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_2)])
        _tiles = Generation::GetInstance()->generateRoom(this, 2); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_3)])
        _tiles = Generation::GetInstance()->generateRoom(this, 3); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_4)])
        _tiles = Generation::GetInstance()->generateRoom(this, 4); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_5)])
        _tiles = Generation::GetInstance()->generateRoom(this, 5); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_6)])
        _tiles = Generation::GetInstance()->generateRoom(this, 6); _player->setTiles(_tiles);
    if(states[SDL_GetScancodeFromKey(SDLK_7)])
        _tiles = Generation::GetInstance()->generateRoom(this, 7); _player->setTiles(_tiles);

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
    for(auto i = 0; i < _bullets.size(); i++)
        if(!_bullets[i]->Update()) _bullets.erase(_bullets.begin() + i);
}

void Game::Draw()
{
    for(const auto& line : (*_tiles.get()))
        for(const auto& tile : line)
            tile->Draw();
    for(const auto& bullet : _bullets)
        bullet->Draw();
    _player->Draw();

    State::Draw();
}