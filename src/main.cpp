#include"Defs.h"
#include"gamewindow.h"


GameWindow* gamewindow;

// The MAIN function, from here we start our application and run our Game loop
int main( void )
{
    //Basic window setup
	 glfwInit();
	 glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2);
	 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
	 glfwOpenWindow(screenWidth, screenHeight, 8,8,8,8, 0,0, GLFW_WINDOW );
	 glfwEnable( GLFW_STICKY_KEYS );
	 glfwSetWindowTitle( "Galaxy Wars" );

	 glewInit();

    gamewindow=new GameWindow(true);
    //Game Starts !
    while(gamewindow->getRunning())
    {
        gamewindow->Render();
        gamewindow->Update();

        gamewindow->setRunning(glfwGetWindowParam( GLFW_OPENED ) && glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS);
    }

    delete gamewindow;
	glfwTerminate();

    return 0;
}
















