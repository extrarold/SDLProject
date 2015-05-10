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
    
    drawImage(getHealth1(), 2, 2);
    drawImage(getHealth2(), 600, 2);

    SDL_RenderPresent(getRenderer());
    
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

SDL_Texture *drawMessage(char *texte) {
    
    SDL_Color color = {152 , 56, 153};
    
    SDL_Surface *surface = TTF_RenderText_Solid(getFjalla(), texte, color);
    
    SDL_Texture *texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    
    SDL_FreeSurface(surface);
    surface = NULL;
    return texture;
}