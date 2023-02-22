#include "Player1.hpp"


void Player1::update(){
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

void Player1::draw(){
    GameObject::draw();
}

void Player1::setDirection(int d){
    dir = d;
}