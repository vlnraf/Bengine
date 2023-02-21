#include "GameEngine.hpp"
#include <iostream>
#include <SDL2/SDL.h>

GameEngine::GameEngine(){}
GameEngine::~GameEngine(){}

void GameEngine::initialize(std::string p){
    message = p;
};

void GameEngine::run(){
    std::cout << message << std::endl;
    while(count < 10){
        std::cout << count << std::endl;
        count++;
    }
}