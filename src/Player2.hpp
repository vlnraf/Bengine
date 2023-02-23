#ifndef PLAYER2_H
#define PLAYER2_H

#include "GameObject.hpp"

class Player2 : public GameObject{
    
    public:
        using GameObject::GameObject;

        void update(float dt) override;
        void draw() override;
        void addCollider() override;
        void setVelocity(int v);

    private:
        float vel = 5;
};

#endif