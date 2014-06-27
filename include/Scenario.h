#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>

#include <GL/gl.h>
#include <GL/glu.h>
#include "bitmap.h"
#include "Modelable.h"
#include "Penguin.h"

#define SCENARIO_CAMERA_TP 0
#define SCENARIO_CAMERA_FP 1
#define SCENARIO_CAMERA_OVER 2

#define SCENARIO_CENTER_TRANSLATION 0.5f

#define SCENARIO_MAP_SIZE 16
#define SCENARIO_MAP_FILENAME "map.bmp"
#define SCENARIO_TEXTURE_FLOOR_FILENAME "groundTexture.bmp"
#define SCENARIO_MAP_COLOR_IMBLOCK 0x000000FF
#define SCENARIO_IMBLOCK_FILENAME "block.obj"
#define SCENARIO_MAP_COLOR_BLOCK 0x0000FF00
#define SCENARIO_BLOCK_FILENAME "block.obj"
#define SCENARIO_MAP_COLOR_ENEMY 0x00FF0000
#define SCENARIO_ENEMY_FILENAME "bee.obj"
#define SCENARIO_PENGUIN_FILENAME "penguin.obj"

class Scenario
{
private:
    float backgrundColor[4];
    
    std::string resourceFolder;
    
    /* Textures */
    GLubyte* floorTexture;
    BITMAPINFO * floorTextureInfo;
    GLuint floorTextureId;
    
    void initTexture();
    
    void initMap();
    
    void initLight();
    
    void renderFloor();
    
    void updateCamera();
    
public:
	Modelable* map[SCENARIO_MAP_SIZE][SCENARIO_MAP_SIZE];
    
    Penguin* penguin;

	int cameraState;

	Scenario(std::string _resourceFolder);
    
    ~Scenario();

	void render();

	void init();

	void updateWindow(int windowWidth, int windowHeight);

    bool outOfMap(std::pair<int, int> position);

};
#endif
