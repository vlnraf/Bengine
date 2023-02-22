#include "GameEngine.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player1.hpp"

SDL_Rect drect;
GameObject *ball;
//GameObject *player;
Player1 *player;
GameObject *player2;


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

    //player = new GameObject(renderer, "assets/p1texture.png", 0, 0, 20, 100);
    player = new Player1(renderer, "assets/p1texture.png", 0, 0, 20, 100);
    player2 = new GameObject(renderer, "assets/p1texture.png", WIDTH-20, 0, 20, 100);
    ball = new GameObject(renderer, "assets/p1texture.png", WIDTH/2, HEIGHT/2, 10, 10);
};

void GameEngine::eventHandler(){
    SDL_Event ev;
    SDL_PollEvent(&ev);
    switch (ev.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            player->event(ev);
    
        default:
            break;
    }
};

void GameEngine::update(){
    player->update();
    player2->update();
};

void GameEngine::draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0 );
    SDL_RenderClear(renderer);

    player->draw();
    player2->draw();
    ball->draw();

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
