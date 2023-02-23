#include "Player2.hpp"


void Player2::update(float dt){
    GameObject::update(dt);
    ypos += vel * dt;

    if(ypos < 0){ // Prevent the player to go over the top screen
        ypos = 0;
    }

    if(ypos > HEIGHT-drect.h){
        ypos = HEIGHT-drect.h;
    }

    drect.x = xpos;
    drect.y = ypos;
}

void Player2::draw(){
    GameObject::draw();
}

void Player2::setVelocity(int v){
    vel = v;
}

void Player2::addCollider(){
    GameObject::addCollider();
}