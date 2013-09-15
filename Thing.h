#ifndef THING_H
#define THING_H

#include "graphicslib.h"
#include "vec3.h"

#define NORTH 1;
#define EAST 2;
#define SOUTH 3;
#define WEST 4;

class Thing
{
public:
	Thing();
	~Thing();
    virtual void draw();
	virtual void advanceFrame();
    void setpos(double x,double y,double z) {pos.set(x,y,z);}

protected:
    Vec3 pos; // position 
    Vec3 velocity;
    Vec3 dynamics; // roll pitch and yaw 

    void sphere(double x,double y,double z,
                double dx,double dy,double dz);
    void Cube (double x,double y,double z,
               double xLength, double yLength, double zLength,
               double th,double rx,double ry,double rz);
    void Cylinder (double x,double y,double z,
                   double length, double radius,
                   double th, double rx,double ry,double rz);
    void Ring (double x,double y,double z,
              double outerRadius, double innerRadius,double height,
               double rx,double ry,double rz,
               double begin,double end);
    void texturedSphere (double x,double y,double z,
                         double dx, double dy, double dz,
                         GLuint tex);
    void torus(double x,double y,double z,
               double donutRadius,double tubeRadius,
               double th,double rx,double ry,double rz);
    void texturedTorus(double x,double y,double z,
                       double donutRadius,double tubeRadius,
                       double th,double rx,double ry,double rz,
                       GLuint tex);


};
#endif
