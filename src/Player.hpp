#ifndef PLAYER1_H
#define PLAYER1_H

#include "GameObject.hpp"

class Player : public GameObject{
    
    public:
        Player(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height);

        void update(float dt) override;
        void draw() override;
        //void addCollider(std::string name) override;
        void setVelocity(int xv, int yv);
    
    private:
        float xvel;
        float yvel;
};

#endif
