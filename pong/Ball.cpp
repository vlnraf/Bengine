#include "Ball.hpp"
#include <time.h>
#include <random>
#include <tuple>


Ball::Ball(int x, int y, int width, int height) : GameObject(x, y, width, height){
    xvel=0;
    yvel=0;
    xinit=x;
    yinit=y;
    initDirection();
}


void Ball::updateObject(float dt){
    //bool coll;
    std::string collName;
    collName = c->getInfos().collisionName;
    //int paddleLeft = c->getInfos().lhit;
    //int paddleRight = c->getInfos().rhit;
    int paddleTop = c->getInfos().thit;
    int paddleBot = c->getInfos().bhit;
    float paddleRangeMiddle = paddleBot - ((float) (paddleBot - paddleTop)) / 3;
    float paddleRangeUp = paddleBot - (((float) (paddleBot - paddleTop)) * 2) /3;

    if(collName == "player1" || collName == "player2"){
        if((c->getBoxBottom() > paddleTop) && (c->getBoxBottom() < paddleRangeUp)){
            xvel = -xvel;
            yvel = -.75 * SPEED_BALL;
        }else if(c->getBoxBottom() > paddleTop && (c->getBoxBottom() < paddleRangeMiddle)){
            xvel = -xvel;
            yvel = 0;
        }else{
            xvel = -xvel;
            yvel = .75 * SPEED_BALL;
        }

    }
    if(collName == "screenwallr" || collName == "screenwalll"){ // those are fixed objects that determine the screen walls
        //TODO: give a point to the player
        xpos = xinit;
        ypos = yinit;
    }
    if(collName == "screenwallt" || collName == "screenwallb"){ // those are fixed objects that determine the screen walls
        yvel = -yvel;
    }
    c->setCollision("");
    xpos += xvel * dt;
    ypos += yvel * dt;
    drect.x = xpos;
    drect.y = ypos;
    GameObject::updateObject(dt);
    
}

void Ball::drawObject(){
    GameObject::drawObject();
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
