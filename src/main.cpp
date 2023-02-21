#include "GameEngine.hpp"

int main (int argv, char *args[]){
    GameEngine game;
    game.initialize("Ciao Mondo!");
    game.run();
    return 0;
}