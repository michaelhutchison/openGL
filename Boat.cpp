#include "Boat.h"

Boat::Boat() {
    pos.set(0,0,0); 
    angleToWave = 0;
    color.set(.5,0,.5);
    vectorToWave.set(0,0,0);
    cannonHorizAngle = 0;
    cannonVertAngle = 0;
    heading = 0;
 
}
Boat::~Boat() {

}
/*
 * Draws the boat
 */
void Boat::draw ()
{
	// dimensions
	// total length is 1
	// total width is .6
	double boatLength=1;
	double boatWidth=.5;
	double deckFrontEdge=.4;
	double deckBackEdge=-.6;
	double deckLeftEdge=-boatWidth/2;
	double deckRightEdge=boatWidth/2;	
	double sideInsetWidth=.2;
	double frontInsetLength=boatWidth/2;
	double backInsetLength=.3;
	double deckThickness=.1;
	double deckSurfaceHeight=.2;
	double frontCornerX=deckFrontEdge-frontInsetLength;
	double backCornerX=deckBackEdge+backInsetLength;
	double deckSideLength=boatLength-(frontInsetLength+backInsetLength);
	double deckEndWidth=boatWidth-(2*sideInsetWidth);
	double hullHeightOverWater=deckSurfaceHeight-deckThickness;
	double hullHeightUnderWater=-.2;
	// prepare to draw
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	// Rotate to match wave
	glRotated(angleToWave, vectorToWave.x,vectorToWave.y,vectorToWave.z);
	glRotated(heading,0,1,0);
	// pitch and roll are not being used to determine boat position
		//glRotated(pitch,0,0,1);
		//glRotated(roll,1,0,0);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,metalTexture);	
	// begin drawing

	// Deck
	glBegin(GL_POLYGON);
	glNormal3f(0,1,0);
	glTexCoord2f(0,frontInsetLength/boatLength);
        glVertex3f(frontCornerX,deckSurfaceHeight,deckLeftEdge);
	glTexCoord2f(boatWidth/boatLength,frontInsetLength/boatLength);	
        glVertex3f(frontCornerX,deckSurfaceHeight,deckRightEdge);
	glTexCoord2f(boatWidth/boatLength,(boatLength-backInsetLength)/boatLength);	
        glVertex3f(backCornerX,deckSurfaceHeight,deckRightEdge);
	glTexCoord2f(((boatWidth/2)-sideInsetWidth)/boatLength,1);	
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckRightEdge-sideInsetWidth);
	glTexCoord2f(sideInsetWidth/boatLength,1);			
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckLeftEdge+sideInsetWidth);
	glTexCoord2f(0,(boatLength-backInsetLength)/boatLength);	
        glVertex3f(backCornerX,deckSurfaceHeight,deckLeftEdge );
	glEnd();
	// deck curved top
	glBegin(GL_POLYGON);
	glNormal3f(0,1,0);
	for (double i=0;i<=180;i=i+5)
	{
		glTexCoord2f(  ((boatWidth/boatLength)/2)+(Cos(i)*(boatWidth/2)), 
				( (boatWidth/2)*(1-(Sin(i))))/boatLength      );
		glVertex3f(	frontCornerX+(Sin(i)*deckRightEdge),
				deckSurfaceHeight,
				Cos(i)*deckRightEdge);
	}
	glEnd();
	// deck curved front
	glBegin(GL_QUAD_STRIP);
	glNormal3f(0,1,0);
	for (double i=0;i<=180;i=i+5)
	{
		glNormal3f(Sin(i),0,Cos(i));
		glTexCoord2f( (i/180)*PI*deckRightEdge,0);
            glVertex3f( frontCornerX+(Sin(i)*deckRightEdge),deckSurfaceHeight,Cos(i)*deckRightEdge);
		glTexCoord2f( (i/180)*PI*deckRightEdge,deckThickness/(PI*deckRightEdge));	
		    glVertex3f( frontCornerX+(Sin(i)*deckRightEdge),deckSurfaceHeight-deckThickness,Cos(i)*deckRightEdge);
	}
	glEnd();
	// Flat Sides      	
	glBegin(GL_QUADS);
	// deck back side
	glNormal3f(-1,0,0);
	glTexCoord2f(0,0);	
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckLeftEdge+sideInsetWidth);
	glTexCoord2f( deckEndWidth/boatLength,0);	
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckRightEdge-sideInsetWidth);
	glTexCoord2f( deckEndWidth/boatLength,deckThickness/boatLength);	
        glVertex3f(deckBackEdge,deckSurfaceHeight-deckThickness,deckRightEdge-sideInsetWidth);
	glTexCoord2f(0,deckThickness/boatLength);	
        glVertex3f(deckBackEdge,deckSurfaceHeight-deckThickness,deckLeftEdge+sideInsetWidth);
	// deck left side
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);
        glVertex3f(frontCornerX,deckSurfaceHeight,deckLeftEdge);
	glTexCoord2f( deckSideLength/boatLength,0);	
        glVertex3f(backCornerX,deckSurfaceHeight,deckLeftEdge);
	glTexCoord2f( deckSideLength/boatLength,deckThickness/boatLength);	
        glVertex3f(backCornerX,deckSurfaceHeight-deckThickness,deckLeftEdge);
	glTexCoord2f(0,deckThickness/boatLength);
        glVertex3f(frontCornerX,deckSurfaceHeight-deckThickness,deckLeftEdge);
	// deck right side
	glNormal3f(0,0,1);
	glTexCoord2f(0,0);
        glVertex3f(backCornerX,deckSurfaceHeight,deckRightEdge);
	glTexCoord2f( deckSideLength/boatLength,0);	
        glVertex3f(frontCornerX,deckSurfaceHeight,deckRightEdge);
	glTexCoord2f( deckSideLength/boatLength,deckThickness/boatLength);	
	    glVertex3f(frontCornerX,deckSurfaceHeight-deckThickness,deckRightEdge);
	glTexCoord2f(0,deckThickness/boatLength);	
        glVertex3f(backCornerX,deckSurfaceHeight-deckThickness,deckRightEdge);
	// deck left corner side
	glNormal3f(-2/3,0,-3/2);	
	glTexCoord2f(0,0);
        glVertex3f(backCornerX,deckSurfaceHeight,deckLeftEdge);
	glTexCoord2f(.36/boatLength,0);
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckLeftEdge+sideInsetWidth);
	glTexCoord2f(.36/boatLength,deckThickness/boatLength);	
        glVertex3f(deckBackEdge,deckSurfaceHeight-deckThickness,deckLeftEdge+sideInsetWidth);
	glTexCoord2f(0,deckThickness/boatLength);
        glVertex3f(backCornerX,deckSurfaceHeight-deckThickness,deckLeftEdge);
	// deck right corner side
	glNormal3f(-2/3,0,3/2);	
	glTexCoord2f(0,0);
        glVertex3f(deckBackEdge,deckSurfaceHeight,deckRightEdge-sideInsetWidth);
	glTexCoord2f(.36/boatLength,0);
        glVertex3f(backCornerX,deckSurfaceHeight,deckRightEdge);
	glTexCoord2f(.36/boatLength,deckThickness/boatLength);	
        glVertex3f(backCornerX,deckSurfaceHeight-deckThickness,deckRightEdge);
	glTexCoord2f(0,deckThickness/boatLength);	glVertex3f(deckBackEdge,deckSurfaceHeight-deckThickness,deckRightEdge-sideInsetWidth);
     	glEnd();
	// Hull
	//front curved surface
	glBegin(GL_TRIANGLES);
	for (double i=0;i<180;i=i+5)
	{
		glNormal3f(Sin(i), -1, Cos(i));
		glTexCoord2f(.5,.5);
            glVertex3f(frontCornerX,hullHeightUnderWater,0);
		glTexCoord2f(.5+Cos(i), .5+Sin(i));	
            glVertex3f( frontCornerX+(Sin(i)*deckRightEdge),hullHeightOverWater,Cos(i)*deckRightEdge);
		glTexCoord2f(.5+Cos(i+5), .5+Sin(i+5));	
            glVertex3f( frontCornerX+(Sin(i+5)*deckRightEdge),hullHeightOverWater,Cos(i+5)*deckRightEdge);
	}
	glEnd();
	// right side of hull
	glBegin(GL_QUADS);
	glNormal3f(0,-1,1);
	glTexCoord2f(0,0);	
        glVertex3f(backCornerX,hullHeightOverWater,deckRightEdge);
	glTexCoord2f(deckSideLength/boatLength,0);	
        glVertex3f(frontCornerX,hullHeightOverWater,deckRightEdge);
	glTexCoord2f(deckSideLength/boatLength,.424/boatLength);
        glVertex3f(frontCornerX,hullHeightUnderWater,0);
	glTexCoord2f(0,.424/boatLength);
        glVertex3f(backCornerX,hullHeightUnderWater,0);
	// left side of hull
	glNormal3f(0,-1,-1);
	glTexCoord2f(0,0);
        glVertex3f(frontCornerX,hullHeightOverWater,deckLeftEdge);
	glTexCoord2f(deckSideLength/boatLength,0);
        glVertex3f(backCornerX,hullHeightOverWater,deckLeftEdge);
	glTexCoord2f(deckSideLength/boatLength,.424/boatLength);
        glVertex3f(backCornerX,hullHeightUnderWater,0);
	glTexCoord2f(0,.424/boatLength);
        glVertex3f(frontCornerX,hullHeightUnderWater,0);
	glEnd();
	// back side of hull
	glBegin(GL_TRIANGLES);	
	glNormal3f(-1,-1,0);
	glTexCoord2f(0,0);	
        glVertex3f(deckBackEdge,hullHeightOverWater,deckLeftEdge+sideInsetWidth);
	glTexCoord2f( deckEndWidth/boatLength,0);
        glVertex3f(deckBackEdge,hullHeightOverWater,deckRightEdge-sideInsetWidth);
	glTexCoord2f( (deckEndWidth/boatLength)/2,.424/boatLength);	
        glVertex3f(backCornerX,hullHeightUnderWater,0);
	
	// left corner side of hull
	glNormal3f(-2/3,-1,-3/2);
	glTexCoord2f(0,0);	
        glVertex3f(backCornerX,hullHeightOverWater,deckLeftEdge);
	glTexCoord2f(.25,0);
        glVertex3f(deckBackEdge,hullHeightOverWater,deckLeftEdge+sideInsetWidth);
	glTexCoord2f(.125,.25);
        glVertex3f(backCornerX,hullHeightUnderWater,0);
	// right corner side of hull
	glNormal3f(-2/3,-1,3/2);
	glTexCoord2f(0,0);
        glVertex3f(deckBackEdge,hullHeightOverWater,deckRightEdge-sideInsetWidth);
	glTexCoord2f(.25,0);
        glVertex3f(backCornerX,hullHeightOverWater,deckRightEdge);
	glTexCoord2f(.125,.25);
        glVertex3f(backCornerX,hullHeightUnderWater,0);
	glEnd();

	// Cannon base
	double turretheight1=.12;//.05;
	double turretradius1=.18;//.14
	double turretheight2=.03;//.1
	double turretradius2=.14;//.18

	glColor3f(color.r(),color.g(),color.b());
	// top of upper turret
	glBegin(GL_POLYGON);
   	glNormal3f( 0,1, 0);
	for(double i=0;i<360;i+=5) 
	{
		glTexCoord2f(.5+Cos(i)*.5, .5+.5*Sin(i)); 
		    glVertex3d(turretradius2*Sin(i),deckSurfaceHeight+turretheight1+turretheight2,turretradius2*Cos(i));
	}
	glEnd();
	// upper turret sides
	glBegin(GL_QUAD_STRIP);
	for(double i=0;i<=360;i+=5)
	{
   		glNormal3f(Sin(i),0, Cos(i));
		glTexCoord2f(i/360,0);
            glVertex3d(turretradius2*Sin(i),deckSurfaceHeight+turretheight1,turretradius2*Cos(i));
		glTexCoord2f(i/360,.1);
            glVertex3d(turretradius2*Sin(i),deckSurfaceHeight+turretheight1+turretheight2,turretradius2*Cos(i));
	}
	glEnd();
	glColor3f(1,1,1);
	// top of lower turret
	glBegin(GL_POLYGON);
   	glNormal3f( 0,1, 0);
	for(double i=0;i<360;i+=5) 
	{
		glTexCoord2f(.5+Cos(i)*.5, .5+.5*Sin(i)); 
            glVertex3d(turretradius1*Sin(i),deckSurfaceHeight+turretheight1,turretradius1*Cos(i));
	}
	glEnd();

	// lower turret sides
	glBegin(GL_QUAD_STRIP);
	for(double i=0;i<=360;i+=5)
	{
   		glNormal3f(Sin(i),0, Cos(i));
		glTexCoord2f(i/360,0); 	
            glVertex3d(turretradius1*Sin(i),deckSurfaceHeight,turretradius1*Cos(i));
		glTexCoord2f(i/360,.1); 
            glVertex3d(turretradius1*Sin(i),deckSurfaceHeight+turretheight1,turretradius1*Cos(i));
	}
	glEnd();
	double centerOfSphere=deckSurfaceHeight+turretheight1+turretheight2+.1;

	// Cannon barrel
	drawCannonBarrel(centerOfSphere);


	glPopMatrix();		
}

