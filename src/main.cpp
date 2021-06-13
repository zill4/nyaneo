#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

#include "main.h"

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Renderer *renderer = NULL;
SDL_Event events;


void main_loop(void)
{
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 18, 1, 54, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderPresent(renderer);

    //Wait two seconds
    SDL_Delay (70);
}

int main(int arc, char* args[])
{
    bool running = false;

    //Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
            #ifdef __EMSCRIPTEN__
                emscripten_set_main_loop(main_loop, 0, 1);
            #endif
            
            #ifndef __EMSCRIPTEN__
                while(running)
                    main_loop(renderer);
            #endif
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
    return (0);
}