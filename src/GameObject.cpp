#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(SDL_Renderer *rend, std::string texture, int x, int y){
    renderer = rend;
    objTexture = TextureManager::LoadTexture(renderer, texture);
    xpos = x;
    ypos = y;

    srect.h=32;
    srect.w=32;
    srect.x=0;
    srect.y=0;

    drect.h=100;
    drect.w=20;
    drect.x=xpos;
    drect.y=ypos;
}

void GameObject::update(){
    drect.y++;
}

void GameObject::draw(){
    SDL_RenderCopy(renderer, objTexture, &srect, &drect);
}