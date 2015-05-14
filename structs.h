#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "const.h"
 
 
typedef struct Input {
    int left, right, up, down, jump, attack, enter;
}Input;
 
typedef struct Map {
    SDL_Texture *background;
    SDL_Texture *tileSet;
    SDL_Texture *health1;
    SDL_Texture *health2;
    
    int tileSetAffiche;
    int begin_player1x, begin_player1y, begin_player2x, begin_player2y;
    int startX, startY;
    int maxX, maxY;
    int tile[MAX_MAP_Y][MAX_MAP_X];
    int tileSetNumber;
}Map;

typedef struct GameOBject {
    int life, invincibleTimer;
    int x, y;
    int h, w;
    int frameNumber, frameTimer, frameMax;
    int etat, direction;
    int onGround, timerMort;
    float dirX, dirY;
    int saveX, saveY;
    SDL_Texture *spriteSheet;
}GameObject;

#endif
