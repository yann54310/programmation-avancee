#include "Menu.hpp"

Menu::Menu(): _selection(0)
            , _deltaMove(0)
{
    _utils = Utils::GetInstance();

    if(SDL_SetRenderDrawColor(_utils->_renderer,
                                0,
                                0,
                                0,
                                255) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return;
    }

    SDL_Color red = (SDL_Color){255, 0, 0, 255};
    SDL_Color white = (SDL_Color){255, 255, 255, 255};
    std::string nom;
    SDL_Rect rect;

    nom = "jouer";
    rect = (SDL_Rect){100, 100
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), red, rect, nom));

    nom = "option";
    rect = (SDL_Rect){200, 200
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), white, rect, nom));  

    nom = "quitter";
    rect = (SDL_Rect){300, 300
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), white, rect, nom));

    _buttons[2].get()->addEvent(SDLK_RETURN, Event::QUITTER);
}

Menu::~Menu()
{
    
}

void Menu::Init()
{
    
}

void Menu::Stop()
{
    for(std::shared_ptr<Button> b : _buttons)
    {
        b->Stop();
        b = nullptr;
    }
}

        
void Menu::Pause()
{
    
}

void Menu::Resume()
{
    
}


void Menu::HandleEvents()
{
    while (SDL_PollEvent(&_utils->_events))
    {
        switch(_utils->_events.type)
        {
            case SDL_QUIT:
                _utils->_stateMan->Quit();
                break;
            case SDL_KEYDOWN:
                switch(_utils->_events.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        if(_selection < (int)_buttons.size()-1) { _selection++; _deltaMove++; };
                        break;
                    case SDLK_UP:
                        if(_selection > 0) { _selection--; _deltaMove--; };
                        break;
                    case SDLK_RETURN:
                        _buttons[_selection].get()->HandleEvents(SDLK_RETURN);
                }
                break;
            default:
                _deltaMove = 0;
                break;
        }
    }
}

void Menu::Update()
{

}

inline void Menu::_loadSelection()
{
    if(_deltaMove == 0)
        return;

    _buttons[_selection].get()->SetColor((SDL_Color){255, 0, 0, 255});
    _buttons[_selection - _deltaMove].get()->SetColor((SDL_Color){255, 255, 255, 255});
}

void Menu::Draw()
{
    _loadSelection();
    
    for(const std::shared_ptr<Button>& b : _buttons)
        b->Draw();

    SDL_RenderPresent(_utils->_renderer);

    if(SDL_RenderClear(_utils->_renderer) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s at line %d : %s\n", __FILE__, __LINE__, SDL_GetError());
        _utils->_stateMan->Quit();
        return;
    }
}
