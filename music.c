//
//  music.c
//  SDLTest
//
//  Created by Harold Heim on 08/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

Mix_Music *gMusic = NULL;


void loadMusic(char *name) {
    gMusic = Mix_LoadMUS(name);
    
    if(gMusic == NULL) {
        printf("Erreur lors du chargement de la musique: %s\n", Mix_GetError());
        exit(1);
    }
}

void cleanMusic() {
    if(gMusic != NULL) {
        Mix_FreeMusic(gMusic);
        gMusic = NULL;
    }
}

void playMusic() {
    Mix_PlayMusic(gMusic, -1);
}