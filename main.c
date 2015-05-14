#include "prototypes.h"
 
 
/* Déclaration des variables / structures utilisées par le jeu */
Input input1, input2;

int startMenu;
int startGame;
 
int main(int argc, char *argv[])
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
 
    // Initialisation de la SDL 
    init("Projet C: AAZA HEIM HEN");
	
	loadGame();
	
	initializePlayer(getPlayer1(), getBeginPlayer1X(), getBeginPlayer1Y(), RIGHT, "graphics/ryurouge.gif");
    initializePlayer(getPlayer2(), getBeginPlayer2X(), getBeginPlayer2Y(), LEFT, "graphics/ryubleu.gif");
	
    // Appelle la fonction cleanup à la fin du programme 
    atexit(cleanup);
 
    startMenu = 1;
    startGame = 0;

 
    // Boucle infinie, principale, du jeu 
    while (startMenu == 1)
    {
		updateInputs();
		if(!startGame)
            drawMenu();
        if(getInput()->enter == 1)
            startGame = 1;
        if(startGame)
            drawGame();
 
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16 
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
 
    // On quitte
    exit(0);
 
}
