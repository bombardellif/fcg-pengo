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
#include "Scenario.h"
#include "GameController.h"

#define APP_NAME "FCG - Pengo"
#define SLEEP_MS 30
#define SLEEP_uS SLEEP_MS * 1000

using namespace std;

/* Global Variables */
/**
 * Screen dimensions
*/
static int windowWidth = 600;
static int windowHeight = 480;
/**
 * Screen position
*/
static int windowXPos = 100;
static int windowYPos = 150;

static int mainWindowId = 0;

/**
 * Global objects of game control
 */
Scenario scenario("res/");
GameController gameController;

/* END of Global Variables*/

/**
 *  Viewport functions
 */
void onWindowReshape(int x, int y) {
	windowWidth = x;
	windowHeight = y;
    
	scenario.updateWindow(windowWidth, windowWidth);
    
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
	scenario.render();
    
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
    
    scenario.updateWindow(windowWidth, windowWidth);
    glViewport(0, 0, windowWidth, windowHeight);
    
    scenario.init();
    
    //gameController.penguin = *(scenario.penguin);
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

