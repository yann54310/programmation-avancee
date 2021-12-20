#pragma once

#include <string>

#include <SDL2/SDL_ttf.h>

class Utils;

class Font
{
    private:
        Utils* _utils;
        std::string _filePath;
        int _size;
        TTF_Font* _font;

    public:
        Font(const std::string& filePath, int size);
        ~Font();
        
        void setFont(const std::string& filePath);
        void setSize(int size);

        void loadFont();

        void createFont(const std::string& filePath, int size);

        TTF_Font* getFont();
        int getSize();
        std::string getFontFilePath();
};

#include "Utils.hpp"