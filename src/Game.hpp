#pragma once

#include <iostream>

#include "Time.hpp"

class Game{
    private:
        Time _time;
        bool _isPlaying;

    public:
        Game();
        ~Game();

        void start();
        bool isPlaying() const;
};