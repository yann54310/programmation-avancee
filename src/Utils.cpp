#include "Utils.hpp"

Utils* Utils::_instance = nullptr;

Utils::Utils()  : _IMG_WasInit(false), _stateMan(StateManager::GetInstance())
                , _window(nullptr), _renderer(nullptr), _time(FRAME_PER_SECOND)
{

}

Utils::~Utils()
{
    this->Quit();
    delete _instance;
}

Utils* Utils::GetInstance() {
    if(!_instance)
    {
        _instance = new Utils();

        if(SDL_Init(SDL_INIT_EVERYTHING) != 0) ERROR_SDL_UTILS(SDL_LOG_CATEGORY_APPLICATION)

        if(!IMG_Init(IMG_INIT_PNG)) ERROR_SDL_UTILS(SDL_LOG_CATEGORY_APPLICATION)
        _instance->_IMG_WasInit = true;

        if(TTF_Init() != 0) ERROR_SDL_UTILS(SDL_LOG_CATEGORY_APPLICATION)

        _instance->_window = SDL_CreateWindow("PROG_AVANCE",
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    WINDOW_WIDTH, WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN);

        if(_instance->_window == nullptr)
            ERROR_SDL_UTILS(SDL_LOG_CATEGORY_APPLICATION)

        _instance->_renderer = SDL_CreateRenderer(_instance->_window, -1, SDL_RENDERER_ACCELERATED);
        if(_instance->_renderer == nullptr)
            ERROR_SDL_UTILS(SDL_LOG_CATEGORY_APPLICATION)
    }
    return _instance;
}

void Utils::Quit()
{
    _stateMan->Quit();

    if(TTF_WasInit() != 1)  TTF_Quit();
    if(_IMG_WasInit)        IMG_Quit(); _IMG_WasInit = false;
    if(SDL_WasInit(0) != 0) SDL_Quit();

    if(_renderer) { SDL_DestroyRenderer(_renderer); _renderer = nullptr; }
    if(_window) { SDL_DestroyWindow(_window); _window = nullptr; }
}