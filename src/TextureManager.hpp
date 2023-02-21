#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "GameEngine.hpp"

class TextureManager{
    public:
        static SDL_Texture* rectTexture(SDL_Renderer *renderer, SDL_Rect rect, SDL_Color c);
};


#endif