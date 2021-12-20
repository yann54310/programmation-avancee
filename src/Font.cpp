#include "Font.hpp"

Font::Font(const std::string& filePath, int size):
    _utils(Utils::GetInstance()), _filePath(filePath), _size(size), _font(nullptr)
{
    this->loadFont();
}

Font::~Font()
{
    if(_font) TTF_CloseFont(_font);
}

void Font::setFont(const std::string& filePath)
{
    _filePath = filePath;
}
void Font::setSize(int size)
{
    _size = size;
}

void Font::loadFont()
{
    if(_font)
        TTF_CloseFont(_font);

    if(!(_font = TTF_OpenFont(_filePath.c_str(), _size)))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return;
    }
}

void Font::createFont(const std::string& filePath, int size)
{
    if(!_utils)
        _utils = Utils::GetInstance();

    setFont(filePath);
    setSize(size);
    loadFont();
}

TTF_Font* Font::getFont(){ return _font; }
int Font::getSize(){ return _size; }
std::string Font::getFontFilePath() { return _filePath; }