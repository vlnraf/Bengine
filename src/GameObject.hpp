#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "GameEngine.hpp"
#include "CollisionManager.hpp"
#include "BoxCollider2d.hpp"

class GameObject{
    public:

        GameObject(SDL_Renderer *rend, std::string texture, int x, int y, int width, int height);
        virtual ~GameObject();

        virtual void update(float dt);
        virtual void draw();
        virtual void addCollider(std::string name);

    protected:
    BoxCollider2D *c; 
    CollisionManager *cm;
    float xpos, ypos, w, h;
    //bool collided;
    SDL_Texture *objTexture;
    SDL_Renderer *renderer;
    SDL_Rect drect, srect;
};
#endif
