#include <chrono>
#include "GameEngine.hpp"

//const int WIDTH = 800, HEIGHT = 600;

int main (int argv, char *args[]){
    const int FPS = 144;
    const int frameDelay = 1000 / FPS;
    int frames = 0;

    Uint32 frameStart;
    float frameTime;

    GameEngine *game = new GameEngine();
    game->initialize("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

    Uint32 ff = SDL_GetTicks();

    while(game->run()){
        frameStart = SDL_GetTicks();

        game->eventHandler();
        game->update();
        game->draw();
        frames++;

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            if((SDL_GetTicks() - ff) >= 1000){ //to print the FPS of the application on the console
                std::cout<< "fps: " << frames << std::endl;
                frames=0;
                ff = SDL_GetTicks();
            }
            SDL_Delay(frameDelay - frameTime);
            game->dt = (float) (frameDelay - frameTime) / 10;
        }
    }

    game->destroy();
    delete game;
    game = nullptr;
    return 0;
}
