#ifndef GRAPHICS_H
# define GRAPHICS_H
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720


#include <SDL.h>
#include <stdio.h>

enum graphicsStatus { FAIL, SUCCESS, OTHER }; // TODO: Need to define other status codes and describe.

class Graphics
{
public:
    Graphics();
    ~Graphics();
    SDL_Renderer* getRenderer() { return (_renderer); }
    graphicsStatus getStatus() { return (status); }
private:
    graphicsStatus status;
    SDL_Renderer* _renderer;
    SDL_Window* _window;
};

#endif