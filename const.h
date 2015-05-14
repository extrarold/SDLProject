#ifndef DEF_CONST
#define DEF_CONST
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
 
/* On inclut les libs supplémentaires */
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
 
// Taille de la fenêtre : 800x480 pixels 
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

#define MAX_MAP_X 40
#define MAX_MAP_Y 25

#define TILE_SIZE 32

#define PLAYER_SPEED 4

#define TIME_BETWEEN_2_FRAMES_PLAYER 4

#define IDLE 0
#define WALK 1
#define ATK 2
#define JUMP 3
#define DEATH 4

#define RIGHT 1
#define LEFT 2

#define PLAYER_WIDTH 76
#define PLAYER_HEIGHT 95

#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 15
#define JUMP_HEIGHT 8

#define BLANK_TILE 20
#define TILE_TRANSVERSABLE 20
 
#endif
