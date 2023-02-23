#ifndef PLAYER1_H
#define PLAYER1_H

#include "GameObject.hpp"

class Player1 : public GameObject{
    
    public:
        using GameObject::GameObject;

        void update(float dt) override;
        void draw() override;
        void addCollider(std::string name) override;
        void setVelocity(int v);
    
    private:
        float vel = 5;
};

#endif