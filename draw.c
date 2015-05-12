//
//  draw.c
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

void drawGame() {

    drawImage(getBackground(), 0, 0);

    drawMap();

    drawPlayer(getPlayer1());
    drawPlayer(getPlayer2());
    drawImage(getHealth1(), 2, 50);
    drawOppositeImage(getHealth2(), 1180, 50);
    drawImage(drawMessage("Player 1", 255, 0, 0), 2, 2);
    drawImage(drawMessage("Player 2", 0, 0, 255), 1075, 2);
    drawImage(getplayer1wins(), 450, 50);
    drawImage(getplayer2wins(), 450, 50);

    SDL_RenderPresent(getRenderer());
     
    SDL_RenderClear(getRenderer());
    
    SDL_Delay(1);

}

void drawMenu() {
    
    drawImage(drawMessage("PRESS   ENTER   TO    START", 255, 255, 255), 400, 500);
    drawImage(drawMessage("PLAYER 1", 255, 255, 255), 2, 200);
    drawImage(drawMessage("PLAYER 2", 255, 255, 255), 1050, 200);

    SDL_RenderPresent(getRenderer());
    
    SDL_RenderClear(getRenderer());
    
    SDL_Delay(1);
}

void delay(unsigned int fpsLimit) {
    unsigned int ticks = SDL_GetTicks();

    if(fpsLimit < ticks)
        return;

    if (fpsLimit > ticks + 16)
        SDL_Delay(16);
    else
        SDL_Delay(fpsLimit - ticks);
}

SDL_Texture *loadImage(char *name) {

    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;

    loadedImage = IMG_Load(name);

    if(loadedImage != NULL) {


        texture = SDL_CreateTextureFromSurface(getRenderer(), loadedImage);

        SDL_FreeSurface(loadedImage);
        loadedImage = NULL;

    } else
        printf("L'image n'a pas pu etre chargée ! Error : %s\n", SDL_GetError());

    return texture;
}


void drawImage(SDL_Texture *image, int x, int y) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getRenderer(), image, NULL, &dest);
    
}

void drawOppositeImage(SDL_Texture *image, int x, int y) {
    SDL_Rect dest;
    
    dest.x = x;
    dest.y = y;
    
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopyEx(getRenderer(), image, NULL, &dest, 0, 0, SDL_FLIP_HORIZONTAL);
    
}

void drawTile(SDL_Texture *image, int destx, int desty, int srcx, int srcy) {
    SDL_Rect dest;

    dest.x = destx;
    dest.y = desty;
    dest.w = TILE_SIZE;
    dest.h = TILE_SIZE;

    SDL_Rect src;

    src.x = srcx;
    src.y = srcy;
    src.w = TILE_SIZE;
    src.h = TILE_SIZE;

    SDL_RenderCopy(getRenderer(), image, &src, &dest);
}

SDL_Texture *drawMessage(char *texte, int rouge, int vert,int bleu) {

    SDL_Color color = {rouge , vert, bleu};

    SDL_Surface *surface = TTF_RenderText_Solid(getFjalla(), texte, color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(getRenderer(), surface);

    SDL_FreeSurface(surface);
    surface = NULL;
    return texture;
}
