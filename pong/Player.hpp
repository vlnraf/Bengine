#ifndef PLAYER1_H
#define PLAYER1_H

#include "Core.hpp"

class Player : public GameObject{
    
    public:
        Player(std::string objectTag, int x, int y, int width, int height); 
        ~Player();

        void updateObject(float dt) override;
        void drawObject() override;
        void setVelocity(int xv, int yv);
    
    private:
        KeyboardManager* keyboardManager;
        float xvel;
        float yvel;
        int xinit, yinit;
};

#endif
