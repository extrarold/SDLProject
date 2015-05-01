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
    
    int tileSetAffiche;
    int beginx, beginy;
    int startX, startY;
    int maxX, maxY;
    int tile[SCREEN_HEIGHT][SCREEN_WIDTH];
    int tileSetNumber;
}Map;


#endif
