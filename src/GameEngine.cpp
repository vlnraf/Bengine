#include "GameEngine.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player1.hpp"
#include "Player2.hpp"

SDL_Rect drect;
GameObject *ball;
//GameObject *player;
Player1 *player;
Player2 *player2;


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
    player = new Player1(renderer, "assets/p1texture.png", 10, HEIGHT/2 - 50, 20, 100);
    player2 = new Player2(renderer, "assets/p1texture.png", (WIDTH-20)-10, HEIGHT/2 - 50, 20, 100);
    ball = new GameObject(renderer, "assets/p1texture.png", WIDTH/2, HEIGHT/2 - 10, 10, 10);
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

    const Uint8 * keystates = SDL_GetKeyboardState(NULL);
    
    if(keystates[SDL_SCANCODE_ESCAPE]){
        isRunning = false;
    }

    player->setDirection(0);
    if(keystates[SDL_SCANCODE_W]){
        player->setDirection(-1);
    }

    if(keystates[SDL_SCANCODE_S]){
        player->setDirection(1);
    }

    player2->setDirection(0);
    if(keystates[SDL_SCANCODE_I]){
        player2->setDirection(-1);
    }

    if(keystates[SDL_SCANCODE_K]){
        player2->setDirection(1);
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
