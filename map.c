//
//  map.c
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

Map map;

void initMaps() {
    map.background = loadImage("graphics/background.png");
}

SDL_Texture *getBackground() {
    return map.background;
}

void cleanMaps() {
    if(map.background != NULL) {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
}