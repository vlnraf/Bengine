#include "Renderer.hpp"

SDL_Renderer* Renderer::renderer;
uint8_t Renderer::backRed, Renderer::backGreen, Renderer::backBlue, Renderer::backAlpha;

void Renderer::init(SDL_Window *window){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}           
void Renderer::destroy(){
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}
            
void Renderer::drawLine(){}

void Renderer::drawRect(const SDL_Rect *rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    Renderer::setColor(red , green, blue, alpha);
    SDL_RenderFillRect(renderer, rect);
    Renderer::setBGColor(backRed,backGreen,backBlue,backAlpha);
}

void Renderer::drawCircle(){}

void Renderer::setBGColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    backRed = red;
    backGreen = green;
    backBlue = blue;
    backAlpha = alpha;
    SDL_SetRenderDrawColor(renderer, backRed, backGreen, backBlue, backAlpha);
}
void Renderer::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha );
}

void Renderer::drawSprite(SDL_Texture* texture, const SDL_Rect &srect, const SDL_Rect &drect){
    SDL_RenderCopy(renderer, texture, &srect, &drect);
}

SDL_Texture* Renderer::createTexture(SDL_Surface* surface){
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}

void Renderer::render(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}
