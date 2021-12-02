#include "Game.hpp"

Game::Game() : _tStart(getActualTime()), _isPlaying(true)
{

}

Game::~Game()
{

}

inline msec_t Game::getActualTime() const
{
    static struct timeval _tempTimeval{};

    gettimeofday(&_tempTimeval, nullptr);
    return (_tempTimeval.tv_sec * 1000) + (_tempTimeval.tv_usec / 1000);
}

inline msec_t Game::getElapsedTime() const
{
    return getActualTime() - _tStart;
}

inline bool Game::isPlaying() const
{
    return _isPlaying;
}

inline msec_t Game::getDeltaTime() const
{
    return getActualTime() - _tLastFrame;
}

void Game::start()
{
    while(isPlaying())
    {
        std::cout << "WOW" << std::endl;
        if(getElapsedTime() > 100)
            _isPlaying = false;
    }
}