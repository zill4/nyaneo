/*  Main.cpp
*   The entry point of the program.
*/
#include "game.h"
#include "input.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void main_loop(void *game)
{
    ((Game*)game)->start();

}

int main(int argc, const char* argv[])
{
    // Emscripten define game loop
    Game *game;
     #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop_arg(main_loop, game, 0, 1);
        main_loop(game);
    #endif
	//SDL_Quit();
    return (0);
}