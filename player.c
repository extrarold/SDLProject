//
//  player.c
//  SDLTest
//
//  Created by Harold Heim on 01/05/2015.
//  Copyright (c) 2015 Harold Heim. All rights reserved.
//

#include "prototypes.h"

int level;
GameObject player1, player2;
SDL_Texture *playerSpriteSheet, *playerSpriteSheet2;
Input input_player1, input_player2;

int getLevel() {
    return level;
}

void setValeurDuNiveau(int valeur) {
    level = valeur;
}

GameObject *getPlayer() {
    return &player1;
}

int getPlayerx() {
    return player1.x;
}

int getPlayery() {
    return player1.y;
}

void setPlayerx(int valeur) {
    player1.x = valeur;
}

void setPlayery(int valeur) {
    player1.y = valeur;
}

void initPlayerSprites() {
    playerSpriteSheet = loadImage("graphics/leonardo.gif");
    playerSpriteSheet2 = loadImage("graphics/donatello.gif");;
}

void cleanPlayer() {
    if(playerSpriteSheet != NULL) {
        SDL_DestroyTexture(playerSpriteSheet);
        playerSpriteSheet = NULL;
    }
}

void initializePlayer() {
    
    player1.life = 3;
    player1.invincibleTimer = 0;
    player1.direction = RIGHT;
    player1.etat = IDLE;
    
    player1.frameNumber = 0;
    player1.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
    
    player1.frameMax = 4;
    
    player1.x = getBeginPlayer1X();
    player1.y = getBeginPlayer1Y();

    
    player1.w = PLAYER_WIDTH;
    player1.h = PLAYER_HEIGHT;
    
    player1.timerMort = 0;
    player1.onGround = 0;
    
    player2.life = 3;
    player2.invincibleTimer = 0;
    player2.direction = LEFT;
    player2.etat = IDLE;
    
    player2.frameNumber = 0;
    player2.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
    
    player2.frameMax = 4;
    
    player2.x = getBeginPlayer2X();
    player2.y = getBeginPlayer2Y();
    
    
    player2.w = PLAYER_WIDTH;
    player2.h = PLAYER_HEIGHT;
    
    player2.timerMort = 0;
    player2.onGround = 0;
}



void drawPlayer() {
    
    /*if(player1.frameTimer <= 0) {
        player1.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
        
        player1.frameNumber++;
        
        if(player1.frameNumber >= player1.frameMax)
            player1.frameNumber = 0;
    } else
        player1.frameTimer--;
    */
    SDL_Rect dest;
    dest.x = player1.x - getStartX();
    dest.y = player1.y - getStartY();
    dest.w = player1.w;
    dest.h = player1.h;
    
    SDL_Rect src;
    src.x = player1.frameNumber * player1.w;
    src.w = player1.w;
    src.h = player1.h;
    src.y = player1.etat * player1.h;
    
    if(player1.direction == LEFT)
        SDL_RenderCopyEx(getRenderer(), playerSpriteSheet, &src, &dest, 0, 0, SDL_FLIP_HORIZONTAL);
    else
        SDL_RenderCopyEx(getRenderer(), playerSpriteSheet, &src, &dest, 0, 0, SDL_FLIP_NONE);
    /*
    if(player2.frameTimer <= 0) {
        player2.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
        
        player2.frameNumber++;
        
        if(player2.frameNumber >= player2.frameMax)
            player2.frameNumber = 0;
    } else
        player2.frameTimer--;
    */
    SDL_Rect dest2;
    dest2.x = player2.x - getStartX();
    dest2.y = player2.y - getStartY();
    dest2.w = player2.w;
    dest2.h = player2.h;
    
    SDL_Rect src2;
    src2.x = player2.frameNumber * player2.w;
    src2.w = player2.w;
    src2.h = player2.h;
    src2.y = player2.etat * player2.h;
    
    if(player2.direction == LEFT)
        SDL_RenderCopyEx(getRenderer(), playerSpriteSheet2, &src2, &dest2, 0, 0, SDL_FLIP_HORIZONTAL);
    else
        SDL_RenderCopyEx(getRenderer(), playerSpriteSheet2, &src2, &dest2, 0, 0, SDL_FLIP_NONE);

}

void update() {
    
    getInputs(&input_player2, &input_player1);
    
    updatePlayer(&player2, &input_player2);
    
    updatePlayer(&player1, &input_player1);
    
    
}


