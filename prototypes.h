 #include "structs.h"
 
#ifndef PROTOTYPES
#define PROTOTYPES
 
#include "structs.h"

void cleanup(void);
void delay(unsigned int frameLimit);
void drawGame(void);
void gestionInputs(Input *input);
void getInputs(Input *input1, Input *input2);
SDL_Renderer *getrenderer(void);
void init(char *);
void initMaps();
SDL_Texture *getBackground();
void cleanMaps();
void loadGame();
SDL_Texture *loadImage(char *name);
void drawImage(SDL_Texture *image, int x, int y);
void drawMap();
void loadMap(char *name);
void updateInputs();
void drawMenu();
SDL_Texture *drawMessage(char *texte, int rouge, int vert,int bleu);
TTF_Font getFjalla();
int writeTxt(char *message, signed int x, signed int y, int size, SDL_Color color);
Input *getInput();
void mapCollision(GameObject *entity);
SDL_Texture *getHealth1();
SDL_Texture *getHealth2();
void drawOppositeImage(SDL_Texture *image, int x, int y);
void initializePlayer(GameObject *player, int x, int y, int direction, char *nameTexture);
GameObject *getPlayer2();
GameObject *getPlayer1(); 
void drawPlayer(GameObject *player);
void updatePlayer(GameObject *player, Input *input);
void fight(GameObject *player1, GameObject *player2, Input *input1, Input *input2);
int getVictoires();
void mondeSuivant(double victoires);
void reinitializePlayers();
void setHealth1(SDL_Texture *message);
void setHealth2(SDL_Texture *message);
void playKick();
void playJump();
void playMusic();
void setGame(int game);
void setVictoires(int valeur);
 
#endif
