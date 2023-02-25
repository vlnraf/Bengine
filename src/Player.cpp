#include "Player.hpp"
#include <tuple>


void Player::update(float dt){
    ypos += vel * dt;
    GameObject::update(dt);

    //bool coll;
    std::string collName;
    //std::tie(coll, collName) = c->getCollision();
    collName = c->getInfos().collisionName;
    std::cout<<collName<<std::endl;
    //if(coll){
    if(collName == "screenwallt"){
        ypos = 0;
    }
    if(collName == "screenwallb"){
        ypos = HEIGHT - h;
    }
    c->setCollision("");
    //}
    
    //if(c->getBoxTop() < 0){ // Prevent the player to go over the top screen
    //    ypos = 0;
    //}

    //if(c->getBoxBottom() > HEIGHT){ // Prevent the player to go over the bottom of the screen
    //    ypos = HEIGHT-drect.h;
    //}

    drect.x = xpos;
    drect.y = ypos;
}

void Player::draw(){
    GameObject::draw();
}

void Player::setVelocity(int v){
    vel = v;
}
void Player::addCollider(std::string name){
    GameObject::addCollider(name);
}