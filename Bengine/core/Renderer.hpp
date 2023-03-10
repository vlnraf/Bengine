#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>

class Renderer{
    public:
        static void init(SDL_Window *window);
        static void destroy();
        
        static void drawLine();
        static void drawRect(const SDL_Rect *rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        static void drawCircle();
        static void drawSprite(SDL_Texture* texture, const SDL_Rect &src, const SDL_Rect &dst);
        static void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        static void setBGColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        static SDL_Texture* createTexture(SDL_Surface* surface);
        static void render();

    private:
        static uint8_t backRed, backGreen, backBlue, backAlpha;
        static SDL_Renderer* renderer;
    
};
#endif  
