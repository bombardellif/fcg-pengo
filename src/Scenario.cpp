#include "Scenario.h"

#include <cstdlib>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "bitmap.h"

using namespace std;

Scenario::Scenario(string _resourceFolder)
: backgrundColor({0.0f,0.0f,0.0f,1.0f}),
resourceFolder(_resourceFolder)
{
}

void Scenario::initTexture()
{
    
}

void Scenario::initMap()
{
    BITMAPINFO *info;
    short row, col;
    C3DObject *obj;
    Modelable *mappedModel;
    GLuint pixel;
    
    // Load the 8x8 Bitmap that describes the map
    GLubyte *bits = LoadDIBitmap((this->resourceFolder + SCENARIO_MAP_FILENAME).c_str(), &info);
    if (bits == (GLubyte *)NULL) {
		throw string("Error loading map file!");
	}
    
    // Create a RGBA image
    if (info->bmiHeader.biWidth != 8 || info->bmiHeader.biHeight != 8) {
        throw string("Error loading map file: Invalid image size!");
    }
    
    for(int i = info->bmiHeader.biWidth * info->bmiHeader.biHeight; i > 0 ; i--, bits += 3)
    {
        row = i / 8;
        col = i % 8;
        
        // interpret the RGB pixel (3 bytes) as an RGBA pixel (4 bytes)
        pixel = ((GLuint)*bits) & 0x00ffffff;
        
        // TODO: instanciate the models according to the bitmap
        switch (pixel) {
            case SCENARIO_MAP_COLOR_IMBLOCK:
                
                obj = new C3DObject();
                obj->Load((this->resourceFolder + SCENARIO_IMBLOCK_FILENAME).c_str());
                map[row][col] = obj;
                break;
            case SCENARIO_MAP_COLOR_BLOCK:
                
                obj = new C3DObject();
                obj->Load((this->resourceFolder + SCENARIO_BLOCK_FILENAME).c_str());
                map[row][col] = obj;
                break;
            default:
                map[row][col] = NULL;
        }
    }
}

void Scenario::initLight()
{
    glEnable(GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	GLfloat light_ambient[] = { backgrundColor[0], backgrundColor[1], backgrundColor[2], backgrundColor[3] };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position1[] = {0.0, 1.0, 0.0, 0.0 };

    // Light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
}

void Scenario::render()
{
    glClearColor(backgrundColor[0],backgrundColor[1],backgrundColor[2],backgrundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // limpar o depth buffer
    
    for(int i=0; i < SCENARIO_MAP_SIZE; i++) {
        for(int j=0; j < SCENARIO_MAP_SIZE; j++) {
            
            if (map[i][j])
                map[i][j]->Draw(SMOOTH_MATERIAL);
        }
    }
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

    this->initTexture();
    
    this->initMap();
    
    this->initLight();
}

void Scenario::updateWindow(int windowWidth, int windowHeight)
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)windowWidth/(GLfloat)windowHeight, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0,
        10.0,
        10.0,
        0.0,
        0.0,
        0.0,
		0.0,
        1.0,
        0.0);
}
