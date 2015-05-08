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
    
    initializePlayer(getPlayer1(), getBeginPlayer1X(), getBeginPlayer1Y(), RIGHT, "graphics/donatelloV10.gif");
    initializePlayer(getPlayer2(), getBeginPlayer2X(), getBeginPlayer2Y(), LEFT, "graphics/donatellobleu.gif");
    
    atexit(clean);
    
    startGame = 1;
    
    while(startGame == 1) {

        updateInputs();
        
        drawGame();
        
        delay(fpsLimit);
        
        fpsLimit = SDL_GetTicks() + 16;
        
    }
    
    exit(0);
}
