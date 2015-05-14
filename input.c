//
//  input.c
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"



void getInputs(Input *input1, Input *input2) {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
                
            case SDL_QUIT:
                exit(0);
                break;
                
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit(0);
                    break;
                    
                case SDLK_UP:
                    input1->jump = 1;
                    playJump();
                    break;
                    
                case SDLK_z:
                    input2->jump = 1;
					playJump();
                    break;
                    
                case SDLK_v:
                    input1->attack = 1;
                    break;
                    
                case SDLK_a:
                    input2->attack = 1;
                    break;
                    
                case SDLK_LEFT:
                    input1->left = 1;
                    break;
                    
                case SDLK_q:
                    input2->left = 1;
                    break;
                    
                case SDLK_RIGHT:
                    input1->right = 1;
                    break;
                
                case SDLK_d:
                    input2->right = 1;
                    break;
                    
                case SDLK_DOWN:
                    input1->down = 1;
                    
                    break;
                    
                    
                case SDLK_RETURN:
                    input2->enter = 1;
                    break;
                    
                case SDLK_t:
                    
                default:
                    break;
            }
                break;
                
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
            {                    
                case SDLK_UP:
                    input1->jump = 0;
                    break;
                
                case SDLK_z:
                    input2->jump = 0;
                    break;
                
                case SDLK_v:
                    input1->attack = 0;
                    break;
                    
                case SDLK_a:
                    input2->attack = 0;
                    break;
                    
                case SDLK_LEFT:
                    input1->left = 0;
                    break;
                    
                case SDLK_RIGHT:
                    input1->right = 0;
                    break;
                    
                case SDLK_q:
                    input2->left = 0;
                    break;
                    
                case SDLK_d:
                    input2->right = 0;
                    break;
                    
                case SDLK_DOWN:
                    input1->down = 0;
                    break;
                    
                case SDLK_RETURN:
                    input2->enter = 0;
                    break;
                    
                default:
                    break;
            }
                break;
                
        }
        
    }
}
