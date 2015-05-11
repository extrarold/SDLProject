//
//  init.c
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

SDL_Window *screen;
SDL_Renderer *renderer;
TTF_Font *fjallaFont;

SDL_Renderer *getRenderer() {
    return renderer;
}

TTF_Font *getFjalla() {
    return fjallaFont;
}

void init(char *title) {

    // Création de la fenêtre
    screen = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Création du rendu avec synchro accélérée
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);



    // Curseur de la souris caché
    SDL_ShowCursor(SDL_DISABLE);

    // Initialisation des composantes SDL et affichage du message d'erreur
    if(screen == NULL || renderer == NULL) {
        printf("Impossible de créer une fenêtre %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image non iniatilisé : %s\n", IMG_GetError());
        exit(1);
    }

    if( TTF_Init() < 0) {
        printf("Impossible d'initialiser TTF: %s\n", TTF_GetError());
        exit(1);
    }

    fjallaFont = TTF_OpenFont("fonts/bitter.ttf", 100);

    if(fjallaFont == NULL) {
        printf("Impossible de créer un font: %s", TTF_GetError());
        exit(1);
    }

    int mp3Flags = MIX_INIT_MP3;
    int initted = Mix_Init(mp3Flags);/*
    if((initted & mp3Flags) != mp3Flags) {
        printf("Mix_init: Erreur d'initialisation de Mixer\n");
        printf("Erreur: %s\n", Mix_GetError());
        exit(1);
    }*/

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)  == -1) {
        printf("Mix_OpenAudio error : %s", Mix_GetError());
        exit(1);
    }

    Mix_AllocateChannels(32);
}

void clean() {
    // Fermeture des libs SDL et pointeurs à NULL

    cleanMaps();

    cleanPlayer(getPlayer1()->spriteSheet);
    cleanPlayer(getPlayer2()->spriteSheet);

    cleanMusic();

    TTF_CloseFont(fjallaFont);

    Mix_CloseAudio();
    Mix_Quit();

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    TTF_Quit();

    SDL_Quit();

}

void loadGame() {
    initMaps();
    setHealth1(loadImage("graphics/coeur1.png"));
    setHealth2(loadImage("graphics/coeur1.png"));
    loadMusic();
    playMusic();

    setValeurDuNiveau(1);
    changeLevel();
}

