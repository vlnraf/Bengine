#include "CollisionManager.hpp"

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager(){
}

CollisionManager::~CollisionManager(){
    //delete instance;
    //instance = nullptr;
}

CollisionManager* CollisionManager::Istance(){
    if(instance == nullptr){
        instance = new CollisionManager();
    }
    return instance;
}

void CollisionManager::destroy(){
    delete instance;
    instance = nullptr;
}

void CollisionManager::setScreen(int screenWidth, int screenHeight){
    screenW = screenWidth;
    screenH = screenHeight;
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
        a->setCollision(b->getName(), b->getBoxLeft(), b->getBoxRigth(), b->getBoxTop(), b->getBoxBottom());
        b->setCollision(a->getName(), a->getBoxLeft(), a->getBoxRigth(), a->getBoxTop(), a->getBoxBottom());
    }
}

void CollisionManager::checkWallCollision(BoxCollider2D *c){
    if(c->getBoxTop() < 0){
        c->setCollision("screenwallt");
    }
    if(c->getBoxBottom() > screenH){
        c->setCollision("screenwallb");
    }
    if(c->getBoxLeft() < 0){
        c->setCollision("screenwalll");
    }
    if(c->getBoxRigth() > screenW){
        c->setCollision("screenwallr");
    }
}
