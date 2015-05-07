//
//  main.c
//  SDLTest
//
//  Created by Harold Heim on 29/03/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//


#include "prototypes.h"




int main(int argc, const char * argv[]) {
    
    unsigned int fpsLimit = SDL_GetTicks() + 16;
    
    int startGame;
    
    init("Projet C: AAZA HEIM HEN");
    
    loadGame();
    
    initializePlayer();
    
    atexit(clean);
    
    startGame = 1;
    
    while(startGame == 1) {

        update();
        
        drawGame();
        delay(fpsLimit);
        fpsLimit = SDL_GetTicks() + 16;
        
    }
    
    exit(0);
}
