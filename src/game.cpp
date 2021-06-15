/*  Game Class
*   Game loop and connected logic.
*
*/
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "snake.h"
#include "apple.h"

namespace {
    const int FPS = 60; //Was 50
    const int MAX_FRAME_RATE = 1000 / FPS;
}

Game::Game()
{
    // SDL_Init(SDL_INIT_EVERYTHING);
}

Game::~Game()
{

}

// TODO: Maybe add variables to start depending on mode.
void Game::start()
{
    
    gameLoop();
    // Assuming that the game loop has ended.
    SDL_Quit();
    #ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop();
    #endif
}

void Game::gameLoop() 
{
    Graphics graphics;
    SDL_Event e;
    Input input;
    int i = 0;
    // 

    while (true) 
    {
        input.beginNewFrame();
        while(SDL_PollEvent(&e) != 0){
                if(e.type == SDL_QUIT){
                    return ;
                }
                else if(e.type == SDL_KEYDOWN){
                    switch(e.key.keysym.sym){
                        case SDLK_RIGHT:
                            change_snake_direction(RIGHT);
                            break;
                        case SDLK_LEFT:
                            change_snake_direction(LEFT);
                            break;
                        case SDLK_UP:
                            change_snake_direction(UP);
                            break;
                        case SDLK_DOWN:
                            change_snake_direction(DOWN);
                            break;
                    }
                }
            }
        SDL_SetRenderDrawColor(graphics.getRenderer(), 18, 1, 54, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(graphics.getRenderer());

        SDL_SetRenderDrawColor(graphics.getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
        //Start the game loop
        
        update_snake(graphics);
        render_apple(graphics);
        SDL_RenderPresent(graphics.getRenderer());

        SDL_Delay(70);
        // if (SDL_PollEvent(&event))
        // {
        //     if (event.type == SDL_KEYDOWN)
        //     {
        //         return ;
        //         if (event.key.repeat == 0)
        //         {
        //             input.keyDownEvent(event);
        //             return ;
        //         }
        //     }

        //     if (event.type == SDL_QUIT) 
        //     {
        //         return;
        //     }
        // }
        //this->_graphics = graphics;
        printf("Running %i", i);
        i++;
        SDL_Delay(70);
    }
}

void Game::draw(Graphics &graphics)
{

}

void Game::update(float elapsedtime) 
{

}