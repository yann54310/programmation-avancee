#include "Menu.hpp"

Menu::Menu(): State(),
            _selection(0)
            , _deltaMove(0)
{
    SDL_Color red = (SDL_Color){255, 0, 0, 255};
    SDL_Color white = (SDL_Color){255, 255, 255, 255};
    std::string nom;
    SDL_Rect rect;

    nom = "jouer";
    rect = (SDL_Rect){100, 100
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), red, rect, nom));

    _buttons.back().get()->addEvent(SDLK_RETURN, Event::JOUER);

    nom = "option";
    rect = (SDL_Rect){200, 200
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), white, rect, nom));  

    _buttons.back().get()->addEvent(SDLK_RETURN, Event::OPTION);

    nom = "quitter";
    rect = (SDL_Rect){300, 300
                    , (int)nom.size()*_utils->_fonts["ttf_kenny"].get()->getSize()
                    , _utils->_fonts["ttf_kenny"].get()->getSize()};
    _buttons.push_back(std::make_shared<Button>(_utils->_fonts["ttf_kenny"].get(), white, rect, nom));

    _buttons.back().get()->addEvent(SDLK_RETURN, Event::QUITTER);
}

Menu::~Menu()
{
    this->Stop();
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
                        break;
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
    for(int i = _deltaMove; i != 0; i > 0 ? i-- : i++)
        _buttons[_selection - i].get()->SetColor((SDL_Color){255, 255, 255, 255});
}

void Menu::Draw()
{
    _loadSelection();

    for(const std::shared_ptr<Button>& b : _buttons)
        b->Draw();

    State::Draw();
}
