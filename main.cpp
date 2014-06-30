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

#include <iostream>

#define APP_NAME "FCG - Pengo"
#define SLEEP_MS 30
#define SLEEP_uS SLEEP_MS * 1000
#define GO_FORWARD_KEY 'w'
#define GO_FORWARD_KEY_U 'W'
#define GO_BACKWARDS_KEY 's'
#define GO_BACKWARDS_KEY_U 'S'
#define TURN_CLOCKWISE_KEY 'd'
#define TURN_CLOCKWISE_KEY_U 'D'
#define TURN_COUNTERCLOCKWISE_KEY 'a'
#define TURN_COUNTERCLOCKWISE_KEY_U 'A'
#define PUSH_KEY ' '
#define CREATE_BLOCK_KEY 'e'
#define CREATE_BLOCK_KEY_U 'E'
#define CHANGE_CAMERA_KEY 'v'
#define CHANGE_CAMERA_KEY_U 'V'


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
    
    glScissor(windowWidth - windowWidth*0.2,
            windowHeight - windowHeight*0.2,
            windowWidth*0.2,
            windowHeight*0.2);
    
    //glViewport(0, 0, windowWidth, windowHeight);
}

/**
 * Key press event handler
*/
void onKeyDown(unsigned char key, int x, int y) {
	switch (key) {
		case GO_FORWARD_KEY:case GO_FORWARD_KEY_U:
			gameController.goForwardPressed = true;
		break;
		case GO_BACKWARDS_KEY:case GO_BACKWARDS_KEY_U:
			gameController.goBackwardsPressed = true;
		break;
		case TURN_CLOCKWISE_KEY:case TURN_CLOCKWISE_KEY_U:
			gameController.turnClockwisePressed = true;
		break;
		case TURN_COUNTERCLOCKWISE_KEY:case TURN_COUNTERCLOCKWISE_KEY_U:
			gameController.turnCounterClockwisePressed = true;
		break;
		case PUSH_KEY:
			gameController.pushPressed = true;
		break;
		case CREATE_BLOCK_KEY:case CREATE_BLOCK_KEY_U:
			gameController.createnewBlockPressed = true;
		break;
		case CHANGE_CAMERA_KEY:case CHANGE_CAMERA_KEY_U:
			gameController.changeCameraPressed = true;
		break;
	}
}

/**
 * Key release event handler
*/
void onKeyUp(unsigned char key, int x, int y) {
	switch (key) {
		case GO_FORWARD_KEY:case GO_FORWARD_KEY_U:
			gameController.goForwardPressed = false;
		break;
		case GO_BACKWARDS_KEY:case GO_BACKWARDS_KEY_U:
			gameController.goBackwardsPressed = false;
		break;
		case TURN_CLOCKWISE_KEY:case TURN_CLOCKWISE_KEY_U:
			gameController.turnClockwisePressed = false;
		break;
		case TURN_COUNTERCLOCKWISE_KEY:case TURN_COUNTERCLOCKWISE_KEY_U:
			gameController.turnCounterClockwisePressed = false;
		break;
		case PUSH_KEY:
			gameController.pushPressed = false;
		break;
		case CREATE_BLOCK_KEY:case CREATE_BLOCK_KEY_U:
			gameController.createnewBlockPressed = false;
		break;
		case CHANGE_CAMERA_KEY:case CHANGE_CAMERA_KEY_U:
			gameController.changeCameraPressed = false;
		break;
	}	
}

/**
 * Render scene
*/
void mainRender() {
    gameController.update();
    
    glViewport(0, 0, windowWidth, windowHeight);
    glDisable(GL_SCISSOR_TEST);
    glDepthRange(0.1, 1.0);
	scenario.render();
    
    glViewport(windowWidth - windowWidth*0.2,
            windowHeight - windowHeight*0.2,
            windowWidth*0.2,
            windowHeight*0.2);
    glEnable(GL_SCISSOR_TEST);
    glDepthRange(0.0, 0.1);
    
    int currentCameraState = scenario.cameraState;
    scenario.cameraState = SCENARIO_CAMERA_OVER;
	scenario.render();
    scenario.cameraState = currentCameraState;
    
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
    
    //scenario.updateWindow(windowWidth, windowWidth);
    //glViewport(0, 0, windowWidth, windowHeight);
    
    scenario.init();
    gameController.init();
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

