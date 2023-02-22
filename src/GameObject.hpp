#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameEngine.hpp"

class GameObject{
    public:
        GameObject(SDL_Renderer *rend, std::string texture, int x, int y, int width, int height);
        ~GameObject();

        virtual void update(float dt);
        virtual void draw();

    protected:
    SDL_Texture *objTexture;
    SDL_Renderer *renderer;
    int xpos, ypos, w, h;
    SDL_Rect drect, srect;

};
#endif