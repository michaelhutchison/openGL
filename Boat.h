#ifndef BOAT_H
#define BOAT_H


#include "Thing.h"
#include "vec3.h"

class Boat : public Thing {
  public:
    Boat();
    ~Boat();
    void draw();
    void setTextures(GLuint metal) {metalTexture = metal;}
  private:
    GLuint metalTexture;

    void drawCannonBarrel(double height);
    double cannonHorizAngle;
    double cannonVertAngle;
    double cannonPower;

    double heading; 
	double angleToWave;
    Vec3 vectorToWave;
    Vec3 color;
};

#endif
