#include "Generation.hpp"

Generation* Generation::_instance = nullptr;

Generation::Generation(): _utils(Utils::GetInstance()), _tilemap(nullptr)
                        , _filePathTilemap("src/assets/1bitpack_kenney_1.2/Tilesheet/colored-transparent_packed.png")
                        , _filePathRoom("src/assets/room.txt")
{

}

Generation::~Generation()
{
    delete _instance;
}

Generation* Generation::GetInstance()
{
    if(!_instance)
    {
        _instance = new Generation();

        _instance->LoadData();
    }
    return _instance;
}

void Generation::LoadData()
{
    _tilemap = IMG_LoadTexture(_utils->_renderer, _filePathTilemap.c_str());
    if(!_tilemap) ERROR_SDL(SDL_LOG_CATEGORY_VIDEO)

    _room.open(_filePathRoom.c_str());
    if(!_room.good()) ERROR("Problème lors de l'ouverture du fichier")
}

SDL_Texture* Generation::getTilemap()
{
    return _tilemap;
}

std::unique_ptr<Room> Generation::generateRoom(int lvl)
{
    std::unique_ptr<Room> room = std::make_unique<Room>();

    unsigned char old = 'x';
    unsigned char curr = 'x';
    int i = 0;
    int j = 0;
    while(curr != EOF || !(old == '\n' && curr == '\n'))
    {
        old = curr;
        curr = _room.get();

        switch(curr)
        {
            case ' ':
                break;
            case '*':
                break;
            case '#':
                break;            
            case '+':
                break;
            case '0':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '-':
                break;
            case 'H':
                break;
            case 'S':
                break;
            case 'D':
                break;
            case 'V':
                break;
        }
        if(++i >= WIDTH_OF_ROOM)
            i = 0;
        if(j >= HEIGHT_OF_ROOM)
            j = 0;
    }

    return room;
}

/*
Generation Generation::generateEnemies(int number)
{

}

void Generation::clearRoom(Generation salle)
{

}
*/