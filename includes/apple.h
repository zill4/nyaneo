#ifndef APPLE
#define APPLE

#include "graphics.h"
static const int DEFAULT_APPLE_WIDTH = 20;
static const int DEFAULT_APPLE_HEIGHT = 20;

class Apple
{
    public:
        void render_apple(Graphics &graphics);
        void generate_new_apple_pos(void);
        int get_apple_posX(void);
        int get_apple_posY(void);
    private:
        SDL_Rect _apple;

};

#endif