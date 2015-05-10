//
//  structs.h
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#ifndef SDLTest_structs_h
#define SDLTest_structs_h

#include "const.h"

typedef struct Input {
    int left, right, up, down, jump, attack, enter;
}Input;

typedef struct Map {
    SDL_Texture *background;
    SDL_Texture *tileSet;
    SDL_Texture *message;
    
    int tileSetAffiche;
    int begin_player1x, begin_player1y, begin_player2x, begin_player2y;
    int startX, startY;
    int maxX, maxY;
    int tile[MAP_Y][MAP_X];
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
