#include "GameEngine.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "BoxCollider2d.hpp"
#include "CollisionManager.hpp"

CollisionManager *cm;


GameEngine::GameEngine(std::string title, int x, int y, int w, int h, bool fullscreen){
    int flags = 0;
    WIDTH = w;
    HEIGHT = h;
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

    cm = CollisionManager::Istance();
    cm->setScreen(WIDTH, HEIGHT);

}

GameEngine::~GameEngine(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cm->destroy();
    window = nullptr;
    renderer = nullptr;
    cm = nullptr;
    std::cout << "Memory cleaned" << std::endl;
}

void GameEngine::initialize(std::string title, int x, int y, int w, int h, bool fullscreen){
};

void GameEngine::eventHandler(){
    // This is only the eventHandler of the application itself
    // it probably should be decoupled in a new entity "ApplicationHandler"
    SDL_Event ev;
    SDL_PollEvent(&ev);
    while(SDL_PollEvent(&ev))
    {
        switch (ev.type){
            case SDL_QUIT:
                isRunning = false;
                break;

            default:
                break;
        }
    }

};

void GameEngine::update(){
    cm->checkCollision();
    SDL_RenderClear(renderer);
};

void GameEngine::setBackground(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha){
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha );
}

void GameEngine::draw(){
}

void GameEngine::display(){
    SDL_RenderPresent(renderer);
}

void GameEngine::destroy(){}

void GameEngine::run(){
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    int frames = 0;

    Uint32 frameStart;
    float frameTime;

    Uint32 ff = SDL_GetTicks();

    while(isRunning){
        frameStart = SDL_GetTicks();

        eventHandler();
        update();
        draw();
        frames++;

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            if((SDL_GetTicks() - ff) >= 1000){ //to print the FPS of the application on the console
                std::cout<< "fps: " << frames << std::endl;
                frames=0;
                ff = SDL_GetTicks();
            }
            SDL_Delay(frameDelay - frameTime);
            dt = (float) (frameDelay - frameTime) / 10;
        }
    }

    destroy();
}

