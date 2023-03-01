#include "GameObject.hpp"
#include "TextureManager.hpp"
#include <SDL2/SDL_mutex.h>
#include <SDL2/SDL_render.h>

GameObject::GameObject(SDL_Renderer *rend, std::string texture, int x, int y, int width, int height){
    renderer = rend;
    objTexture = TextureManager::LoadTexture(renderer, texture);
    xpos = x;
    ypos = y;
    w = width;
    h = height;


    srect.h=32;
    srect.w=32;
    srect.x=0;
    srect.y=0;

    drect.h=h;
    drect.w=w;
    drect.x=xpos;
    drect.y=ypos;
}

GameObject::~GameObject(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(objTexture);
    delete c;
    c = nullptr;
    //cm->destroy();
}

void GameObject::update(float dt){
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
}

void GameObject::draw(){
    SDL_RenderCopy(renderer, objTexture, &srect, &drect);
}

void GameObject::addCollider(std::string name){
    cm = CollisionManager::Istance();
    c = new BoxCollider2D(name);
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
    cm->pushCollider(c);
}
