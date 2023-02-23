#include <chrono>
#include "GameEngine.hpp"

//const int WIDTH = 800, HEIGHT = 600;

int main (int argv, char *args[]){
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    int frames = 0;

    Uint32 frameStart;
    float frameTime;

    GameEngine *game = new GameEngine();
    game->initialize("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

    while(game->run()){
        frameStart = SDL_GetTicks();

        game->eventHandler();
        game->update();
        game->draw();
        frames++;

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            game->dt = (float) (frameDelay - frameTime) / 10;
            SDL_Delay(frameDelay - frameTime);
            //std::cout<< "fps: " << frames << std::endl;
            //frames=0;
        }
    }

    game->destroy();
    game = nullptr;
    return 0;
}