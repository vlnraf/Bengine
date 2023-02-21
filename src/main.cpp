#include "GameEngine.hpp"

const int WIDTH = 800, HEIGHT = 600;

int main (int argv, char *args[]){
    GameEngine *game = new GameEngine();
    game->initialize("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

    while(game->run()){
        game->eventHandler();
        game->update();
        game->draw();
    }

    game->destroy();
    game = nullptr;
    return 0;
}