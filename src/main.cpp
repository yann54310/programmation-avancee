#include <iostream>

#include <cstdlib>
#include <chrono>

#include <SDL2/SDL.h>

#include "Launcher.hpp"

int main(void)
{
    srand(std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count());

    Launcher launcher;

    launcher.start();

    return 0;
}