#include "BoxCollider2d.hpp"

#include <iostream>

BoxCollider2D::BoxCollider2D(){
    //boxLeft = x;
    //boxRight = x + width;
    //boxTop = y;
    //boxBottom = y + height;
    boxLeft = 0;
    boxRight = 0;
    boxTop = 0;
    boxBottom = 0;
}
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