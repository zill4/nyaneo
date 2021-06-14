/*  Game Class
*   Game loop and connected logic.
*
*/
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
    const int FPS = 60; //Was 50
    const int MAX_FRAME_RATE = 1000 / FPS;
}

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
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
    SDL_Event event;
    Input input;
    //Start the game loop
    while (true) 
    {
        input.beginNewFrame();
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.repeat == 0)
                {
                    input.keyDownEvent(event);
                    return ;
                }
            }

            if (event.type == SDL_QUIT) 
            {
                return;
            }
        }
        //this->_graphics = graphics;
        // SDL_Delay(70);
    }
}

void Game::draw(Graphics &graphics)
{

}

void Game::update(float elapsedtime) 
{

}