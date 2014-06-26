#include "Scenario.h"

#include <GL/gl.h>
#include <GL/glu.h>

Scenario::Scenario()
: backgrundColor({0.0f,0.0f,0.0f,1.0f})
{
}

void Scenario::render()
{
    glClearColor(backgrundColor[0],backgrundColor[1],backgrundColor[2],backgrundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // limpar o depth buffer

}

void Scenario::init()
{
    glClearColor(backgrundColor[0], backgrundColor[1], backgrundColor[2], backgrundColor[3]);
	glColor3f(0.0f,0.0f,0.0f);

	// habilita remocao de faces ocultas
	glFrontFace (GL_CCW);
	glEnable(GL_CULL_FACE);

	// habilita o z-buffer
	glEnable(GL_DEPTH_TEST);

    //initTexture();

	//initModel();

	//initLight();
}

void Scenario::updateWindow(int windowWidth, int windowHeight)
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)windowWidth/(GLfloat)windowHeight, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
		0.0,
        1.0,
        0.0);
}
