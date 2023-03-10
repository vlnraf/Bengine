#include "Player.hpp"
#include <tuple>

Player::Player(std::string objectTag, int x, int y, int width, int height) : GameObject(x, y, width, height){
    tag = objectTag;
    keyboardManager = new KeyboardManager();
    xvel = 0;
    yvel = 0;
}

Player::~Player(){
    delete keyboardManager;
}
void Player::updateObject(float dt){
    xpos += xvel * dt;
    ypos += yvel * dt;

    std::string collName;
    collName = c->getInfos().collisionName;
    setVelocity(0,0);
    if(tag == "player1"){
        if(keyboardManager->getState()[SDL_SCANCODE_W] && collName != "screenwallt"){
            setVelocity(0,-3);
        }
        if(keyboardManager->getState()[SDL_SCANCODE_S] && collName != "screenwallb"){
            setVelocity(0,3);
        }
    }
    if(tag == "player2"){
        if(keyboardManager->getState()[SDL_SCANCODE_I] && collName != "screenwallt"){
            setVelocity(0,-3);
        }
        if(keyboardManager->getState()[SDL_SCANCODE_K] && collName != "screenwallb"){
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
