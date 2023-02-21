#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject{
    public:
        GameObject();
        ~GameObject();

        void initialize();
        void update();
        void draw();

    private:
    int xpos, ypos;
};
#endif