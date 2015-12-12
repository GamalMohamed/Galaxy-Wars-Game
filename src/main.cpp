#include"Defs.h"
#include"Game engine/GameManager.h"


// The MAIN function, from here we start our application and run our Game loop !
int main( void )
{
	GameManager *gameManager = &GameManager::getGameManager(); //1. Setting up game !
    gameManager->runGameLoop(); 							  //2. Game Begins !
    GameManager::destroyGameManager(); 						 //3. Game finishes !

    return 0;
}
















