#include "BoxCollider2d.hpp"
#include <tuple>

BoxCollider2D::BoxCollider2D(std::string name){
    this->name = name;
}

BoxCollider2D::~BoxCollider2D(){
}

void BoxCollider2D::updateCollider(int bleft, int btop, int bright, int bbot){
    boxLeft = bleft;
    boxRight = bright;
    boxTop = btop;
    boxBottom = bbot;
    infos.lhit = bleft;
    infos.rhit = bright;
    infos.thit = btop;
    infos.bhit = bbot;
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

collisionInfos BoxCollider2D::getInfos(){
    return infos;
}

void BoxCollider2D::setCollision(std::string n){
    infos.collisionName = n;
}

void BoxCollider2D::setCollision(std::string n, int leftHit, int rightHit, int topHit, int bottomHit){
    infos.lhit = leftHit;
    infos.rhit = rightHit;
    infos.thit = topHit;
    infos.bhit = bottomHit;
    infos.collisionName = n;
}
