#include "Player2.hpp"


void Player2::update(float dt){
    ypos += vel * dt;
    GameObject::update(dt);

    //if(c->getBoxTop() < 0){ // Prevent the player to go over the top screen
    //    ypos = 0;
    //    GameObject::update(dt);
    //}

    //if(c->getBoxBottom() > HEIGHT){ // Prevent the player to go over the bottom of the screen
    //    ypos = HEIGHT-drect.h;
    //    GameObject::update(dt);
    //}

    drect.x = xpos;
    drect.y = ypos;
}

void Player2::draw(){
    GameObject::draw();
}

void Player2::setVelocity(int v){
    vel = v;
}

void Player2::addCollider(std::string name){
    GameObject::addCollider(name);
}