void Boat::drawCannonBarrel(double height)
{
	double length=.22;
	double radius=.09;
	double thickness=.02;
	double inc=4;
	// transform
	glPushMatrix();
	glTranslated(0,height,0);
	glRotated(cannonHorizAngle,0,1,0);
	glRotated(cannonVertAngle,0,0,1);
	// Begin drawing
	// Sphere
	glPushMatrix();
	glScaled(.15,.15,.15);
	for (double i=0;i<180;i+=inc)
	{
		glBegin(GL_QUAD_STRIP);
		for (double j=0;j<=360;j+=inc)
		{
			glNormal3f( Cos(j)*Sin(i), Cos(i), Sin(j)*Sin(i));
			glTexCoord2f(j/360, i/180); 		
                glVertex3f(Cos(j+0  )*Sin(i+0  ), Cos(i+0  ), Sin(j+0  )*Sin(i+0  ));
			glNormal3f( Cos(j)*Sin(i+inc), Cos(i+inc), Sin(j)*Sin(i+inc));
			glTexCoord2f(j/360, (i+inc)/180);	
                glVertex3f(Cos(j+0  )*Sin(i+inc), Cos(i+inc), Sin(j+0  )*Sin(i+inc));
		}
		glEnd();
	}
	glPopMatrix();
	// Outside surface
	glBegin(GL_QUAD_STRIP);
	for(double i=0;i<=360;i+=5)
	{
   		glNormal3f( 0,Sin(i), Cos(i));
		glTexCoord2f(i/360,0); 
            glVertex3d(0,Sin(i)*radius,Cos(i)*radius);
		glTexCoord2f(i/360,.2); 
            glVertex3d(length,Sin(i)*radius,Cos(i)*radius);
	}
	glEnd();
	// Inside surface
	glBegin(GL_QUAD_STRIP);
	for(double i=0;i<=360;i+=5)
	{
   		glNormal3f( 0,-Sin(i), -Cos(i));
		glTexCoord2f(i/360,0); 
            glVertex3d(0,Sin(i)*(radius-thickness),Cos(i)*(radius-thickness) );
		glTexCoord2f(i/360,.2);
            glVertex3d(length,Sin(i)*(radius-thickness),Cos(i)*(radius-thickness) );
	}
	glEnd();
	// End
	glBegin(GL_QUAD_STRIP);
	glNormal3f( 1,0,0);
	for(int i=0;i<=360;i+=5)
	{
		glTexCoord2f(.5+Sin(i)*.5, .5+Cos(i)*.5  );	
            glVertex3d(length,Sin(i)*(radius-thickness),Cos(i)*(radius-thickness) );
		glTexCoord2f(.5+Sin(i)*.45, .5+Cos(i)*.45  );	
            glVertex3d(length,Sin(i)*radius,Cos(i)*radius);
	}
	glEnd();
	// Black spot inside
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
   	glNormal3f(-1,0,0);
	for(int i=0;i<=360;i+=5) {
        glVertex3d(.15,Sin(i)*(radius-thickness),Cos(i)*(radius-thickness));
    }
    glEnd();
	glPopMatrix();	
}

