#include "Overlay.h"

Overlay::Overlay() {

}

Overlay::~Overlay() {

}

void Overlay::draw()
{
   	//  prepare to draw
	glPushAttrib(GL_TRANSFORM_BIT|GL_ENABLE_BIT);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0,800,600,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1,1,1);
	// Draw here
	
	// Draw power control border
	double powerPanel[]={700,120,50,160};	// panel for power control (x,y,width,height)
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(powerPanel[0],powerPanel[1]);
	glVertex2f(powerPanel[0]+powerPanel[2],powerPanel[1]);
	glVertex2f(powerPanel[0]+powerPanel[2],powerPanel[1]+powerPanel[3]);
	glVertex2f(powerPanel[0],powerPanel[1]+powerPanel[3]);
	glEnd();
	glColor3f(0,0,0);

   	//  Finish drawing
   	glPopMatrix();
   	glMatrixMode(GL_PROJECTION);
   	glPopMatrix();
   	glPopAttrib();
}


