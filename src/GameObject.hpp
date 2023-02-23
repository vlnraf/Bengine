#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameEngine.hpp"
#include "BoxCollider2d.hpp"

class GameObject{
    public:
        GameObject(SDL_Renderer *rend, std::string texture, int x, int y, int width, int height);
        ~GameObject();

        virtual void update(float dt);
        virtual void draw();
        virtual void addCollider();

    protected:
    int xpos, ypos, w, h;
    BoxCollider2D *c; //In the Future i try to implement an ECS so i can use different colliders and in general different components
    SDL_Texture *objTexture;
    SDL_Renderer *renderer;
    SDL_Rect drect, srect;
};
#endif