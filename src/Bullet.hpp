#pragma once

#include <memory>

#include "Player.hpp"

class Bullet : public Tile
{
    private:
        std::shared_ptr<Player> _player;
        
    public:
        Bullet(std::shared_ptr<Player> player);
        ~Bullet();

        bool Update();
        void Draw();
};
