#pragma once

#include <array>

#include <SDL2/SDL.h>

#include "../Define.hpp"
#include "State.hpp"
#include "../Tiles/Tile.hpp"
#include "../Tiles/DamageBonus.hpp"
#include "../Tiles/DestructibleWall.hpp"
#include "../Tiles/Floor.hpp"
#include "../Tiles/HeartBonus.hpp"
#include "../Tiles/HealthBonus.hpp"
#include "../Tiles/SpeedBonus.hpp"
#include "../Tiles/Void.hpp"
#include "../Tiles/Wall.hpp"

class Player;

class Game : public State
{
    private:
        std::unique_ptr<Player> _player;
        std::unique_ptr<Room> _tiles;

    public:
        Game();
        ~Game();

        void setPlayer(const int x, const int y);

        void Init();
        void Stop();

        void Pause();
        void Resume();

        void HandleEvents();
        void Update();
        void Draw();
};

#include "../Player.hpp"