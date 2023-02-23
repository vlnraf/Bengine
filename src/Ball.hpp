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
        void addCollider() override;
        //void setDirectionX(int d);
        //void setDirectionY(int d);

    private:
        float xvel;
        float yvel;

};

#endif