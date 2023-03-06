#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "GameEngine.hpp"
#include "CollisionManager.hpp"
#include "BoxCollider2d.hpp"
#include "SDL_render.h"

enum class hit{
    None,
    Top,
    Middle,
    Bottom
};

class GameObject {
    public:

        GameObject(SDL_Renderer* rend,std::string texture, int x, int y, int width, int height);
        virtual ~GameObject();

        virtual void updateObject(float dt);
        virtual void drawObject();
        virtual void addCollider(std::string name);

    protected:
    std::string tag;
    BoxCollider2D *c; 
    CollisionManager *cm;
    float xpos, ypos, w, h;
    SDL_Texture *objTexture;
    SDL_Renderer *renderer;
    SDL_Rect drect, srect;
};
#endif
