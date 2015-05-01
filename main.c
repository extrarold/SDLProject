//
//  main.c
//  SDLTest
//
//  Created by Harold Heim on 29/03/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

<<<<<<< HEAD
#include "prototypes.h"

Input input;

int main(int argc, const char * argv[]) {
    
    unsigned int fpsLimit = SDL_GetTicks() + 16;
    
    int startGame;
    
    init("Projet C: AAZA HEIM HEN");
    
    loadGame();
    
    atexit(clean);
    
    startGame = 1;
    
    while(startGame == 1) {
        
        gestionInputs(&input);
        drawGame();
        delay(fpsLimit);
        fpsLimit = SDL_GetTicks() + 16;
    }
    
    exit(0);
=======
#include <stdio.h>
#include <SDL2_/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

int main(int argc, const char * argv[]) {

    SDL_Window *window;                    // Declare a pointer
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
                              "Eggnogg 2.0",                  // window title
                              SDL_WINDOWPOS_UNDEFINED,           // initial x position
                              SDL_WINDOWPOS_UNDEFINED,           // initial y position
                              640,                               // width, in pixels
                              480,                               // height, in pixels
                              SDL_WINDOW_OPENGL                  // flags - see below
                              );

    // Check that the window was successfully made
    if (window == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Boucle principal, s'arrete quand clique sur la croix
    int terminer = 0;
    SDL_Event evenements;

    while(terminer == 0) {
        SDL_WaitEvent(&evenements);
        SDL_ShowCursor(SDL_DISABLE);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

        SDL_SetRenderDrawColor(renderer, 17, 206, 112, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);


        if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
            terminer = 1;
    }
    // The window is open: enter program loop (see SDL_PollEvent)

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
>>>>>>> b792b7254d52ba1974c00d34ddd14a7a183ed57f
}
