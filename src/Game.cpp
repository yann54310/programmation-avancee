#include "Game.hpp"

Game::Game() : _isPlaying(true), _time(FRAME_PER_SECOND)
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
        _time.startFrame();

        std::cout << "WOW" << std::endl;
        
        _time.sleepUntilNextFrame();
    }
}