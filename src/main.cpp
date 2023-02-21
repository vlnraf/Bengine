#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

void setRect(SDL_Rect &rect, int x, int y, int w, int h){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

int main(int argc, char *argv[]){
    // SDL_Init(SDL_INIT_EVERYTHING); // To initialize everything (video, keyboard, joystick, audio, ...)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER); 

    //Window for video
    SDL_Surface *windowSurface = nullptr;
    //Images to show on the windows
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *image3 = nullptr;
    SDL_Surface *currentImage = nullptr;
    // rectangle to reposition the images
    SDL_Rect dstrect;
    // event
    SDL_Event ev;
    //joystick
    //SDL_Joystick *joystick = SDL_JoystickOpen(0);
    SDL_GameController *controller;

    bool isRunning = true;

    for(int i = 0; i < SDL_NumJoysticks(); i++){
        if(SDL_IsGameController(i)){
            controller = SDL_GameControllerOpen(i);
            std::cout << SDL_GameControllerMapping(controller) << std::endl;
            break;
        }
    }

    SDL_Window *window = SDL_CreateWindow("SDL Tests", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    windowSurface = SDL_GetWindowSurface(window);
    image1 = SDL_LoadBMP("bmp/image1.bmp");
    image2 = SDL_LoadBMP("bmp/lena.bmp");
    image3 = SDL_LoadBMP("bmp/blackbuck.bmp");

    if(!image1 && !image2 && !image3){
        std::cout << "Could not load the images" << SDL_GetError() << std::endl;
        return 1;
    }

    currentImage = image1;

    if (!window){
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;

        return 1;
    }

    while(isRunning){
        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                isRunning = false;
            }else if(ev.type == SDL_CONTROLLERBUTTONDOWN){
                if(ev.cbutton.button == SDL_CONTROLLER_BUTTON_X) {
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image1; 
                    setRect(dstrect, (WIDTH-640)/2, (HEIGHT-426)/2, 0, 0);
                    }
                if(ev.cbutton.button == SDL_CONTROLLER_BUTTON_A) {
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image2; 
                    setRect(dstrect, (WIDTH-512)/2, (HEIGHT-512)/2, 0, 0);
                    }
                if(ev.cbutton.button == SDL_CONTROLLER_BUTTON_B) {
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image3; 
                    setRect(dstrect, (WIDTH-512)/2, (HEIGHT-512)/2, 0, 0);
                    }
            }else if(ev.type == SDL_KEYDOWN){ // keyboard event type
                switch (ev.key.keysym.sym)
                {
                case SDLK_1:
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image1; 
                    setRect(dstrect, (WIDTH-640)/2, (HEIGHT-426)/2, 0, 0);
                    break;

                case SDLK_2:
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image2; 
                    setRect(dstrect, (WIDTH-512)/2, (HEIGHT-512)/2, 0, 0);
                    break;
                    
                case SDLK_3:
                    SDL_FillRect(windowSurface, NULL, 0x0000);
                    currentImage = image3; 
                    setRect(dstrect, (WIDTH-512)/2, (HEIGHT-512)/2, 0, 0);
                    break;
                
                default:
                    break;
                }

            }

            SDL_BlitSurface(currentImage, NULL, windowSurface, &dstrect);
            SDL_UpdateWindowSurface(window);
        }

    }

    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_FreeSurface(windowSurface);
    windowSurface = nullptr;
    SDL_DestroyWindow(window);

    if(!controller){SDL_GameControllerClose(controller);}

    currentImage = image1 = image2 =image3 = nullptr;
    controller = nullptr;
    window = nullptr;
    SDL_Quit();

    return 0;
}