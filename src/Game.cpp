#include "Game.hpp"

Game::Game() : _isPlaying(true), _time()
{

}

Game::~Game()
{

}

bool Game::isPlaying() const
{
    return _isPlaying;
}

void Game::start()
{
    while(_isPlaying)
    {
        std::cout << "WOW" << std::endl;
        if(_time.getElapsedTime() > 100)
            _isPlaying = false;
    }
}