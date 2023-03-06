#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "GameEngine.hpp"
#include "GameObject.hpp"

class KeyboardManager {

    public:
        KeyboardManager();
        ~KeyboardManager();

        const uint8_t* getState() const;

    private:

};
#endif
