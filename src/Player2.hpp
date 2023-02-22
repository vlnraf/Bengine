#ifndef PLAYER2_H
#define PLAYER2_H

#include "GameObject.hpp"

class Player2 : GameObject{
    
    public:
        using GameObject::GameObject;

        void update(float dt) override;
        void draw() override;
        void setVelocity(int v);

    private:
        int vel = 5;
};

#endif