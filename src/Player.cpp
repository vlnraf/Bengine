#include "Player.hpp"
#include <tuple>

Player::Player(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height) : GameObject(renderer, texture, x, y, width, height){
    xvel = 0;
    yvel = 5;
}
void Player::update(float dt){
    xpos += xvel * dt;
    ypos += yvel * dt;
    GameObject::update(dt);

    //bool coll;
    std::string collName;
    //std::tie(coll, collName) = c->getCollision();
    collName = c->getInfos().collisionName;
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

void Player::setVelocity(int xv, int yv){
    xvel = xv;
    yvel = yv;
}

//void Player::addCollider(std::string name){
//    GameObject::addCollider(name);
//}
