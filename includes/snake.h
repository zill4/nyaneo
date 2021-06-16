#ifndef SNAKE
#define SNAKE
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"
#include "apple.h"
#include "graphics.h"
static const int DEFAULT_X = 500;
static const int DEFAULT_Y = 10;
static const int DEFAULT_WIDTH = 20;
static const int DEFAULT_HEIGHT = 20;

static const int DEFAULT_TAILS_N = 3;

struct TailNode{
    SDL_Rect rect;
    struct TailNode *next;
    struct TailNode *previous;
} typedef TailNode;

struct SnakeHead{
    int dx;
    int dy;
    int size;
    struct TailNode head;
} typedef SnakeHead;

enum direction{LEFT, RIGHT, UP, DOWN};

class Snake {
    public:

        bool init_snake(void);
        void update_snake(Apple *, Graphics *);
        void change_snake_direction(int);
        void free_tails(void);
        void check_collision(Apple *);
        void render_tail(SDL_Rect *, Graphics *);
        void push_tail();
        SnakeHead *getSnakeHead() {return snakeHead;}
        TailNode *getLastTail() {return lastTail;}
    private:
        SnakeHead *snakeHead;
        TailNode *lastTail;
};


#endif