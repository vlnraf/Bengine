#include "Ball.hpp"
#include <time.h>
#include <random>


Ball::Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height) : GameObject(renderer, texture, x, y, width, height){
    initDirection();
}

void Ball::update(float dt){
    xpos += xvel * dt;
    ypos += yvel * dt;
    GameObject::update(dt);
    
   if(collided){
        //std::cout<<"collision"<<std::endl;
        xvel = 0;
        yvel = 0;
        //xvel = -xvel;
        //yvel = -yvel;
        c->setCollision(false);
   }
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