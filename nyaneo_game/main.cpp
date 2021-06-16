// /*  Main.cpp
// *   The entry point of the program.
// */
// #include "game.h"
// #include "input.h"
// #ifdef __EMSCRIPTEN__
// #include <emscripten.h>
// #endif

// void main_loop(void *game)
// {
//     ((Game*)game)->start();

// }

// int main(int argc, const char* argv[])
// {
//     // Emscripten define game loop
//     Game *game;
//      #ifdef __EMSCRIPTEN__
//         emscripten_set_main_loop_arg(main_loop, game, 0, 1);
//         main_loop(game);
//     #endif
// 	//SDL_Quit();
//     return (0);
// }
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "snake.h"
#include "apple.h"
#include "graphics.h"

void handle_events(Snake* snake);
void quit(void);

// SDL_Window *window;
// SDL_Renderer *renderer;
SDL_Event e;

bool running = false;
bool frozen = false;

bool init(void)
{
    // bool success = true;
    // window = NULL;
    // renderer = NULL;

    // 1- intialize SDL 2- Initialize game objects.

    // if(SDL_Init(SDL_INIT_VIDEO) < 0){
    //     printf("SDL could not be initiliazed. SDL_Error: %s\n", SDL_GetError());
    //     success = false;
    // }

    // window = SDL_CreateWindow("GameJam Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // if(!window){
    //     printf("SDL_Window could not be initialized. SDL_Error: %s\n", SDL_GetError());
    //     success = false;
    // }
    // else{
    //     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);    
    // }

    // if(!init_snake()){
    //     printf("snake could not be initialized.\n");
    //     success = false;
    // }

    // generate_new_apple_pos();

    // running = true;
    // return success;
    return 0;
}

void main_loop(void)
{
    //Graphics may need to be initialized outside of the main loop.

    Graphics* graphics = new Graphics;
    Snake* snake = new Snake;
    Apple* apple = new Apple;
    // Check if graphics initialized ok. should return 0 if not okay.
    if (graphics->getStatus() == FAIL)
    {
        printf("Graphics returned a status %i exiting.\n", graphics->getStatus());
        return;
    }
    if (!snake->init_snake())
    {
        printf("Snake could not be initialied.\n");
        return;
    }
    apple->generate_new_apple_pos();
    running = true;
    // Start loop
    while (running)
    {
        handle_events(snake);

        if (frozen)
            return;

        SDL_SetRenderDrawColor(graphics->getRenderer(), 18, 1, 54, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(graphics->getRenderer());

        SDL_SetRenderDrawColor(graphics->getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);

        snake->update_snake(apple, graphics);
        apple->render_apple(graphics);

        SDL_RenderPresent(graphics->getRenderer());

        SDL_Delay(70);
    }
    free(&graphics);
    free(&snake);
    free(&apple);
    return;
}

int main(int argc, char* args[])
{
    while (running)
        main_loop();
    // quit_game();
    return 0;
}

void handle_events(Snake* snake)
{
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_RIGHT:
                snake->change_snake_direction(RIGHT);
                break;
            case SDLK_LEFT:
                snake->change_snake_direction(LEFT);
                break;
            case SDLK_UP:
                snake->change_snake_direction(UP);
                break;
            case SDLK_DOWN:
                snake->change_snake_direction(DOWN);
                break;
            }
        }
    }
}

void quit_game(void)
{
    // SDL_DestroyWindow(window);
    // window = NULL;

    // SDL_DestroyRenderer(renderer);
    // renderer = NULL;

    // // free_tails();
    // SDL_Quit();

    // #ifdef __EMSCRIPTEN__
    //     emscripten_cancel_main_loop();
    // #endif
}

void set_freeze(bool b)
{
    frozen = b;
}

// SDL_Renderer* getRenderer()
// { 
//     return renderer; 
// }