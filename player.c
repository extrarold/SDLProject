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
Input input_player1, input_player2;
double victoires = 0;

double getVictoires() {
    return victoires;
}

int getLevel() {
    return level;
}

void setValeurDuNiveau(int valeur) {
    level = valeur;
}

GameObject *getPlayer1() {
    return &player1;
}

GameObject *getPlayer2() {
    return &player2;
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


void cleanPlayer(SDL_Texture *name) {
    if(name != NULL) {
        SDL_DestroyTexture(name);
        name = NULL;
    }
}

void initializePlayer(GameObject *player, int x, int y, int direction, char *nameTexture) {
    
    player->life = 3;
    player->invincibleTimer = 0;
    player->direction = direction;
    player->etat = IDLE;
    
    player->frameNumber = 0;
    player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
    
    player->frameMax = 4;
    
    player->x = x;
    player->y = y;

    
    player->w = PLAYER_WIDTH;
    player->h = PLAYER_HEIGHT;
    
    player->timerMort = 0;
    player->onGround = 0;
    player->saveX = 0;
    
    player->spriteSheet = loadImage(nameTexture);
}



void drawPlayer(GameObject *player) {
    
    if(player->frameTimer <= 0) {
        player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
        
        player->frameNumber++;
        
        if(player->frameNumber >= player->frameMax)
            player->frameNumber = 0;
    } else
        player->frameTimer--;
    
    SDL_Rect dest;
    dest.x = player->x - getStartX();
    dest.y = player->y - getStartY();
    dest.w = player->w;
    dest.h = player->h;
    
    SDL_Rect src;
    src.x = player->frameNumber * player->w;
    src.w = player->w;
    src.h = player->h;
    src.y = player->etat * player->h;
    
    if (player->invincibleTimer > 0)
    {
        if (player->frameNumber % 2 == 0)
        {
            if (player->direction == LEFT)
                SDL_RenderCopyEx(getRenderer(), player->spriteSheet, &src, &dest, 0, 0, SDL_FLIP_HORIZONTAL);
            else
                SDL_RenderCopyEx(getRenderer(), player->spriteSheet, &src, &dest, 0, 0, SDL_FLIP_NONE);
        }
    } else {
        if(player->direction == LEFT)
            SDL_RenderCopyEx(getRenderer(), player->spriteSheet, &src, &dest, 0, 0, SDL_FLIP_HORIZONTAL);
        else
            SDL_RenderCopyEx(getRenderer(), player->spriteSheet, &src, &dest, 0, 0, SDL_FLIP_NONE);
    }
}

void updateInputs() {
    
    getInputs(&input_player2, &input_player1);
    
    updatePlayer(&player2, &input_player2);
    
    updatePlayer(&player1, &input_player1);
    
    fight(&player1, &player2, &input_player1, &input_player2);

}

void fight(GameObject *player1, GameObject *player2, Input *input1, Input *input2) {
    
    if(player1->life == 3)
        setHealth1(loadImage("graphics/coeur1.png"));
    if(player2->life == 3)
        setHealth2(loadImage("graphics/coeur1.png"));

        
    if((player1->x +player1->w < player2->x + player2->w && player1->x + player1->w >player2->x && input1->attack == 1)
       || (player1->x < player2->x + player2->w && player1->x > player2->x && input1->attack == 1)) {
        playKick();
        if (player2->invincibleTimer == 0)
        {
            if(player2->life == 3) {
                setHealth2(loadImage("graphics/coeur3.png"));
                player2->life--;
            }
            else if(player2->life == 2) {
                setHealth2(loadImage("graphics/coeur5.png"));
                player2->life--;
            } else {
                setHealth2(loadImage("graphics/coeur7.png"));
                player2->etat = DEATH;
                
                victoires++;
                mondeSuivant(victoires);
            }
            player2->invincibleTimer = 80;
        }
    }
    if((player2->x +player2->w < player1->x + player1->w && player2->x + player2->w >player1->x && input2->attack == 1)
       || (player2->x < player1->x + player1->w && player2->x > player1->x && input2->attack == 1)) {
        playKick();
        if (player1->invincibleTimer == 0)
        {
            if(player1->life == 3) {
                setHealth1(loadImage("graphics/coeur3.png"));
                player1->life--;
            }
            else if(player1->life == 2) {
                setHealth1(loadImage("graphics/coeur5.png"));
                player1->life--;
            } else {
                setHealth1(loadImage("graphics/coeur7.png"));
                player1->etat = DEATH;
                victoires--;
                mondeSuivant(victoires);
            }
            player1->invincibleTimer = 80;
        }

    }
}

void reinitializePlayers() {
    player1.x = getBeginPlayer1X();
    player2.x = getBeginPlayer2X();
    player1.y = getBeginPlayer1Y();
    player2.y = getBeginPlayer2Y();
    player1.life = 3;
    player2.life = 3;
    player1.direction = RIGHT;
    player2.direction = LEFT;
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
        
        if(input->attack == 1)
            if(player->saveX == 1)
                player->saveX = 0;
        
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
                    player->frameMax = 6;
                }
            }
        }
        if(player->saveX == 0) {
                
            if(input->attack == 1) {
                
                player->etat = ATK;
                player->frameNumber = 1;
                player->frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
                player->frameMax = 4;
            }

        }
        
        //On rajoute notre fonction de détection des collisions qui va mettre à
        //jour les coordonnées de notre super lapin.
        mapCollision(player);
        
    }
}