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
void getInputs(Input *input1, Input *input2);
void initMaps();
SDL_Texture *getBackground();
void cleanMaps();
void loadGame();
SDL_Texture *loadImage(char *name);
void drawImage(SDL_Texture *image, int x, int y);
void loadMap(char *name);
void drawMap();
void changeLevel();
int getLevel();
void setValeurDuNiveau(int level);
void drawTile(SDL_Texture *image, int destx, int desty, int srcx, int srcy);
GameObject *getPlayer1();
GameObject *getPlayer2();
int getPlayerx();
int getPlayery();
void setPlayerx(int valeur);
void setPlayery(int valeur);
void initPlayerSprites();
void cleanPlayer();
void initializePlayer(GameObject *player, int x, int y, int direction, char *nameTexture);
void drawPlayer();
void drawPlayer2();
int getBeginPlayer1X();
int getBeginPlayer2X();
int getBeginPlayer1Y();
int getBeginPlayer2Y();
int getMaxY();
int getMaxX();
void setStartY(int valeur);
void setStartX(int valeur);
int getStartY();
int getStartX();
void updatePlayer(GameObject *player, Input *input);
void mapCollision(GameObject *entity);
void updateInputs();
void loadMusic();
void cleanMusic();
void playMusic();
TTF_Font *getFjalla();
SDL_Texture *drawMessage(char *texte);
SDL_Texture *getHealth1();
void setHealth1(SDL_Texture *message);
void reinitializePlayers();
void playJump();
void fight(GameObject *player1, GameObject *player2, Input *input1, Input *input2);
SDL_Texture *getHealth2();
void setHealth2(SDL_Texture *message);
void mondeSuivant(int level, char *name);

#endif
