#include "GameEngine.hpp"
#include "TextureManager.hpp"

SDL_Texture *texture;
SDL_Rect drect;

GameEngine::GameEngine(){}
GameEngine::~GameEngine(){}

void GameEngine::initialize(std::string title, int x, int y, int w, int h, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL Tests", x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    isRunning = true;

    if(!window){
        std::cout << "Error creating the window" << std::endl;
        isRunning = false;
    }

    SDL_Color color = {255,0,0,255};
    texture = TextureManager::rectTexture(renderer, drect, color);
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

void GameEngine::update(){
    drect.h=100;
    drect.w=20;
    drect.x=10;
    drect.y++;
};

void GameEngine::draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0 );
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture, NULL, &drect);

    SDL_RenderPresent(renderer);
};

void GameEngine::destroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    window = nullptr;
    renderer = nullptr;
    std::cout << "Memory cleaned" << std::endl;
};

bool GameEngine::run(){
    return isRunning;
}
