#include "Thing.h"

Thing::Thing()
{
    pos.set(0,0,0); 
    velocity.set(0,0,0);
    dynamics.set(0,0,0);
}
Thing::~Thing() {

}
void Thing::advanceFrame()
{
    pos += velocity;
}
void Thing::draw() {

}

/*
Draws a ball wrapped in a texture
(x,y,z) is the location of the center
default radius is 1
size is scaled by (dx,dy,dz)
tex is the texture
*/
void Thing::texturedSphere (double x,double y,double z,
		  double dx, double dy, double dz,
		  GLuint tex)
{
	double inc=5;
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(dx,dy,dz);
   	//  Enable textures
  	glEnable(GL_TEXTURE_2D);
   	// Begin drawing
	glColor3f(1,1,1);
   	glBindTexture(GL_TEXTURE_2D,tex);	
	glBegin(GL_QUAD_STRIP);	
	for (double i=0;i<=180;i+=inc)
	{
		for (double j=0;j<=360;j+=inc)
		{
   			glNormal3f( Cos(j+0  )*Sin(i+0  ), Cos(i+0  ), Sin(j+0  )*Sin(i+0  ));
			glTexCoord2f( (j+0  )/360,(i+0  )/180);
			glVertex3f( Cos(j+0  )*Sin(i+0  ), Cos(i+0  ), Sin(j+0  )*Sin(i+0  ));
			glNormal3f( Cos(j+0  )*Sin(i+inc), Cos(i+inc), Sin(j+0  )*Sin(i+inc));
			glTexCoord2f( (j+0  )/360,(i+inc)/180);
			glVertex3f( Cos(j+0  )*Sin(i+inc), Cos(i+inc), Sin(j+0  )*Sin(i+inc));
		}
	}
	glEnd();
	// Finished drawing	
	glPopMatrix();
   	glDisable(GL_TEXTURE_2D);
}
/*
Draws a ball 
(x,y,z) is the location of the center
default radius is 1
color is determined by state machine
size is scaled by (dx,dy,dz)
*/
void Thing::sphere(double x,double y,double z,
                 double dx,double dy,double dz)
{
	double inc=5;
	glPushMatrix();
	glTranslated(x,y,z);
	glScaled(dx,dy,dz);
	// Begin drawing
	for (double i=0;i<180;i+=inc)
	{
		glBegin(GL_QUAD_STRIP);
		for (double j=0;j<=360;j+=inc)
		{
			glNormal3f( Cos(j+0  )*Sin(i+0  ), Cos(i+0  ), Sin(j+0  )*Sin(i+0  ));
			glVertex3f( Cos(j+0  )*Sin(i+0  ), Cos(i+0  ), Sin(j+0  )*Sin(i+0  ));
			glNormal3f( Cos(j+0  )*Sin(i+inc), Cos(i+inc), Sin(j+0  )*Sin(i+inc));
			glVertex3f( Cos(j+0  )*Sin(i+inc), Cos(i+inc), Sin(j+0  )*Sin(i+inc));
		}
		glEnd();
	}
	// Finished drawing	
	glPopMatrix();
}
/*
Draws a torus 
(x,y,z) is the location of the center
donutRadius is the radius of the primary circls
tubeRadius is the radius of the tube
color is determined by state machine
rotated th degrees around vector (rx,ry,rz)
*/
void Thing::torus(double x,double y,double z,
		double donutRadius,double tubeRadius,
		double th,double rx,double ry,double rz)
{
	double inc=5;
	glPushMatrix();
	glTranslated(x,y,z);
	glRotated(th,rx,ry,rz);
	// Begin drawing
	for (double i=0;i<360;i+=inc) // progress around donut
	{
		glBegin(GL_QUAD_STRIP);
		double centerX_1=Cos(i+0  )*donutRadius;
		double centerZ_1=Sin(i+0  )*donutRadius;
		double centerX_2=Cos(i+inc)*donutRadius;
		double centerZ_2=Sin(i+inc)*donutRadius;

		for (double j=0;j<=360;j+=inc)
		{
			double surfaceX_1=centerX_1+  Cos(i+0  )*Cos(j+0  )*tubeRadius;
			double surfaceY_1=Sin(j+0  )*tubeRadius;
			double surfaceZ_1=centerZ_1+  Sin(i+0  )*Cos(j+0  )*tubeRadius;
			glNormal3f(Cos(i+0  )*Cos(j+0),  Sin(j+0  ),  Sin(i+0  )*Cos(j+0  ));
			glVertex3f(surfaceX_1,surfaceY_1,surfaceZ_1);
			
			double surfaceX_2=centerX_2+  Cos(i+inc)*Cos(j+0  )*tubeRadius;
			double surfaceY_2=Sin(j+0  )*tubeRadius;
			double surfaceZ_2=centerZ_2+  Sin(i+inc)*Cos(j+0  )*tubeRadius;
			glNormal3f(Cos(i+inc)*Cos(j+0),  Sin(j+0  ),  Sin(i+inc)*Cos(j+0  ));
			glVertex3f(surfaceX_2,surfaceY_2,surfaceZ_2);
		}
		glEnd();
	}
	glPopMatrix();
}
/*
Draws a textured torus 
(x,y,z) is the location of the center
donutRadius is the radius of the primary circls
tubeRadius is the radius of the tube
color is determined by state machine
rotated th degrees around vector (rx,ry,rz)
with texture tex
*/
void Thing::texturedTorus(double x,double y,double z,
		double donutRadius,double tubeRadius,
		double th,double rx,double ry,double rz,
		GLuint tex)
{
	double inc=5;
	glPushMatrix();
	glTranslated(x,y,z);
	glRotated(th,rx,ry,rz);
   	//  Enable textures
  	glEnable(GL_TEXTURE_2D);
   	// Begin drawing
	glColor3f(1,1,1);
   	glBindTexture(GL_TEXTURE_2D,tex);	
	for (double i=0;i<360;i+=inc) // progress around donut
	{
		glBegin(GL_QUAD_STRIP);
		double centerX_1=Cos(i+0  )*donutRadius;
		double centerZ_1=Sin(i+0  )*donutRadius;
		double centerX_2=Cos(i+inc)*donutRadius;
		double centerZ_2=Sin(i+inc)*donutRadius;

		for (double j=0;j<=360;j+=inc)
		{
			double surfaceX_1=centerX_1+  Cos(i+0  )*Cos(j+0  )*tubeRadius;
			double surfaceY_1=Sin(j+0  )*tubeRadius;
			double surfaceZ_1=centerZ_1+  Sin(i+0  )*Cos(j+0  )*tubeRadius;
			glNormal3f(Cos(i+0  )*Cos(j+0),  Sin(j+0  ),  Sin(i+0  )*Cos(j+0  ));
			glTexCoord2f( (i+0  )/360,(j+0  )/360);
			glVertex3f(surfaceX_1,surfaceY_1,surfaceZ_1);
			
			double surfaceX_2=centerX_2+  Cos(i+inc)*Cos(j+0  )*tubeRadius;
			double surfaceY_2=Sin(j+0  )*tubeRadius;
			double surfaceZ_2=centerZ_2+  Sin(i+inc)*Cos(j+0  )*tubeRadius;
			glNormal3f(Cos(i+inc)*Cos(j+0),  Sin(j+0  ),  Sin(i+inc)*Cos(j+0  ));
			glTexCoord2f( (i+inc)/360,(j+0  )/360);
			glVertex3f(surfaceX_2,surfaceY_2,surfaceZ_2);
		}
		glEnd();
	}
	glPopMatrix();
}
/*
Draws a cube
centered at (x,y,z)
with size (xLength,yLength,zLength)
rotated th degrees around (rx,ry,rz)
*/
void Thing::Cube (double x,double y,double z,
	   double xLength, double yLength, double zLength,
	   double th,double rx,double ry,double rz)
{
	glPushMatrix();
	// Transform 
	glTranslated(x,y,z);
	glRotated(th,rx,ry,rz);
   	glScaled(xLength/2,yLength/2,zLength/2);
	glBegin(GL_QUADS);
	// +x side
   	glNormal3f( 1, 0, 0);
	glVertex3d(1,1,1);
	glVertex3d(1,1,-1);
	glVertex3d(1,-1,-1);
	glVertex3d(1,-1,1);
	// +z side
  	glNormal3f( 0, 0, 1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(1,-1,1);
	// -x side
   	glNormal3f( -1, 0, 0);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(-1,-1,1);
	// -z side
  	glNormal3f( 0, 0, -1);
	glVertex3d(1,1,-1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	// Top
   	glNormal3f( 0, 1, 0);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(1,1,-1);
	// Bottom
	glNormal3f( 0, -1, 0);
	glVertex3d(1,-1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	glEnd();
	glPopMatrix();
}
/*
Draws a Cylinder
centered at (x,y,z)
with length 'length' and radius 'radius'
rotated th degrees around vector(rx,ry,rz)
*/
void Thing::Cylinder (double x,double y,double z,
		double length, double radius,
		double th, double rx,double ry,double rz)
{
	glPushMatrix();
	// Transform 
	glTranslated(x,y,z);
	glRotated(th,rx,ry,rz);
	// Sides
	glBegin(GL_QUAD_STRIP);
	for(double i=0;i<=360;i+=5)
	{
   		glNormal3f( 0,Sin(i), Cos(i));
		glVertex3d(-length/2,Sin(i)*radius,Cos(i)*radius);
		glVertex3d(length/2,Sin(i)*radius,Cos(i)*radius);
	}
	glEnd();
	// Ends
	glBegin(GL_POLYGON);
   	glNormal3f( -1,0, 0);
	for(double i=0;i<360;i+=5) 
	{
		glVertex3d(-length/2,Sin(i)*radius,Cos(i)*radius);
	}
	glEnd();
	glBegin(GL_POLYGON);
   	glNormal3f( 1,0, 0);
	for(double i=0;i<360;i+=5)
	{
		glVertex3d(length/2,Sin(i)*radius,Cos(i)*radius);
	}
	glEnd();
	glPopMatrix();	
}

/*
Draws a solid ring with square corners
Center at (x,y,z)
begins at 'begin' degrees, draws clockwise, ending at 'end' degrees. 0 at +x axis
*/
void Thing::Ring (double x,double y,double z,
	   double outerRadius, double innerRadius,double height,
	   double rx,double ry,double rz,
	   double begin,double end)
{
	int i;
	glPushMatrix();
	// Transform 
	glTranslated(x,y,z);
	glRotated(rx,1,0,0);
	glRotated(ry,0,1,0);
	glRotated(rz,0,0,1);
	// Top
	glBegin(GL_QUAD_STRIP);
   	glNormal3f( 0,1, 0);
	for(i=begin;i<=end;i++)
	{
		glVertex3d(Cos(i)*innerRadius,height/2,Sin(i)*innerRadius);
		glVertex3d(Cos(i)*outerRadius,height/2,Sin(i)*outerRadius);
	}
	glEnd();
	// Bottom
	glBegin(GL_QUAD_STRIP);
   	glNormal3f( 0,1, 0);
	for(i=begin;i<=end;i++)
	{
		glVertex3d(Cos(i)*innerRadius,-(height/2),Sin(i)*innerRadius);
		glVertex3d(Cos(i)*outerRadius,-(height/2),Sin(i)*outerRadius);
	}
	glEnd();
	// Outer Edge
	glBegin(GL_QUAD_STRIP);
	for(i=begin;i<=end;i++)
	{
	   	glNormal3f( Cos(i)*outerRadius,0, Sin(i)*outerRadius);
		glVertex3d(Cos(i)*outerRadius,-(height/2),Sin(i)*outerRadius);
		glVertex3d(Cos(i)*outerRadius,(height/2),Sin(i)*outerRadius);
	}
	glEnd();
	// Inner Edge
	glBegin(GL_QUAD_STRIP);
	for(i=begin;i<=end;i++)
	{
	   	glNormal3f( -Cos(i)*outerRadius,0, -Sin(i)*outerRadius);
		glVertex3d(Cos(i)*innerRadius,-(height/2),Sin(i)*innerRadius);
		glVertex3d(Cos(i)*innerRadius,(height/2),Sin(i)*innerRadius);
	}
	glEnd();
	glPopMatrix();
}

