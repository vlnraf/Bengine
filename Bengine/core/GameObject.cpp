#include "GameObject.hpp"
#include "SDL_surface.h"
#include "TextureManager.hpp"
#include "Renderer.hpp"

GameObject::GameObject(const int x, const int y, const int width, const int height){
    objTexture = nullptr;
    xpos = x;
    ypos = y;
    w = width;
    h = height;
}

GameObject::~GameObject(){
    SDL_DestroyTexture(objTexture);
    delete c;
    c = nullptr;
}

void GameObject::updateObject(float dt){
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
}

void GameObject::drawObject(){
    srect.h=32;
    srect.w=32;
    srect.x=0;
    srect.y=0;

    drect.h=h;
    drect.w=w;
    drect.x=xpos;
    drect.y=ypos;

    switch (type){
        case spriteType::Rect:
            Renderer::drawRect(&drect, sprite.red, sprite.green, sprite.blue, sprite.alpha);
            break;
        case spriteType::Text:
            Renderer::drawSprite(objTexture, srect, drect);
            break;
        default:
            break;
    };
}

void GameObject::addSprite(const std::string pathSprite){
    type = spriteType::Text;
    objTexture = TextureManager::LoadTexture(pathSprite);
}

void GameObject::addRectSprite(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a){
    type = spriteType::Rect;
    sprite.red = r;
    sprite.green = g;
    sprite.blue = b;
    sprite.alpha = a;
}

void GameObject::addCollider(const std::string name){
    cm = CollisionManager::Istance();
    c = new BoxCollider2D(name);
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
    cm->pushCollider(c);
}
