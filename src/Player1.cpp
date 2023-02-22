#include "Player1.hpp"


void Player1::event(SDL_Event e){
    if(e.key.keysym.sym == SDLK_s){
        ypos++;
    }
    if(e.key.keysym.sym == SDLK_w){
        ypos--;
    }
}

void Player1::update(){
    drect.y = ypos;
    drect.x = xpos;
}

void Player1::draw(){
    GameObject::draw();
}