#ifndef BALL_H
#define BALL_H

#include "GameObject.hpp"

class Ball : GameObject {

    public:
        //using GameObject::GameObject;
        Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height);

        void initDirection();
        void checkBorders();
        void update(float dt) override;
        void draw() override;
        void setDirectionX(int d);
        void setDirectionY(int d);

    private:
        int xvel;
        int yvel;
        int xdir;
        int ydir;

};

#endif