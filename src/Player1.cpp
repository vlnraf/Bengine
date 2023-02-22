#include "Player1.hpp"


void Player1::update(float dt){
    ypos += vel * dt;

    if(ypos < 0){ // Prevent the player to go over the top screen
        ypos = 0;
    }

    if(ypos > HEIGHT-drect.h){ // Prevent the player to go over the bottom of the screen
        ypos = HEIGHT-drect.h;
    }

    drect.x = xpos;
    drect.y = ypos;
}

void Player1::draw(){
    GameObject::draw();
}

void Player1::setVelocity(int v){
    vel = v;
}