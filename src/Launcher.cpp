#include "Launcher.hpp"

Launcher::Launcher() : _isPlaying(true), _utils(Utils::GetInstance())
{
    _utils->_fonts["ttf_kenny"] = std::make_shared<Font>("src/assets/ttf_kenny.ttf", 16); //No upper chars
    if(!_utils->_fonts["ttf_kenny"]->getFont())
        ERROR_SDL_LAUNCHER(SDL_LOG_CATEGORY_APPLICATION)
    
    _utils->_stateMan->PushState(std::make_shared<Menu>());
}

Launcher::~Launcher()
{
    _utils->Quit();
}

bool Launcher::isPlaying() const
{
    return _isPlaying && _utils->_stateMan->isRunning();
}

void Launcher::start()
{
    _utils->_stateMan->UpdateStack();
    while(isPlaying())
    {
        _utils->_time.startFrame();

        _utils->_stateMan->HandleEvents();
        _utils->_stateMan->Update();
        _utils->_stateMan->Draw();

        _utils->_stateMan->UpdateStack();
        
        _utils->_time.sleepUntilNextFrame();
    }
}