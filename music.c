#include "prototypes.h"

Mix_Music *gMusic = NULL;
Mix_Chunk *gJump = NULL;
Mix_Chunk *gKick = NULL;



void loadMusic() {
    gMusic = Mix_LoadMUS("sounds/seashore.mp3");
    
    if(gMusic == NULL) {
        printf("Erreur lors du chargement de la musique: %s\n", Mix_GetError());
        exit(1);
    }
    
    gJump = Mix_LoadWAV("sounds/jump.wav");
    
    if(gJump == NULL) {
        printf("Erreur lors du chargement du jump sound: %s\n", Mix_GetError());
        exit(1);
    }
    gKick = Mix_LoadWAV("sounds/kick.wav");
    
    if(gKick == NULL) {
        printf("Erreur lors du chargement du kick sound: %s\n", Mix_GetError());
        exit(1);
    }
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
    if(gKick != NULL) {
        Mix_FreeChunk(gKick);
        gKick = NULL;
    }
}

void playMusic() {
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    Mix_PlayMusic(gMusic, -1);
}

void playJump() {
    Mix_VolumeChunk(gJump, MIX_MAX_VOLUME/4);
    Mix_PlayChannel(-1, gJump, 0);
}

void playKick() {
    Mix_VolumeChunk(gKick, MIX_MAX_VOLUME/4);
    Mix_PlayChannel(-1, gKick, 0);
}
