#ifndef PLAYER1_H
#define PLAYER1_H

#include "Core.hpp"

class Player : public GameObject{
    
    public:
        Player(SDL_Renderer* rend, std::string objectTag, std::string texture, int x, int y, int width, int height);

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
