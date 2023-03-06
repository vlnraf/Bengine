#ifndef BOX_COLLIDER2D_H
#define BOX_COLLIDER2D_H
#include <iostream>
struct collisionInfos {
    std::string collisionName;
    int lhit;
    int rhit;
    int thit;
    int bhit;
};

class BoxCollider2D{
    public:

        BoxCollider2D(std::string name);
        ~BoxCollider2D();

        void updateCollider(int bleft, int btop, int bright, int bbot);

        int getBoxLeft();
        int getBoxRigth();
        int getBoxTop();
        int getBoxBottom();
        collisionInfos getInfos();
        std::string getName();

        void setCollision(std::string name);
        void setCollision(std::string n, int leftHit, int rightHit, int topHit, int bottomHit);

    private:
        std::string name;
        float boxLeft, boxRight, boxTop, boxBottom;
        struct collisionInfos infos;
};

#endif
