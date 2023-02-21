#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL2/SDL.h>

class GameEngine{
    public:
        GameEngine();
        ~GameEngine();

        void initialize(std::string p){
            message = p;
        };
        void run(){
            std::cout << message << std::endl;
            while(true){
                std::cout << count << std::endl;
            }
        };

    private:
    int count = 0;
    std::string message;

};
#endif