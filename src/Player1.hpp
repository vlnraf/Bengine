#ifndef PLAYER1_H
#define PLAYER1_H

#include "GameObject.hpp"

class Player1 : GameObject{
    
    public:
        using GameObject::GameObject;

        void update(float dt) override;
        void draw() override;
        void addCollider() override;
        void setVelocity(int v);
    
    private:
        int vel = 5;
};

#endif