#ifndef GRAPHICS_H
# define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics {
    public:
        Graphics();
        ~Graphics();
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};


#endif