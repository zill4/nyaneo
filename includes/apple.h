#ifndef APPLE
#define APPLE
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "main.h"
#include "graphics.h"
static const int DEFAULT_APPLE_WIDTH = 20;
static const int DEFAULT_APPLE_HEIGHT = 20;



class Apple 
{
    public:
    void render_apple(Graphics *);
    void generate_new_apple_pos(void);

    int get_apple_posX(void);
    int get_apple_posY(void);
    SDL_Rect *getApple(){return (_apple);}
    private:
        SDL_Rect *_apple;
};

#endif