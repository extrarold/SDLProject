//
//  prototypes.h
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#ifndef SDLTest_prototypes_h
#define SDLTest_prototypes_h

#include "structs.h"

SDL_Renderer *getRenderer();
void init(char *title);
void clean();
void drawGame();
void delay(unsigned int fpsLimit);
void gestionInputs(Input *input);
void getInput(Input *input);
void initMaps();
SDL_Texture *getBackground();
void cleanMaps();
void loadGame();
SDL_Texture *loadImage(char *name);
void drawImage(SDL_Texture *image, int x, int y);

#endif
