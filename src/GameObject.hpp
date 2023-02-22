#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameEngine.hpp"

class GameObject{
    public:
        GameObject(SDL_Renderer *renderer, std::string texture, int x, int y);
        ~GameObject();

        void update();
        void draw();

    private:
    int xpos, ypos;
    SDL_Rect drect, srect;
    SDL_Texture *objTexture;
    SDL_Renderer *renderer;
};
#endif