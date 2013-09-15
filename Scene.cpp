#include "Scene.h"


Scene::Scene() {
    axesOn();
    backgroundColor[0] = 1.0;
    backgroundColor[1] = 1.0;
    backgroundColor[2] = 1.0;
    backgroundColor[3] = 1.0;

}
Scene::~Scene() {

}
void Scene::initialize() {
    loadTextures();
    Boat* boat = new Boat();
    boat->setTextures(textures.get("metal"));
    things.push_back(boat);
}
void Scene::loadTextures() {
    textures.loadTexture("textures/metal2.bmp","metal");
}
void Scene::advanceFrame() {

}
void Scene::draw() {
    // Set lighting
    light.setLighting();

    // Set background color
    glClearColor(backgroundColor[0],
                 backgroundColor[1],
                 backgroundColor[2],
                 backgroundColor[3]);
    if (drawAxesOn) drawAxes();

    for (unsigned int i=0; i<things.size(); ++i) {
        (things[i])->draw();
    }
    
    //boat.draw();
}
/*
Draws X Y Z axes
*/
void Scene::drawAxes()
{
	double len=1;
 	glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(len,0.0,0.0);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(0.0,len,0.0);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(0.0,0.0,len);
    glEnd();
    //  Label axes
    glRasterPos3d(len,0.0,0.0);
    Print("X");
    glRasterPos3d(0.0,len,0.0);
    Print("Y");
    glRasterPos3d(0.0,0.0,len);
    Print("Z");
}

