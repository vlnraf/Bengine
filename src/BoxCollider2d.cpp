#include "BoxCollider2d.hpp"

BoxCollider2D::BoxCollider2D(){
    collided = false;
}

BoxCollider2D::~BoxCollider2D(){}

void BoxCollider2D::updateCollider(int bleft, int btop, int bright, int bbot){
    boxLeft = bleft;
    boxRight = bright;
    boxTop = btop;
    boxBottom = bbot;
}

int BoxCollider2D::getBoxLeft(){
    return boxLeft;
}
int BoxCollider2D::getBoxRigth(){
    return boxRight;
}
int BoxCollider2D::getBoxTop(){
    return boxTop;
}
int BoxCollider2D::getBoxBottom(){
    return boxBottom;
}
bool BoxCollider2D::getCollision(){
    return collided;
}

void BoxCollider2D::setCollision(int value){
    collided = value;
}

//void BoxCollider2D::setBoxLeft(int value){
//    boxLeft = value;
//}
//void BoxCollider2D::setBoxRigth(int value){
//    boxRight = value;
//}
//void BoxCollider2D::setBoxTop(int value){
//    boxTop = value;
//}
//void BoxCollider2D::setBoxBottom(int value){
//    boxBottom = value;
//}