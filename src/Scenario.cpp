#include "Scenario.h"

#include <cstdlib>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <utility>
#include <cassert>
#include "bitmap.h"
#include "Block.h"
#include "Enemy.h"

Scenario::Scenario(std::string _resourceFolder)
: backgrundColor({0.0f,0.0f,0.0f,1.0f}),
resourceFolder(_resourceFolder),
floorTexture(NULL),
floorTextureInfo(NULL),
floorTextureId(0),
penguin(NULL)
{
}

Scenario::~Scenario()
{
    if (this->floorTexture)
        free(this->floorTexture);
    if (this->floorTextureInfo)
        free(this->floorTextureInfo);
    
    for(int i=0; i < SCENARIO_MAP_SIZE; i++) {
        for(int j=0; j < SCENARIO_MAP_SIZE; j++) {
            
            if (map[i][j]){
				delete map[i][j];
			}
        }
    }
}

void Scenario::initTexture()
{   
    // Load the floor texture
    this->floorTexture = LoadDIBitmap((this->resourceFolder + SCENARIO_TEXTURE_FLOOR_FILENAME).c_str(), &this->floorTextureInfo);
    if (this->floorTexture == NULL) {
        throw std::string("Error loading map file!");
	}
    
    // Create a texture object
    glGenTextures(1, &floorTextureId);
}

void Scenario::initMap()
{
    GLubyte *bits;
    BITMAPINFO *info = NULL;
    short row, col;
    int bitIndex, i, size;
    C3DObject *obj;
    GLuint pixel;
    
    // Load the Bitmap that describes the map
    bits = LoadDIBitmap((this->resourceFolder + SCENARIO_MAP_FILENAME).c_str(), &info);
    if (bits == NULL) {
		throw std::string("Error loading map file!");
	}
    
    // Create a RGBA image
    if (info->bmiHeader.biWidth != SCENARIO_MAP_SIZE || info->bmiHeader.biHeight != SCENARIO_MAP_SIZE) {
        throw std::string("Error loading map file: Invalid image size!");
    }
    
    for(bitIndex = i = 0, size=SCENARIO_MAP_SIZE*SCENARIO_MAP_SIZE; i < size ; i++, bitIndex += 3)
    {
        row = i / SCENARIO_MAP_SIZE;
        col = i % SCENARIO_MAP_SIZE;
        
        // interpret the RGB pixel (3 bytes) as an RGBA pixel (4 bytes)
        pixel = *((GLuint*)(bits+bitIndex)) & 0x00ffffff;
        
        switch (pixel) {
            case SCENARIO_MAP_COLOR_IMBLOCK:
                
                obj = new C3DObject();
                obj->Load((this->resourceFolder + SCENARIO_IMBLOCK_FILENAME).c_str());
                
                map[row][col] = new Block(obj, std::pair<double,double>((double)col, (double)row), NULL, false);
                break;
            case SCENARIO_MAP_COLOR_BLOCK:
				
                obj = new C3DObject();
                obj->Load((this->resourceFolder + SCENARIO_BLOCK_FILENAME).c_str());
                
                map[row][col] = new Block(obj, std::pair<double,double>((double)col, (double)row), NULL, true);
                break;
            default:
                map[row][col] = NULL;
        }
    }
    
    // finally
    free(bits);
    if (info)
        free(info);
}

