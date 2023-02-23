#ifndef BOX_COLLIDER2D_H
#define BOX_COLLIDER2D_H

class BoxCollider2D{
    public:
        BoxCollider2D();
        ~BoxCollider2D();

        void updateCollider(int bleft, int btop, int bright, int bbot);

        int getBoxLeft();
        int getBoxRigth();
        int getBoxTop();
        int getBoxBottom();

        void setCollision(int value);
        bool getCollision();
        //void setBoxLeft(int value);
        //void setBoxRigth(int value);
        //void setBoxTop(int value);
        //void setBoxBottom(int value);

    private:
        float boxLeft, boxRight, boxTop, boxBottom;
        bool collided;
};

#endif