#pragma once

#include <array>
#include <vector>

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
class Bullet;

class Game : public State
{
    private:
        std::shared_ptr<Player> _player;
        std::shared_ptr<Room> _tiles;
        std::vector<std::unique_ptr<Bullet>> _bullets;

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
#include "../Bullet.hpp"