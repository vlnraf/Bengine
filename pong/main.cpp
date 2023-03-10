#include <chrono>
#include "Core.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#define WIDTH 800
#define HEIGHT 600

class Application : public GameEngine{
    public:
        Application(std::string title, int x, int y, int w, int h, bool fullscreen):GameEngine(title, x, y, w, h, fullscreen){
            player = new Player("player1", 10, (HEIGHT /2) - 50, 10, 100);
            player->addSprite("assets/p1texture.png");
            player->addCollider("player1");

            player2 = new Player("player2", (WIDTH-20)-10, HEIGHT/2 - 50, 10, 100);
            player2->addSprite("assets/p2texture.png");
            player2->addCollider("player2");

            ball = new Ball(WIDTH/2 - 5, HEIGHT/2 - 5, 10, 10);
            ball->addSprite("assets/balltexture.png");
            ball->addCollider("ball");

            net = new GameObject((WIDTH/2) -5 , 0, 10, HEIGHT);
            net->addRectSprite(0, 100, 100, 0);
        }

        ~Application(){
            delete player;
            delete player2;
            delete ball;
            delete net;
        }

        void update() override{
            GameEngine::update();
            player->updateObject(dt);
            player2->updateObject(dt);
            ball->updateObject(dt);
        }

        void draw() override{
            net->drawObject();
            player->drawObject();
            player2->drawObject();
            ball->drawObject();
            GameEngine::draw();
        }

    private:
        Player *player;
        Player *player2;
        GameObject *net;
        Ball *ball;
};

int main (int argv, char *args[]){
    Application* pong = new Application("prova", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
    pong->setBackground(0,0,0,0);
    pong->run();
    delete pong;
    return 0;
}
