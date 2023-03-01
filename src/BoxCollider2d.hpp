#ifndef BOX_COLLIDER2D_H
#define BOX_COLLIDER2D_H
#include <iostream>
struct collisionInfos {
    std::string collisionName;
    int x;
    int y;
};

class BoxCollider2D{
    public:
        //std::string cname;

        BoxCollider2D(std::string name);
        ~BoxCollider2D();

        void updateCollider(int bleft, int btop, int bright, int bbot);

        int getBoxLeft();
        int getBoxRigth();
        int getBoxTop();
        int getBoxBottom();

        void setCollision(std::string name);
        //std::tuple<bool, std::string> getCollision();
        collisionInfos getInfos();
        std::string getName();
        //void setBoxLeft(int value);
        //void setBoxRigth(int value);
        //void setBoxTop(int value);
        //void setBoxBottom(int value);

    private:
        std::string name;
        float boxLeft, boxRight, boxTop, boxBottom;
        struct collisionInfos infos;
        //bool collided;

};

#endif
