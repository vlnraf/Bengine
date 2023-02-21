#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>

class GameEngine{
    public:
        GameEngine();
        ~GameEngine();

        void initialize(std::string p);
        void run();

    private:
    int count = 0;
    std::string message;

};
#endif