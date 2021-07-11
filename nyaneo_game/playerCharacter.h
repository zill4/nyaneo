#ifndef PLAYERCHARACTER
#define PLAYERCHARACTER

#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"
#include "apple.h"
#include "graphics.h"
#include "LTexture.h"

enum direction { LEFT, RIGHT, UP, DOWN };

class PlayerCharacter {
public:
    PlayerCharacter();
    ~PlayerCharacter();
    bool init_playercharacter(void);
    void update_playercharacter(Apple*, Graphics*);
    void change_direction(int);
    void check_collision(Apple*);
    void sprite_renderer(SDL_Rect*, Graphics*);

private:
    LTexture gSpriteSheetTexture;
};


#endif