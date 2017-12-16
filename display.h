#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

// header files
#include "planet.h"
#include "stars.h"
#include "labels.h"

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
	changeColor(0.99, 0.84, 0.20, 1.0);             // setting sun color
	glBegin(GL_LINES);
	glutSolidSphere(0.5f, 45, 45);
	glEnd();

	glPushMatrix();
	glRasterPos3f(-0.2, -1.2, 0.0);                 // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Sun");    // drawing sun string
	glPopMatrix();

	glPopMatrix();

	// rendering all the planets
	glPushMatrix();
	renderPlanet(mercury);
	glRasterPos3f(mercury.xPos - 0.4, mercury.yPos - 0.6, 0.0);     // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Mercury");                // drawing mercury string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(venus);
	glRasterPos3f(venus.xPos - 0.4, venus.yPos - 0.65, 0.0);        // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Venus");                  // drawing venus string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(earth);
	glRasterPos3f(earth.xPos - 0.25, earth.yPos - 0.6, 0.0);         // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Earth");                  // drawing earth string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(mars);
	glRasterPos3f(mars.xPos - 0.2, mars.yPos - 0.6, 0.0);           // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Mars");                   // drawing mars string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(jupiter);
	glRasterPos3f(jupiter.xPos - 0.2, jupiter.yPos - 0.8, 0.0);     // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Jupiter");                // drawing jupiter string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(saturn);
	glRasterPos3f(saturn.xPos - 0.3, saturn.yPos - 0.7, 0.0);       // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Saturn");                 // drawing saturn string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(urenus);
	glRasterPos3f(urenus.xPos - 0.2, urenus.yPos - 0.6, 0.0);       // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Urenus");                 // drawing urenus string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(neptune);
	glRasterPos3f(neptune.xPos - 0.2, neptune.yPos - 0.5, 0.0);     // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Neptune");                // drawing neptune string
	glPopMatrix();

	glPushMatrix();
	renderPlanet(pluto);
	glRasterPos3f(pluto.xPos - 0.3, pluto.yPos - 0.45, 0.0);        // setting string rendering position
	drawString(GLUT_BITMAP_HELVETICA_12, "Pluto");                  // drawing pluto string
	glPopMatrix();

    glPopMatrix();
	glutSwapBuffers();
	changeColor(1.0, 1.0, 1.0, 1.0);                                // setting default color
}

#endif // DISPLAY_H_INCLUDED
