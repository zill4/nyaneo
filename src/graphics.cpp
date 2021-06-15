/*  Graphics Class
*   Handles SDL2 graphics related funcationality.
*
*/
#include <SDL2/SDL.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
if(SDL_Init(SDL_INIT_VIDEO) < 0)
{
        printf("SDL could not be initiliazed. SDL_Error: %s\n", SDL_GetError());
    }

    _window = SDL_CreateWindow("Nyaneo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(!_window){
        printf("SDL_Window could not be initialized. SDL_Error: %s\n", SDL_GetError());
    }
    else{
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);    
    }
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

