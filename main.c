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
    init("Projet C: Eggy");
	
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
		
		printf("%d", getVictoires());
		updateInputs();
		
        if(getInput()->enter == 1) {
			setGame(1);
		}
        if(!startGame)
            drawMenu();
            
        if(startGame)
            drawGame();
 
        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16 
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
 
    // On quitte
    exit(0);
 
}

void setGame(int game) {
	startGame = game;
}
