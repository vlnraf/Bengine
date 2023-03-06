#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <SDL2/SDL.h>

class GameEngine{
    public:
        float dt = 0;
        int WIDTH = 800, HEIGHT = 600;

        GameEngine(std::string title, int x, int y, int w, int h, bool fullscreen);
        virtual ~GameEngine();

        void initialize(std::string title, int x, int y, int w, int h, bool fullscreen);
        void eventHandler();
        void setBackground(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        void display();
        virtual void draw();
        virtual void update();
        virtual void destroy();

        void run();

    protected:
        SDL_Renderer *renderer;

    private:
        bool isRunning;
        SDL_Window *window;

};
#endif