void Scenario::initLight()
{
    glEnable(GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	GLfloat light_ambient[] = { backgrundColor[0], backgrundColor[1], backgrundColor[2], backgrundColor[3] };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position1[] = {SCENARIO_MAP_SIZE/2.0, 4.0, SCENARIO_MAP_SIZE/2.0, 0.0};

    // Light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
}

void Scenario::renderFloor()
{
    // Set the floor texture as current
	glBindTexture(GL_TEXTURE_2D, this->floorTextureId);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, this->floorTextureInfo->bmiHeader.biWidth,
        this->floorTextureInfo->bmiHeader.biHeight, 0, GL_RGB,
        GL_UNSIGNED_BYTE, this->floorTexture);
    
    glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Render the squares of the floor
	glPushMatrix();

    float planeSize = (float)SCENARIO_MAP_SIZE;
    //glTranslatef(-(float)planeSize/2.0f, 0.0f, -(float)planeSize/2.0f);

    glColor4f(1.0f,1.0f,1.0f,1.0f);
    int xQuads = SCENARIO_MAP_SIZE * SCENARIO_MAP_SIZE;
//    for (int i = 0; i < xQuads; i++) {
//        for (int j = 0; j < xQuads; j++) {
            glBegin(GL_QUADS);
                glTexCoord2f(1.0f, 0.0f);   // coords for the texture
                glNormal3f(0.0f,1.0f,0.0f);
                glVertex3f(planeSize, 0.0f, 0.0f);

                glTexCoord2f(0.0f, 0.0f);  // coords for the texture
                glNormal3f(0.0f,1.0f,0.0f);
                glVertex3f(0.0f, 0.0f, 0.0f);

                glTexCoord2f(0.0f, 1.0f);  // coords for the texture
                glNormal3f(0.0f,1.0f,0.0f);
                glVertex3f(0.0f, 0.0f, planeSize);

                glTexCoord2f(1.0f, 1.0f);  // coords for the texture
                glNormal3f(0.0f,1.0f,0.0f);
                glVertex3f(planeSize, 0.0f, planeSize);

            glEnd();
//        }
//    }

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Scenario::updateCamera()
{
    std::vector<double> eyesPosition = this->penguin->getEyesPosition();
    std::vector<double> focusPosition = this->penguin->getFocusPosition();
    std::pair<double, double> backPosition;
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    switch(this->cameraState) {
        case SCENARIO_CAMERA_TP:
            backPosition = this->penguin->getNewPosition<double>(-2.5);
            
            gluLookAt(backPosition.first + SCENARIO_CENTER_TRANSLATION,
                eyesPosition[1] + 1.7,
                backPosition.second + SCENARIO_CENTER_TRANSLATION,
                focusPosition[0] + SCENARIO_CENTER_TRANSLATION,
                focusPosition[1],
                focusPosition[2] + SCENARIO_CENTER_TRANSLATION,
                0.0,
                1.0,
                0.0);
            break;
        case SCENARIO_CAMERA_FP:
            gluLookAt(eyesPosition[0] + SCENARIO_CENTER_TRANSLATION,
                eyesPosition[1],
                eyesPosition[2] + SCENARIO_CENTER_TRANSLATION,
                focusPosition[0] + SCENARIO_CENTER_TRANSLATION,
                focusPosition[1],
                focusPosition[2] + SCENARIO_CENTER_TRANSLATION,
                0.0,
                1.0,
                0.0);
            break;
        case SCENARIO_CAMERA_OVER:
            GLfloat mapCenter = SCENARIO_MAP_SIZE/2.0;
            gluLookAt(mapCenter,
                SCENARIO_MAP_SIZE * 1.5,
                mapCenter,
                mapCenter,
                -1.0,
                mapCenter,
                0.0,
                0.0,
                -1.0);
            break;
    }
}

void Scenario::render()
{
    glClearColor(backgrundColor[0],backgrundColor[1],backgrundColor[2],backgrundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // limpar o depth buffer
    
    this->updateCamera();
    
    glPushMatrix();
    glTranslatef(SCENARIO_CENTER_TRANSLATION, 0.0, SCENARIO_CENTER_TRANSLATION);
    for(int i=0; i < SCENARIO_MAP_SIZE; i++) {
        for(int j=0; j < SCENARIO_MAP_SIZE; j++) {
            
            if (map[i][j]) {
                
                glPushMatrix();
                
                map[i][j]->draw();
                
                glPopMatrix();
            }
        }
    }	
	//Render Conceptions
	for (std::list<Conception*>::iterator it=conceptions.begin(); it != conceptions.end(); ++it){
		Conception* current = (*it);
		glPushMatrix();
		
        current->draw();
		
		glPopMatrix();
	}
    glPopMatrix();
    
    this->renderFloor();
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

    //this->updateCamera();
}

bool Scenario::outOfMap(std::pair<int, int> position){
	return position.first < 0 || position.first >= SCENARIO_MAP_SIZE
			|| position.second < 0 || position.second >= SCENARIO_MAP_SIZE;
}

std::vector< std::pair<int,int> > Scenario::getFreeMapPositions()
{
    std::vector< std::pair<int,int> > result;
    
    for(int i=0; i < SCENARIO_MAP_SIZE; i++) {
        for(int j=0; j < SCENARIO_MAP_SIZE; j++) {
            
            if (!map[i][j])
                result.push_back(std::pair<int,int>(i, j));
        }
    }
    
    return result;
}

std::vector<std::pair<int,int> > Scenario::getMobileBlockPositions()
{
    std::vector< std::pair<int,int> > result;
    
    for(int i=0; i < SCENARIO_MAP_SIZE; i++) {
        for(int j=0; j < SCENARIO_MAP_SIZE; j++) {
            
            if ((map[i][j])
            && (dynamic_cast<Block*>(map[i][j])))
                result.push_back(std::pair<int,int>(i, j));
        }
    }
    
    return result;
}

Enemy* Scenario::createEnemyAt(int row, int col)
{
    C3DObject* obj = new C3DObject();
    obj->Load((this->resourceFolder + SCENARIO_ENEMY_FILENAME).c_str());
    
    Enemy* enemy = new Enemy(obj, std::pair<double, double>(col,row));
    
    map[row][col] = enemy;
    return enemy;
}

Penguin* Scenario::createPenguinAt(int row, int col)
{
    C3DObject* obj = new C3DObject();
    obj->Load((this->resourceFolder + SCENARIO_PENGUIN_FILENAME).c_str());
    
	map[row][col] = new Penguin(obj, std::pair<double, double>(col,row));
    this->penguin = (Penguin*)map[row][col];
    return this->penguin;
}

Item* Scenario::createItemInsideBlockAt(int row, int col)
{
    Item* newItem = NULL;
    if (map[row][col]) {
        Block* blockWithItem = (Block*)map[row][col];
        
        C3DObject* obj = new C3DObject();
        obj->Load((this->resourceFolder + SCENARIO_ITEM_FILENAME).c_str());

        newItem = new Item(obj, blockWithItem->position, ITEM_KIND_PLUS_SPEED);
        blockWithItem->item = newItem;
    }
    
    return newItem;
}

Conception* Scenario::createConceptionAt(int row, int col, int numSteps)
{
	C3DObject* obj = new C3DObject();
	obj->Load((this->resourceFolder + SCENARIO_BLOCK_FILENAME).c_str());

	Block* newBlock = new Block(obj, std::pair<double,double>((double)col, (double)row), NULL, true);
	
	C3DObject* conceptionObj = new C3DObject();
    conceptionObj->Load((this->resourceFolder + SCENARIO_CONCEPTION_FILENAME).c_str());

	Conception* newConception = new Conception(newBlock, numSteps, 
			conceptionObj, std::pair<double,double>((double)col, (double)row));
	
	conceptions.push_back(newConception);
	
	return newConception;
}
