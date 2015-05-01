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
    map.tileSetNumber = 0;
}

SDL_Texture *getBackground() {
    return map.background;
}

void cleanMaps() {
    if(map.background != NULL) {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
    
    if(map.tileSet != NULL) {
        SDL_DestroyTexture(map.tileSet);
        map.tileSet = NULL;
    }
}

void loadMap(char *name) {
    int x, y;
    FILE *fp;
    
    fp = fopen(name, "rb");
    
    if(fp == NULL) {
        printf("Impossible d'ouvrir la map %s\n", name);
        exit(1);
    }
    
    fscanf(fp, "%d", &map.tileSetAffiche);
    
    for(y = 0; y < SCREEN_HEIGHT; y++) {
        for(x = 0; x < SCREEN_WIDTH; x++ ) {
            fscanf(fp, "%d", &map.tile[y][x]);
        }
    }
    
    fclose(fp);
}

void drawMap() {
    int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;
    
    mapX = map.startX / TILE_SIZE;
    x1 = (map.startX % TILE_SIZE) * -1;
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
    
    mapY = map.startY / TILE_SIZE;
    y1 = (map.startY % TILE_SIZE) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
    
    for(y = y1; y < y2; y += TILE_SIZE) {
        mapX = map.startX / TILE_SIZE;
        for(x = x1; x < x2; x += TILE_SIZE) {
            a = map.tile[mapY][mapX];
                
            ysource = a / 28 * TILE_SIZE;
            xsource = a % 28 * TILE_SIZE;
            
            drawTile(map.tileSet, x, y, xsource, ysource);
            
            mapX++;
        }
        mapY++;
    }
    
}

void changeLevel() {
    char file[200];
    
    sprintf(file, "map/map%d.txt", getLevel());
    loadMap(file);
    
    if(map.tileSet != NULL)
        SDL_DestroyTexture(map.tileSet);
    
    sprintf(file, "graphics/tileset%d.png", map.tileSetAffiche);
    
    map.tileSet = loadImage(file);
}