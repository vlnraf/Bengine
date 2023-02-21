#include "GameEngine.hpp"

GameEngine::GameEngine(){}
GameEngine::~GameEngine(){}

void GameEngine::initialize(std::string title, int x, int y, int w, int h, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL Tests", x, y, w, h, flags);

    isRunning = true;

    if(!window){
        std::cout << "Error creating the window" << std::endl;
        isRunning = false;
    }
};

void GameEngine::eventHandler(){
    SDL_Event ev;
    SDL_PollEvent(&ev);
    switch (ev.type){
        case SDL_QUIT:
            isRunning = false;
            break;
    
        default:
            break;
    }
};

void GameEngine::renderer(){

};

void GameEngine::update(){
};

bool GameEngine::run(){
    return isRunning;
}

void GameEngine::destroy(){
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Memory cleaned" << std::endl;
};