#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>

#include <GL/gl.h>
#include <GL/glu.h>
#include "bitmap.h"
#include "Modelable.h"

#define SCENARIO_MAP_SIZE 15
#define SCENARIO_MAP_FILENAME "map.bmp"
#define SCENARIO_TEXTURE_FLOOR_FILENAME "groundTexture.bmp"
#define SCENARIO_MAP_COLOR_IMBLOCK 0x000000FF
#define SCENARIO_MAP_COLOR_BLOCK 0x0000FF00
#define SCENARIO_IMBLOCK_FILENAME "penguin.obj"
#define SCENARIO_BLOCK_FILENAME "penguin.obj"

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
    
public:
	C3DObject* map[SCENARIO_MAP_SIZE][SCENARIO_MAP_SIZE];

	int cameraState;

	Scenario(std::string _resourceFolder);

	void render();

	void init();

	void updateWindow(int windowWidth, int windowHeight);

};
#endif
