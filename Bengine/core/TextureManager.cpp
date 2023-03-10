#include "TextureManager.hpp"
#include "Renderer.hpp"
#include "SDL_surface.h"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(std::string objectTexture){
    SDL_Surface* surface = IMG_Load(objectTexture.c_str());
    SDL_Texture* texture = Renderer::createTexture(surface);
    //SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    return texture;
};

SDL_Texture* TextureManager::createRGBTexture(const uint32_t r, const uint32_t g, const uint32_t b, const uint32_t a){
    SDL_Surface* surface = SDL_CreateRGBSurface(0, 100, 100, 8, r, g, b, a);
    SDL_Texture* texture = Renderer::createTexture(surface);
    SDL_FreeSurface(surface);
    
    return texture;
};
