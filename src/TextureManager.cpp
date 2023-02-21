#include "TextureManager.hpp"

SDL_Texture* TextureManager::rectTexture(SDL_Renderer *renderer, SDL_Rect rect, SDL_Color c){
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 2000, 2000);
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);
    
    return texture;
};