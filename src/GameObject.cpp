#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(SDL_Renderer *rend, std::string texture, int x, int y, int width, int height){
    renderer = rend;
    objTexture = TextureManager::LoadTexture(renderer, texture);
    c = new BoxCollider2D();
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
    c = nullptr;
}

void GameObject::update(float dt){
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
}

void GameObject::draw(){
    SDL_RenderCopy(renderer, objTexture, &srect, &drect);
}

void GameObject::addCollider(){
    c->updateCollider(xpos, ypos, xpos+w, ypos+h);
}