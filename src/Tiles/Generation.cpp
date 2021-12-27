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

std::unique_ptr<Room> Generation::generateRoom(Game* game, int lvl)
{
    std::unique_ptr<Room> room = std::make_unique<Room>();

    _room.seekg(lvl * ((WIDTH_OF_ROOM+1)*HEIGHT_OF_ROOM + 1));

    char old = 'x';
    char curr = 'x';
    int x = 0;
    int y = 0;
    while(y < HEIGHT_OF_ROOM || !(old == '\n' && curr == '\n'))
    {
        old = curr;
        curr = _room.get();
        if(curr == '\n')
        {
            x = 0;
            y++;
            continue;
        }
        switch(curr)
        {
            case ' ':
                (*room.get())[y][x] = std::make_unique<Void>(x, y);
                break;
            case '*':
                (*room.get())[y][x] = std::make_unique<Floor>(x, y);
                break;
            case '#':
                (*room.get())[y][x] = std::make_unique<Wall>(x, y);
                break;            
            case '+':
                (*room.get())[y][x] = std::make_unique<DestructibleWall>(x, y);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
                (*room.get())[y][x] = std::make_unique<Tree>(x, y);
                break;
            case '-':
                game->setPlayer(
                    (int)(WINDOW_WIDTH - SIZE_FACTOR * WIDTH_OF_ROOM * SIZE_OF_A_TILE)/2 + x * SIZE_FACTOR * SIZE_OF_A_TILE,
                    (int)(WINDOW_HEIGHT - SIZE_FACTOR * HEIGHT_OF_ROOM * SIZE_OF_A_TILE)/2 + y * SIZE_FACTOR * SIZE_OF_A_TILE
                );
                (*room.get())[y][x] = std::make_unique<Floor>(x, y);
                break;
            case 'H':
                (*room.get())[y][x] = std::make_unique<HeartBonus>(x, y);
                break;
            case 'S':
                (*room.get())[y][x] = std::make_unique<HealthBonus>(x, y);
                break;
            case 'D':
                (*room.get())[y][x] = std::make_unique<DamageBonus>(x, y);
                break;
            case 'V':
                (*room.get())[y][x] = std::make_unique<SpeedBonus>(x, y);
                break;
            default:
                (*room.get())[y][x] = std::make_unique<Void>(x, y);
                break;
        }
        x++;
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