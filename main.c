//
//  main.c
//  SDLTest
//
//  Created by Harold Heim on 29/03/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//


#include "prototypes.h"

int startMenu;
int startGame;

int main(int argc, const char * argv[]) {

    unsigned int fpsLimit = SDL_GetTicks() + 16;

   

    init("Projet C: AAZA HEIM HEN");

    loadGame();

    initializePlayer(getPlayer1(), getBeginPlayer1X(), getBeginPlayer1Y(), RIGHT, "graphics/ryurouge.gif");
    initializePlayer(getPlayer2(), getBeginPlayer2X(), getBeginPlayer2Y(), LEFT, "graphics/ryubleu.gif");

    atexit(clean);

    startMenu = 1;
    startGame = 0;

    while(startMenu == 1) {

        updateInputs();
        if(!startGame)
            drawMenu();
        
        if(getInput()->enter == 1)
            startGame = 1;

        if(startGame)
            drawGame();

        delay(fpsLimit);

        fpsLimit = SDL_GetTicks() + 16;

    }

    exit(0);
}

void setStartGame(int s) {
    startGame = s;
}