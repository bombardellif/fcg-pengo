/* 
 * File:   main.cpp
 * Author: fernando
 *
 * Created on 26. Juni 2014, 17:21
 */

#include <cstdlib>

# ifdef WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include <GL/glut.h>
#include "bitmap.h"
#include "3DObject.h"

#define APP_NAME "FCG - Pengo"
#define SLEEP_MS 30
#define SLEEP_uS SLEEP_MS * 1000

using namespace std;

/* Global Variables */
/**
 * Screen dimensions
*/
int windowWidth = 600;
int windowHeight = 480;
/**
 * Screen position
*/
int windowXPos = 100;
int windowYPos = 150;

int mainWindowId = 0;

/* END of Global Variables*/

/**
 *  Viewport functions
 */
void onWindowReshape(int x, int y) {
	windowWidth = x;
	windowHeight = y;
    
	// Scenario.getInstance().updateWindow();
    
    glViewport(0, 0, windowWidth, windowHeight);
}

/**
 * Key press event handler
*/
void onKeyDown(unsigned char key, int x, int y) {
    
	switch (key) {
		
		default:
			break;
	}
}

/**
 * Key release event handler
*/
void onKeyUp(unsigned char key, int x, int y) {
	switch (key) {
		default:
			break;
	}
}

/**
 * Render scene
*/
void mainRender() {
	// GameController.getInstance().update();
	// Scenario.getInstance().render();
	glFlush();
	glutPostRedisplay();
	#  ifdef WIN32
        Sleep(SLEEP_MS);
    #  else
        usleep(SLEEP_uS);
    #  endif
}

/**
Initialize
*/
void mainInit() {
    
    // Scenario.getInstance().updateWindow();
    glViewport(0, 0, windowWidth, windowHeight);
    
    // Scenario.getInstance().initialize();
}

/*
 * 
 */
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(windowWidth,windowHeight);
	glutInitWindowPosition(windowXPos,windowYPos);

	/**
	Store main window id so that glui can send it redisplay events
	*/
	mainWindowId = glutCreateWindow(APP_NAME);

	glutDisplayFunc(mainRender);

	glutReshapeFunc(onWindowReshape);

	/**
	Register keyboard events handlers
	*/
	glutKeyboardFunc(onKeyDown);
	glutKeyboardUpFunc(onKeyUp);

	mainInit();

	glutMainLoop();

    return 0;
}

