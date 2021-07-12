#include "graphics.h"

/* Graphics Class
 * Initialize SDL window, renderer, and Enscripten systems.
 */

Graphics::Graphics()
{
    status = SUCCESS;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("ERROR: SDL could not be initiliazed. SDL_Error: %s\n", SDL_GetError());
        status = FAIL;
    }
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        printf("Warning: Linear texture filtering not enabled!");
    }
    _window = SDL_CreateWindow("GameJam Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == NULL)
    {
        printf("ERROR: SDL_Window could not be initialized. SDL_Error: %s\n", SDL_GetError());
        status = FAIL;
    }
    else
    {
        // Create vsynced renderer for window
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == NULL)
        {
            printf("ERROR: Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            status = FAIL;
        }
        else
        {
            // Initialize renderer color
            SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("ERROR: SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                status = FAIL;
            }
        }
    }
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(_window);
    _window = NULL;

    SDL_DestroyRenderer(_renderer);
    _renderer = NULL;

    SDL_Quit();
}