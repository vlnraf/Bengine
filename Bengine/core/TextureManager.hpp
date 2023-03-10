#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <iostream>

#define _COLOR(RED, GREEN, BLUE)    { RED, GREEN, BLUE, 0xFF }
#define COLOR(RED, GREEN, BLUE)     ((SDL_Color) { RED, GREEN, BLUE, 0xFF })

const SDL_Color BLACK         = _COLOR(0, 0, 0);
const SDL_Color WHITE         = _COLOR(0xFF, 0xFF, 0xFF);
const SDL_Color GRAY          = _COLOR(0x64, 0x64, 0x64);
const SDL_Color DARK_GRAY     = _COLOR(0x1E, 0x1E, 0x1E);
const SDL_Color LIGHT_GRAY    = _COLOR(0xC8, 0xC8, 0xC8);
const SDL_Color RED           = _COLOR(0xF5, 0x3B, 0x56);
const SDL_Color GREEN         = _COLOR(0x01, 0x9F, 0x13);
const SDL_Color BLUE          = _COLOR(0x38, 0x95, 0xD3);
const SDL_Color YELLOW        = _COLOR(0xF7, 0xDC, 0x11);
const SDL_Color ORANGE        = _COLOR(0xFF, 0x85, 0);
const SDL_Color PINK          = _COLOR(0xFF, 0, 0xCE);
const SDL_Color VIOLET        = _COLOR(0x91, 0, 0xFF);

class TextureManager{
    public:
        static SDL_Texture* LoadTexture(std::string texture);
        static SDL_Texture* createRGBTexture(const uint32_t r, const uint32_t g, const uint32_t b, const uint32_t a);
};


#endif
