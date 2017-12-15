#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

// header files
#include "planet.h"
#include "stars.h"

/*
This function draws every 3D scenes to the display window
*/
void display(){

    // sets the bit plane area of the window to values previously selected by glClearColor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);             // switch to the drawing perspective
	glLoadIdentity();                       // reset the drawing perspective
	glRotatef(10.0, 1.0f, 0.0f, 0.0f);      // rotate the camera

	// produces a translation of camera by x y z co-ordinate by multiplying between this matrix and current matrix
	glTranslatef(0.0f, -2.0f, -17.0f);

	glPushMatrix();                         // save the transformations performed thus far
	glRotatef(-60.0, 1.0f, 0.0f,0.0f);

	// rendering stars
	glPushMatrix();
	glTranslatef(-95.0f, -140.0f, -50.0f);  // saving the transformations of the stars projection
	renderStars();
	glPopMatrix();

	// rendering the sun
	glPushMatrix();
	changeColor(0.99, 0.84, 0.20, 1.0);        // setting sun color
	glBegin(GL_LINES);
	glutSolidSphere(0.5f, 45, 45);
	glEnd();
	glPopMatrix();

	// rendering all the planets
	renderPlanet(mercury);
	renderPlanet(venus);
	renderPlanet(earth);
	renderPlanet(mars);
	renderPlanet(jupiter);
	renderPlanet(saturn);
	renderPlanet(urenus);
	renderPlanet(neptune);
	renderPlanet(pluto);

    glPopMatrix();
	glutSwapBuffers();
}

#endif // DISPLAY_H_INCLUDED
