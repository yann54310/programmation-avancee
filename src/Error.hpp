#pragma once

#include <iostream>

#define ERROR_SDL_UTILS(CATEGORY) \
        { \
            std::cerr << CATEGORY << " - " << __FILE__ << " at line " << __LINE__ << " : " << SDL_GetError() << std::endl; \
            _instance->_stateMan->Quit(); \
            return _instance; \
        }

#define ERROR_SDL_LAUNCHER(CATEGORY) \
        { \
            std::cerr << CATEGORY << " - " << __FILE__ << " at line " << __LINE__ << " : " << SDL_GetError() << std::endl; \
            _isPlaying = false; \
            return; \
        }

#define ERROR(MESSAGE) \
        { \
            std::cerr << __FILE__ << " at line " << __LINE__ << " : " << MESSAGE << std::endl; \
            _utils->_stateMan->Quit(); \
            return; \
        }

#define ERROR_SDL(CATEGORY) \
        { \
            std::cerr << CATEGORY << " - " << __FILE__ << " at line " << __LINE__ << " : " << SDL_GetError() << std::endl; \
            _utils->_stateMan->Quit(); \
            return; \
        }
