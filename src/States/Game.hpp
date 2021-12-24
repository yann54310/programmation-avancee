#pragma once

#include <array>

#include <SDL2/SDL.h>

#include "../Define.hpp"
#include "State.hpp"
#include "../Tiles/Tile.hpp"
#include "../Tiles/Wall.hpp"

class Game : public State
{
    private:
        Room _tiles;

    public:
        Game();
        ~Game();

        void Init();
        void Stop();

        void Pause();
        void Resume();

        void HandleEvents();
        void Update();
        void Draw();
};
