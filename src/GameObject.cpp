#include "GameObject.hpp"
#include "TextureManager.hpp"

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

void GameObject::update(float dt){
}

void GameObject::draw(){
    SDL_RenderCopy(renderer, objTexture, &srect, &drect);
}