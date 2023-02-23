#ifndef COLLISION_MANGER_H
#define COLLISION_MANGER_H

#include <vector>
#include "BoxCollider2d.hpp"

class CollisionManager{
    public:
        CollisionManager(int screenWidth, int screenHeight);
        ~CollisionManager();

        void pushCollider(BoxCollider2D *b);
        void checkWallCollision(BoxCollider2D *b);
        void checkObjectCollision(BoxCollider2D *a, BoxCollider2D *b);
        void checkCollision();

    private:
        int screenW, screenH;
        std::vector<BoxCollider2D*> listColliders;
};

#endif