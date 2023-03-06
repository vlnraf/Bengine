#include <chrono>
#include "Core.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#define WIDTH 800
#define HEIGHT 600

class Application : public GameEngine{
    public:
        Application(std::string title, int x, int y, int w, int h, bool fullscreen):GameEngine(title, x, y, w, h, fullscreen){
            player = new Player(renderer, "player1", "assets/p1texture.png", 10, (HEIGHT /2) - 50, 10, 100);
            player2 = new Player(renderer, "player2", "assets/p2texture.png", (WIDTH-20)-10, HEIGHT/2 - 50, 10, 100);
            ball = new Ball(renderer, "assets/balltexture.png", WIDTH/2 - 5, HEIGHT/2 - 5, 10, 10);

            player->addCollider("player1");
            player2->addCollider("player2");
            ball->addCollider("ball");
        }
        ~Application(){}

        void update() override{
            GameEngine::update();
            player->updateObject(dt);
            player2->updateObject(dt);
            ball->updateObject(dt);
        }

        void draw() override{
            player->drawObject();
            player2->drawObject();
            ball->drawObject();
            GameEngine::display();
        }

    private:
        Player *player;
        Player *player2;
        Ball *ball;
};

int main (int argv, char *args[]){
    Application* pong = new Application("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
    pong->setBackground(0,0,0,0);
    pong->run();
    delete pong;
    return 0;
}