void updatePlayer(GameObject *player, Input *input)
{
    //On rajoute un timer au cas où notre héros mourrait lamentablement en tombant dans un trou...
    //Si le timer vaut 0, c'est que tout va bien, sinon, on le décrémente jusqu'à 0, et là,
    //on réinitialise.
    //C'est pour ça qu'on ne gère le joueur que si ce timer vaut 0.
    if (player->timerMort == 0)
    {
        //On gère le timer de l'invincibilité
        if (player->invincibleTimer > 0)
            player->invincibleTimer--;
        
        //On réinitialise notre vecteur de déplacement latéral (X), pour éviter que le perso
        //ne fonce de plus en plus vite pour atteindre la vitesse de la lumière ! ;)
        //Essayez de le désactiver pour voir !
        player->dirX = 0;
        
        // La gravité fait toujours tomber le perso : on incrémente donc le vecteur Y
        player->dirY += GRAVITY_SPEED;
        
        //Mais on le limite pour ne pas que le joueur se mette à tomber trop vite quand même
        if (player->dirY >= MAX_FALL_SPEED)
            player->dirY = MAX_FALL_SPEED;
        
        
        //Voilà, au lieu de changer directement les coordonnées du joueur, on passe par un vecteur
        //qui sera utilisé par la fonction mapCollision(), qui regardera si on peut ou pas déplacer
        //le joueur selon ce vecteur et changera les coordonnées du player en fonction.
        if (input->left == 1)
        {
            player->dirX -= PLAYER_SPEED;
            //Et on indique qu'il va à gauche (pour le flip
            //de l'affichage, rappelez-vous).
            player->direction = LEFT;
            
            //Si ce n'était pas son état auparavant et qu'il est bien sur
            //le sol (car l'anim' sera différente s'il est en l'air)
            if (player->etat != WALK && player->onGround == 1)
            {
                //On enregistre l'anim' de la marche et on l'initialise à 0
                player->etat = WALK;
                player->frameNumber = 0;
                player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
                player->frameMax = 4;
            }
        }
        
        //Si on détecte un appui sur la touche fléchée droite
        else if (input->right == 1)
        {
            //On augmente les coordonnées en x du joueur
            player->dirX += PLAYER_SPEED;
            //Et on indique qu'il va à droite (pour le flip
            //de l'affichage, rappelez-vous).
            player->direction = RIGHT;
            
            //Si ce n'était pas son état auparavant et qu'il est bien sur
            //le sol (car l'anim' sera différente s'il est en l'air)
            if (player->etat != WALK && player->onGround == 1)
            {
                //On enregistre l'anim' de la marche et on l'initialise à 0
                player->etat = WALK;
                player->frameNumber = 0;
                player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
                player->frameMax = 4;
            }
        }
        
        //Si on n'appuie sur rien et qu'on est sur le sol, on charge l'animation marquant l'inactivité (Idle)
        else if (input->right == 0 && input->left == 0 && player->onGround == 1)
        {
            //On teste si le joueur n'était pas déjà inactif, pour ne pas recharger l'animation
            //à chaque tour de boucle
            if (player->etat != IDLE)
            {
                //On enregistre l'anim' de l'inactivité et on l'initialise à 0
                player->etat = IDLE;
                player->frameNumber = 0;
                player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
                player->frameMax = 4;
            }
            
        }
        
        
        //Et voici la fonction de saut très simple :
        //Si on appuie sur la touche saut et qu'on est sur le sol, alors on attribue une valeur
        //négative au vecteur Y
        //parce que sauter veut dire se rapprocher du haut de l'écran et donc de y=0.
        if (input->jump == 1)
        {
            if (player->onGround == 1)
            {
                player->dirY = -JUMP_HEIGHT;
                player->onGround = 0;
                
            }
        }
        
        //On gère l'anim du saut
        if (player->onGround == 0)
        {
            //Si on est en saut 1, on met l'anim' du saut normal
            if (input->jump == 1)
            {
                if (player->etat != JUMP)
                {
                    player->etat = JUMP;
                    player->frameNumber = 0;
                    player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
                    player->frameMax = 4;
                }
            }
        }
        
        //On rajoute notre fonction de détection des collisions qui va mettre à
        //jour les coordonnées de notre super lapin.
        mapCollision(player);
        
        
    }
    
    //Gestion de la mort quand le héros tombe dans un trou :
    //Si timerMort est différent de 0, c'est qu'il faut réinitialiser le joueur.
    //On ignore alors ce qui précède et on joue cette boucle (un wait en fait) jusqu'à ce que
    // timerMort == 1. A ce moment-là, on le décrémente encore -> il vaut 0 et on réinitialise
    //le jeu avec notre bonne vieille fonction d'initialisation ;) !
    if (player->timerMort > 0)
    {
        player->timerMort--;
        
        if (player->timerMort == 0)
        {
            // Si on est mort, on réinitialise le niveau
            changeLevel();
            initializePlayer();
        }
    }
}