//
//  const.h
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#ifndef SDLTest_const_h
#define SDLTest_const_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* libs SDL */
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

/* taille de la fenêtre: 1360x768 pixels (peut changer)*/
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 736

/* taille de la map */
#define MAP_X 40
#define MAP_Y 23

#define MAX_MAP_X 400
#define MAX_MAP_Y 150

/* taille d'une tile  32 x 32 */
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
