#include "Player1.hpp"


void Player1::update(float dt){
    ypos += vel * dt;
    GameObject::update(dt);

    if(c->getBoxTop() < 0){ // Prevent the player to go over the top screen
        ypos = 0;
        GameObject::update(dt);
    }

    if(c->getBoxBottom() > HEIGHT){ // Prevent the player to go over the bottom of the screen
        ypos = HEIGHT-drect.h;
        GameObject::update(dt);
    }

    std::cout<<c->getBoxLeft()<< " "<< c->getBoxRigth() << " "<< c->getBoxTop() << " "<< c->getBoxBottom() << std::endl;

    drect.x = xpos;
    drect.y = ypos;
}

void Player1::draw(){
    GameObject::draw();
}

void Player1::setVelocity(int v){
    vel = v;
}
void Player1::addCollider(){
    GameObject::addCollider();
}