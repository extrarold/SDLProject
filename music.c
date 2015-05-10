//
//  music.c
//  SDLTest
//
//  Created by Harold Heim on 08/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

Mix_Music *gMusic = NULL;
Mix_Chunk *gJump = NULL;



void loadMusic(char *name) {
    gMusic = Mix_LoadMUS("sounds/mhysa.mp3");
    
    if(gMusic == NULL) {
        printf("Erreur lors du chargement de la musique: %s\n", Mix_GetError());
        exit(1);
    }
    
    gJump = Mix_LoadWAV("sounds/jump.wav");
}

void cleanMusic() {
    if(gMusic != NULL) {
        Mix_FreeMusic(gMusic);
        gMusic = NULL;
    }
    if(gJump != NULL) {
        Mix_FreeChunk(gJump);
        gJump = NULL;
    }
}

void playMusic() {
    Mix_PlayMusic(gMusic, -1);
}

void playJump() {
    Mix_PlayChannel(-1, gJump, 0);
}