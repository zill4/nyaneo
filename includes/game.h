#ifndef GAME_H
# define GAME_H

#include "graphics.h"

class Game
{
    public:
        Game();
        ~Game();
        void start();
    private:
        Graphics _graphics;
        void gameLoop();
        void update(float elapsedtime);
        void draw(Graphics &graphics);
};

#endif