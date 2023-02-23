#include "Ball.hpp"
#include <time.h>
#include <random>
#include <tuple>


Ball::Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height) : GameObject(renderer, texture, x, y, width, height){
    initDirection();
}

void Ball::update(float dt){
    bool coll;
    std::string collName;
    std::tie(coll, collName) = c->getCollision();
    if(coll){
        if(collName == "player1" || collName == "player2"){
            xvel = -xvel;
            //yvel = 0;
        }
        if(collName == "screenwallr" || collName == "screenwalll"){ // those are fixed objects that determine the screen walls
            //TODO: give a point to the player
            xpos = WIDTH /2;
            ypos = HEIGHT /2;
        }
        if(collName == "screenwallt" || collName == "screenwallb"){ // those are fixed objects that determine the screen walls
            yvel = -yvel;
        }
        c->setCollision(false, "");
    }
    xpos += xvel * dt;
    ypos += yvel * dt;
    GameObject::update(dt);
    
}

void Ball::draw(){
    drect.x = xpos;
    drect.y = ypos;
    GameObject::draw();
}

void Ball::initDirection(){
    srand(time(0));
    int randN = rand() % 2 -1;

    if(randN == 0){
        xvel = SPEED_BALL;
    }else{
        xvel = -SPEED_BALL;
    }
}

void Ball::addCollider(std::string name){
    GameObject::addCollider(name);
}