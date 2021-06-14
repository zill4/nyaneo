#ifndef GRAPHICS_H
# define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Graphics {
    public:
        Graphics();
        ~Graphics();

        /* SDL_Surface* loadImage
	 * Loads an image into the _spriteSheets map if it doesn't already exist.
	 * As a result, each image will only ever be loaded once
	 * Returns the image from the map regardless of whether or not it was just loaded
	 */
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	 * Draws a texture to a certain part of the screen
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	 * Renders everything to the screen
	 */
	void flip();

	/* void clear
	 * Clears the screen
	 */
	void clear();

	/* SDL_Renderer* getRenderer
	 * Returns the renderer
	 */
	SDL_Renderer* getRenderer() const;
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};


#endif