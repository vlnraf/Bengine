#include "Player2.hpp"


void Player2::update(){
    ypos += vel * dir;

    if(ypos < 0){ // Prevent the player to go over the top screen
        ypos = 0;
    }

    if(ypos > HEIGHT-100){
        ypos = HEIGHT-100;
    }

    drect.x = xpos;
    drect.y = ypos;
}

void Player2::draw(){
    GameObject::draw();
}

void Player2::setDirection(int d){
    dir = d;
}