#ifndef BALL_H
#define BALL_H
#define SPEED_BALL 3.0f

#include "GameObject.hpp"

class Ball : public GameObject {

    public:
        //using GameObject::GameObject;
        Ball(SDL_Renderer *renderer, std::string texture, int x, int y, int width, int height);

        void initDirection();
        void update(float dt) override;
        void draw() override;
        //void addCollider(std::string name) override;
        //void setDirectionX(int d);
        //void setDirectionY(int d);

    private:
        float xvel;
        float yvel;

};

#endif
