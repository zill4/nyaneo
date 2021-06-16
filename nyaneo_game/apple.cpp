#include "apple.h"

SDL_Rect apple;

// void generate_new_apple_pos(void);

void Apple::render_apple(Graphics* graphics)
{
    SDL_SetRenderDrawColor(graphics->getRenderer(), 226, 106, 106, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(graphics->getRenderer(), _apple); // used by &apple, may throw an error.
}

void Apple::generate_new_apple_pos(void)
{
    _apple->x = (rand() % (SCREEN_WIDTH - DEFAULT_APPLE_WIDTH + 1));
    _apple->y = (rand() % (SCREEN_HEIGHT - DEFAULT_APPLE_HEIGHT + 1));
    _apple->w = DEFAULT_APPLE_WIDTH;
    _apple->h = DEFAULT_APPLE_HEIGHT;
}

int Apple::get_apple_posX(void)
{
    return _apple->x;
}
int Apple::get_apple_posY(void)
{
    return _apple->y;
}