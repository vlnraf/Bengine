#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL2/SDL.h>

class GameEngine{
    public:
        GameEngine();
        ~GameEngine();

        void initialize(std::string title, int x, int y, int w, int h, bool fullscreen);
        void eventHandler();
        void draw();
        void update();
        void destroy();

        bool run();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool isRunning;

};
#endif