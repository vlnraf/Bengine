#include "Player.hpp"
#include <tuple>

Player::Player(SDL_Renderer* rend, std::string objectTag, std::string texture, int x, int y, int width, int height) : GameObject(rend,texture, x, y, width, height){
    tag = objectTag;
    keyboardManager = new KeyboardManager();
    xvel = 0;
    yvel = 0;
}
void Player::updateObject(float dt){
    xpos += xvel * dt;
    ypos += yvel * dt;

    std::string collName;
    collName = c->getInfos().collisionName;
    if(collName == "screenwallt"){
        yvel = 0;
    }
    if(collName == "screenwallb"){
        yvel = 0;
    }
    setVelocity(0,0);
    if(tag == "player1"){
        if(keyboardManager->getState()[SDL_SCANCODE_W]){
            setVelocity(0,-3);
        }
        if(keyboardManager->getState()[SDL_SCANCODE_S]){
            setVelocity(0,3);
        }
    }
    if(tag == "player2"){
        if(keyboardManager->getState()[SDL_SCANCODE_I]){
            setVelocity(0,-3);
        }
        if(keyboardManager->getState()[SDL_SCANCODE_K]){
            setVelocity(0,3);
        }
    }
    GameObject::updateObject(dt);
    c->setCollision("");

    drect.x = xpos;
    drect.y = ypos;
}

void Player::drawObject(){
    GameObject::drawObject();
}

void Player::setVelocity(int xv, int yv){
    xvel = xv;
    yvel = yv;
}
