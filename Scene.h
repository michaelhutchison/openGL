#ifndef SCENE_H
#define SCENE_H

#include "graphicslib.h"
#include "Texture.h"
#include "Boat.h"
#include "Light.h"
#include <vector>

class Scene {
  public:
    Scene();
    ~Scene();

    void axesOn()       {drawAxesOn = true;}
    void axesOff()      {drawAxesOn = false;}
    void toggleAxes()   {drawAxesOn = !drawAxesOn;}
    void draw();
    void initialize();
    void advanceFrame();
private:
    void drawAxes();
    bool drawAxesOn;
    float backgroundColor[4];
    void loadTextures();
    std::vector<Thing*> things;
    //Boat boat;
    Texture textures;
    Light light;

};

#endif
