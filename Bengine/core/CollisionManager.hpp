#ifndef COLLISION_MANGER_H
#define COLLISION_MANGER_H

#include <vector>
#include "BoxCollider2d.hpp"

class CollisionManager{
    public:
        static CollisionManager* Istance();

        void destroy();
        void setScreen(int screenWidth, int screenHeight);
        void pushCollider(BoxCollider2D *b);
        void checkWallCollision(BoxCollider2D *b);
        void checkObjectCollision(BoxCollider2D *a, BoxCollider2D *b);
        void checkCollision();

    private:
        static CollisionManager* instance;

        CollisionManager();
        ~CollisionManager();

        int screenW, screenH;
        std::vector<BoxCollider2D*> listColliders;
};

#endif
