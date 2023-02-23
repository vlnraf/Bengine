#include "Ball.hpp"
#include <time.h>
#include <random>

#define SPEED_BALL 3.0f

Ball::Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height) : GameObject(renderer, texture, x, y, width, height){
    initDirection();
}

void Ball::update(float dt){
    GameObject::update(dt);
    xpos += xvel * dt;
    ypos += yvel * dt;
    //std::cout<<c->getBoxBottom()<< " "<< c->getBoxLeft() << " "<< c->getBoxRigth() << " "<< c->getBoxTop() << std::endl;

    checkBorders();

    drect.x = xpos;
    drect.y = ypos;
}

void Ball::draw(){
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

void Ball::addCollider(){
    GameObject::addCollider();
}

void Ball::checkBorders(){
    if(ypos < 0){ // Prevent the ball to go over the top screen
        yvel *= -1;
    }

    if(ypos > HEIGHT-drect.h){ //Prevent the ball to go over the bottom of the screen
        yvel *= 1;
    }

    if(xpos < 0){ // Reset ball if left wall is hitted
        xpos = WIDTH /2;
        ypos = HEIGHT /2;
    }

    if(xpos > WIDTH-drect.w){ //Reset ball if right wall is hitted
        xpos = WIDTH /2;
        ypos = HEIGHT /2;
    }
}