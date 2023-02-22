#include "Player2.hpp"


void Player2::update(){
    ypos += vel * dir;
    drect.x = xpos;
    drect.y = ypos;
}

void Player2::draw(){
    GameObject::draw();
}

void Player2::setDirection(int d){
    dir = d;
}