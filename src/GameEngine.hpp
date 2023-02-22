#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

class GameEngine{
    public:
        float dt = 0;

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