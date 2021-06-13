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
    SDL_Init(SDL_INIT_EVERYTHING);
    gameLoop();
}
void Game::gameLoop() 
{
    Graphics graphics;
    SDL_Event event;

    //Start the game loop
    while (true) 
    {
        this->_graphics = graphics;
        SDL_Delay(70);
    }
}