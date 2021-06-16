#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "snake.h"
#include "apple.h"
#include "graphics.h"

void handle_events(Snake* snake);


SDL_Event e;


void main_loop(void)
{
    int running = false;
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
    // Start loop
    running = true;
    while (running)
    {
        handle_events(snake);

        SDL_SetRenderDrawColor(graphics->getRenderer(), 18, 1, 54, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(graphics->getRenderer());

        SDL_SetRenderDrawColor(graphics->getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);

        snake->update_snake(apple, graphics);
        apple->render_apple(graphics);

        SDL_RenderPresent(graphics->getRenderer());

        SDL_Delay(70);
    }
    return;
}

int main(int argc, char* args[])
{
 
    main_loop();
    return 0;
}

void handle_events(Snake* snake)
{
    while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) 
            {
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