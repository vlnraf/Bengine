#include "CollisionManager.hpp"

CollisionManager::CollisionManager(int screenWidth, int screenHeight){
    screenW = screenWidth;
    screenH = screenHeight;
}

CollisionManager::~CollisionManager(){

}
void CollisionManager::pushCollider(BoxCollider2D *b){
    listColliders.push_back(b);
}

void CollisionManager::checkCollision(){
    for(unsigned int i = 0; i < listColliders.size(); i++){
        checkWallCollision(listColliders[i]);
        for(unsigned int j = i+1; j < listColliders.size(); j++){
            checkObjectCollision(listColliders[i],listColliders[j]);
        }
    }
}

void CollisionManager::checkObjectCollision(BoxCollider2D *a, BoxCollider2D *b){
    if(a->getBoxRigth() >= b->getBoxLeft() && a->getBoxTop() <= b->getBoxBottom() && a->getBoxBottom() >= b->getBoxTop() && a->getBoxLeft() <= b->getBoxRigth()){
        a->setCollision(true, b->getName());
        b->setCollision(true, a->getName());
    }
}

void CollisionManager::checkWallCollision(BoxCollider2D *c){
    if(c->getBoxTop() < 0){
        c->setCollision(true, "screenwall");
    }
    if(c->getBoxBottom() > screenH){
        c->setCollision(true, "screenwall");
    }
    if(c->getBoxLeft() < 0){
        c->setCollision(true, "screenwall");
    }
    if(c->getBoxRigth() > screenW){
        c->setCollision(true, "screenwall");
    }
}