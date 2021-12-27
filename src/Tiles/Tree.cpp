#include "Tree.hpp"

Tree::Tree(): Tile((SDL_Point){0, 1})
{
    
}

Tree::Tree(const float x, const float y): Tile(x, y, (SDL_Point){0, 1})
{
    
}

Tree::~Tree()
{

}
