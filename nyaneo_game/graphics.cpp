#include "graphics.h"

/* Graphics Class
 * Initialize SDL window, renderer, and Enscripten systems.
 */

Graphics::Graphics()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initiliazed. SDL_Error: %s\n", SDL_GetError());
        status = FAIL;
    }
    _window = SDL_CreateWindow("GameJam Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!_window)
    {
        printf("SDL_Window could not be initialized. SDL_Error: %s\n", SDL_GetError());
        status = FAIL;
    }
    else
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    status = SUCCESS;
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(_window);
    _window = NULL;

    SDL_DestroyRenderer(_renderer);
    _renderer = NULL;

    SDL_Quit();
}