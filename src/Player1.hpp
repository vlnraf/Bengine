#ifndef PLAYER1_H
#define PLAYER1_H

#include "GameObject.hpp"

class Player1 : GameObject{
    
    public:
        using GameObject::GameObject;

        void update() override;
        void draw() override;
        void event(SDL_Event e);

};

#endif