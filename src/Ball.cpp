#include "Ball.hpp"
#include <time.h>
#include <random>

Ball::Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height) : GameObject(renderer, texture, x, y, width, height){
    initDirection();
}

void Ball::update(float dt){
    xpos += (xvel) * dt;
    ypos += (yvel) * dt;

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
        xvel = 3;
    }else{
        xvel = -3;
    }
}

void Ball::checkBorders(){
    if(ypos < 0){ // Prevent the ball to go over the top screen
        ydir = ydir * -1;
    }

    if(ypos > HEIGHT-drect.h){ //Prevent the ball to go over the bottom of the screen
        ydir = ydir * -1;
    }

    //if(xpos < 0){ 
    //    xpos = WIDTH /2;
    //    ypos = HEIGHT /2;
    //}

    //if(xpos > WIDTH-drect.w){ 
    //    xpos = WIDTH /2;
    //    ypos = HEIGHT /2;
    //}
}