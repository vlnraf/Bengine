#ifndef PLAYER1_H
#define PLAYER1_H

#include "GameObject.hpp"

class Player1 : GameObject{
    
    public:
        using GameObject::GameObject;

        void update()override;
        void draw()override;
        void setDirection(int d);
    
    private:
    int vel = 20;
    int dir;

};

#endif