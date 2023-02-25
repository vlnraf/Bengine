#include "BoxCollider2d.hpp"
#include <tuple>

BoxCollider2D::BoxCollider2D(std::string name){
    this->name = name;
    //collided = false;
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
std::string BoxCollider2D::getName(){
    return name;
}

//std::tuple<bool, std::string> BoxCollider2D::getCollision(){
//    return std::make_tuple(collided, cname);
//}

collisionInfos BoxCollider2D::getInfos(){
    return infos;
}

void BoxCollider2D::setCollision(std::string n){
    //collided = value;
    infos.collisionName = n;
    //cname = n;
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