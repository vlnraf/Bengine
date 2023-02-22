#include "TextureManager.hpp"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer *renderer, std::string objectTexture){
    //SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1000, 1000);
    //SDL_SetRenderTarget(renderer, texture);
    //SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    //SDL_RenderClear(renderer);
    //SDL_SetRenderTarget(renderer, NULL);

    SDL_Surface *surface = IMG_Load(objectTexture.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    return texture;
};