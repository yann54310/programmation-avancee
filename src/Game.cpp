#include "Game.hpp"

Game::Game() : _isPlaying(true), _utils(Utils::GetInstance())
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    _utils->_window = SDL_CreateWindow("PROG_AVANCE",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if(_utils->_window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    _utils->_renderer = SDL_CreateRenderer(_utils->_window, -1, SDL_RENDERER_ACCELERATED);
    if(_utils->_renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    if(TTF_Init() != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    _utils->_fonts["ttf_kenny"] = TTF_OpenFont("src/assets/ttf_kenny.ttf", 16);
    if(!_utils->_fonts["ttf_kenny"]) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    _utils->_stateMan->PushState(std::make_shared<Menu>());
}

Game::~Game()
{
    _utils->Quit();
    TTF_Quit();
    SDL_Quit();
}

bool Game::isPlaying() const
{
    return _isPlaying && _utils->_stateMan->isRunning();
}

void Game::start()
{
    while(isPlaying())
    {
        _utils->_time.startFrame();
        
        _utils->_stateMan->HandleEvents();
        _utils->_stateMan->Update();
        _utils->_stateMan->Draw();
        
        _utils->_time.sleepUntilNextFrame();
    }
}