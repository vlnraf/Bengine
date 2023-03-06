#include "GameEngine.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "BoxCollider2d.hpp"
#include "CollisionManager.hpp"

//SDL_Rect drect;
CollisionManager *cm;
//Player *player;
//Player *player2;
//Ball *ball;


GameEngine::GameEngine(std::string title, int x, int y, int w, int h, bool fullscreen){
    int flags = 0;
    WIDTH = w;
    HEIGHT = h;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL Tests", x, y, w, h, flags);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    isRunning = true;

    if(!window){
        std::cout << "Error creating the window" << std::endl;
        isRunning = false;
    }

    //player = new GameObject(renderer, "assets/p1texture.png", 0, 0, 20, 100);
//    player = new Player(renderer, "assets/p1texture.png", 10, (HEIGHT /2) - 50, 10, 100);
//    player2 = new Player(renderer, "assets/p2texture.png", (WIDTH-20)-10, HEIGHT/2 - 50, 10, 100);
//    ball = new Ball(renderer, "assets/balltexture.png", WIDTH/2 - 5, HEIGHT/2 - 5, 10, 10);

    cm = CollisionManager::Istance();
    cm->setScreen(WIDTH, HEIGHT);

//    player->addCollider("player1");
//    player2->addCollider("player2");
//    ball->addCollider("ball");

}

GameEngine::~GameEngine(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
//    delete player;
//    delete player2;
//    delete ball;
    cm->destroy();
    //delete cm;
    window = nullptr;
    renderer = nullptr;
//    player = nullptr;
//    player2 = nullptr;
//    ball = nullptr;
    cm = nullptr;
    std::cout << "Memory cleaned" << std::endl;
}

void GameEngine::initialize(std::string title, int x, int y, int w, int h, bool fullscreen){
};

void GameEngine::eventHandler(){
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
        //const Uint8 * keystates = SDL_GetKeyboardState(NULL);
        
//        player->setVelocity(0,0);
//
        //if(keystates[SDL_SCANCODE_W]){
//            player->setVelocity(0,-3);
        //}
//
//        if(keystates[SDL_SCANCODE_S]){
//            player->setVelocity(0, 3);
//        }
//
//        player2->setVelocity(0,0);
//        if(keystates[SDL_SCANCODE_I]){
//            player2->setVelocity(0, -3);
//        }
//
//        if(keystates[SDL_SCANCODE_K]){
//            player2->setVelocity(0, 3);
//        }
    }

};

void GameEngine::update(){
//    player->update(dt);
//    player2->update(dt);
//    ball->update(dt);
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

    //GameEngine *game = new GameEngine();
    //initialize("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

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

//bool GameEngine::run(){
//    return isRunning;
//}
