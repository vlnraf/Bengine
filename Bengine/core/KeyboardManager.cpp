#include "KeyboardManager.hpp"

KeyboardManager::KeyboardManager(){
    SDL_Event ev;
    SDL_PollEvent(&ev);
}
KeyboardManager::~KeyboardManager(){
}

const uint8_t* KeyboardManager::getState() const{
    const uint8_t* keystates = SDL_GetKeyboardState(nullptr);
    return keystates;
}
