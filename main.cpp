#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<cmath>
#include<sstream>
#include<string>
#include<IrrKlang/irrklang.h>

#define RADIAN 180.0/3.141592

// global scope variables
int width = 750;
int height = 750;
int planetoidCount = 0;
int planetCount = 0;

// function prototypes
void gameSimulationWindowHandler();
void drawInstructions();

// header files
#include "initialization.h"
#include "updates.h"
#include "display.h"
#include "materials.h"
#include "io_handler.h"
#include "planet.h"
#include "stars.h"
#include "planetoid.h"
#include "music.h"

using namespace std;

// main function
int main(int argc, char** argv){

    // only solar system simulation
//    playMusic();
    createPlanets();
    generateRandomPosition();

    glutInit(&argc, argv);                                          // initializes the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
    glutInitWindowSize(width, height);                              // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
    glutCreateWindow("Orbit");                                      // creates the window

    // initializations
    init();
    initRendering();

    // handler functions
    glutDisplayFunc(display);           // sets the display callback for the current window
    // sets the reshape callback for the current window and is triggered when a window is reshaped
    glutReshapeFunc(handleResize);

    // i/o handlers
    glutKeyboardFunc(keyboardInput);

	// adding a timer function
	glutTimerFunc(25, simulationUpdate, 0);

    glutMainLoop();                        // enters the GLUT event processing loop
	return 0;
}

/*
This function setups all the pre requirements for game simulation
*/
void gameSimulationWindowHandler(){

    createPlanetoid();

    // clearing buffers and indicating the buffers currently enabled for color writing and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                            // determines the OpenGL display mode
    glutInitWindowSize(width, height);                                      // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                                   (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
    glutCreateWindow("Orbit");                                              // creates the window

    glClearColor(0, 0, 0, 1);                               // clears the color buffers
    glMatrixMode(GL_PROJECTION);                            // applies subsequent matrix operations to the projection matrix stack
    glLoadIdentity();                                       // reset the drawing perspective
    glOrtho(-(float)(width/2), (float)(width/2),
            (float)(height/2), -(float)(height/2), 0, 1);   // describes a transformation that produces a parallel projection

    // handler functions
    glutDisplayFunc(display);                               // sets the display callback for the current window

    // i/o handlers
    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouseInput);
	glutMotionFunc(mouseMotionInput);

    // adding a timer function
    glutTimerFunc(1, gameUpdate, 0);

    glutMainLoop();                 // enters the GLUT event processing loop
}

/*
This function will display all instruction strings to the screen
*/
void drawInstructions(){

    if(solarSystemSimulation){

        glPushMatrix();
        glRasterPos3f(-6.0, -8.7, 0.0);                                         // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "i. Press L or l for Planet Labels"); // drawing instructions strings
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-5.85, -9.2, 0.0);                                        // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "ii. Press S or s for Orbital Simulation Screen"); // drawing instructions strings
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-5.69, -9.7, 0.0);                                        // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "iii. Press ESC to terminate");    // drawing instructions strings
        glPopMatrix();
    }else if(orbitalGameSimulation){

        char activePlanet[5]={'\0'};
        char activePlanetoid[5]={'\0'};

        sprintf(activePlanet, "%d", planetCount);           //%d is for integers
        sprintf(activePlanetoid, "%d", planetoidCount);     //%d is for integers

        glPushMatrix();
        glRasterPos3f(-360.0, -340.0, 0.0);                                     // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Planets: ");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-280.0, -340.0, 0.0);                                     // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, activePlanet);
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, -310.0, 0.0);                                     // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Active Planetoids: ");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-190.0, -310.0, 0.0);                                     // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, activePlanetoid);
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 260.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "i. Left mouse click to create smaller planetoids");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 285.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "ii. Right mouse click to create larger planetoids");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 310.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "iii. Middle mouse click to remove all planetoids");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 335.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "iv. Press G or g to set speed with specific direction and then drag it");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 360.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_12, "v. Press ESC to terminate");      // drawing instructions strings
        glPopMatrix();
    }
}
