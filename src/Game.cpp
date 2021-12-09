#include "Game.hpp"

Game::Game() : _time(FRAME_PER_SECOND), _isPlaying(true), _utils(Utils::GetInstance())
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s at line %d : %s", __FILE__, __LINE__, SDL_GetError());
        _isPlaying = false;
        return;
    }

    _utils->_window = SDL_CreateWindow("PROG_AVANCE",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                800, 600,
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
}

Game::~Game()
{
    SDL_Quit();
}

bool Game::isPlaying() const
{
    return _isPlaying;
}

void Game::start()
{
    while(_isPlaying)
    {
        _time.startFrame();

        while (SDL_PollEvent(&_utils->_events))
        {
            switch (_utils->_events.type)
            {
            case SDL_QUIT:
                _isPlaying = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(_utils->_renderer, 0, 0, 0, 255);
        SDL_RenderClear(_utils->_renderer);
        
        _time.sleepUntilNextFrame();
    }
}