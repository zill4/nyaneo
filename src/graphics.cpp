/*  Graphics Class
*   Handles SDL2 graphics related funcationality.
*
*/
#include <SDL2/SDL.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "nyaneo");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

