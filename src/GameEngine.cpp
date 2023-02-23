#include "GameEngine.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
//#include "Player2.hpp"
#include "Ball.hpp"
#include "BoxCollider2d.hpp"
#include "CollisionManager.hpp"

//SDL_Rect drect;
//GameObject *player;
CollisionManager *cm;
Player *player;
Player *player2;
Ball *ball;


GameEngine::GameEngine(){}
GameEngine::~GameEngine(){}

void GameEngine::initialize(std::string title, int x, int y, int w, int h, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL Tests", x, y, w, h, flags);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    isRunning = true;

    if(!window){
        std::cout << "Error creating the window" << std::endl;
        isRunning = false;
    }

    //player = new GameObject(renderer, "assets/p1texture.png", 0, 0, 20, 100);
    player = new Player(renderer, "assets/p1texture.png", 10, (HEIGHT /2) - 50, 10, 100);
    player2 = new Player(renderer, "assets/p2texture.png", (WIDTH-20)-10, HEIGHT/2 - 50, 10, 100);
    ball = new Ball(renderer, "assets/balltexture.png", WIDTH/2 - 5, HEIGHT/2 - 5, 10, 10);

    player->addCollider("player1");
    player2->addCollider("player2");
    ball->addCollider("ball");
    cm = new CollisionManager(WIDTH, HEIGHT);
    cm->pushCollider(player->c);
    cm->pushCollider(player2->c);
    cm->pushCollider(ball->c);
};

void GameEngine::eventHandler(){
    SDL_Event ev;
    //SDL_PollEvent(&ev);
    while(SDL_PollEvent(&ev))
    {
        switch (ev.type){
            case SDL_QUIT:
                isRunning = false;
                break;

            default:
                break;
        }

        const Uint8 * keystates = SDL_GetKeyboardState(NULL);
        
        player->setVelocity(0);

        if(keystates[SDL_SCANCODE_W]){
            player->setVelocity(-3);
        }

        if(keystates[SDL_SCANCODE_S]){
            player->setVelocity(3);
        }

        player2->setVelocity(0);
        if(keystates[SDL_SCANCODE_I]){
            player2->setVelocity(-3);
        }

        if(keystates[SDL_SCANCODE_K]){
            player2->setVelocity(3);
        }
    }

};

void GameEngine::update(){
    player->update(dt);
    player2->update(dt);
    ball->update(dt);
    cm->checkCollision();
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
    player = nullptr;
    player2 = nullptr;
    ball = nullptr;
    std::cout << "Memory cleaned" << std::endl;
};

bool GameEngine::run(){
    return isRunning;
}
