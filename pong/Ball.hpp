#ifndef BALL_H
#define BALL_H
#define SPEED_BALL 3.0f

#include "Core.hpp"

class Ball : public GameObject {

    public:
        Ball(int x, int y, int width, int height);

        void initDirection();
        void updateObject(float dt) override;
        void drawObject() override;

    private:
        float xvel;
        float yvel;
        int xinit, yinit;

};

#endif
