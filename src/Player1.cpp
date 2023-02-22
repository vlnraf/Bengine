#include "Player1.hpp"


void Player1::update(){
    ypos += vel * dir;
    drect.x = xpos;
    drect.y = ypos;
}

void Player1::draw(){
    GameObject::draw();
}

void Player1::setDirection(int d){
    dir = d;
}