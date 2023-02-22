#ifndef PLAYER2_H
#define PLAYER2_H

#include "GameObject.hpp"

class Player2 : GameObject{
    
    public:
        using GameObject::GameObject;

        void update() override;
        void draw() override;
        void setDirection(int d);

    private:
    int vel = 20;
    int dir;
};

#endif