#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "GameEngine.hpp"
#include "CollisionManager.hpp"
#include "BoxCollider2d.hpp"
#include "SDL_render.h"

enum class spriteType{
    Text,
    Rect,
};

struct Sprite{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

class GameObject {
    public:

        GameObject(const int x, const int y, const int width, const int height);
        virtual ~GameObject();

        virtual void updateObject(float dt);
        void addSprite(const std::string pathSprite);
        void addRectSprite(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);
        virtual void drawObject();
        virtual void addCollider(const std::string name);

    protected:
    std::string tag;
    spriteType type;
    Sprite sprite;

    BoxCollider2D *c; 
    CollisionManager *cm;

    float xpos, ypos, w, h;

    SDL_Texture *objTexture;
    SDL_Rect drect, srect;

};
#endif
