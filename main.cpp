#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<cmath>

#define RADIAN 180.0/3.141592

// global scope variables
int width = 750;
int height = 750;

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

using namespace std;

// main function
int main(int argc, char** argv){

    // previous code
//    if(solarSystemSimulation){
//
//        createPlanets();
//        generateRandomPosition();
//
//        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
//    }else if(orbitalGameSimulation){
//
//        createPlanetoid();
//
//        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    // determines the OpenGL display mode
//    }
//
//    glutInit(&argc, argv);                                          // initializes the GLUT library
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
//    glutInitWindowSize(width, height);                              // defines window size
//    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
//                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
//    glutCreateWindow("Orbit");                                      // creates the window
//
//    if(solarSystemSimulation){
//
//        init();
//        initRendering();
//    }else if(orbitalGameSimulation){
//
//        glClearColor(0, 0, 0, 1);
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(-500.0, 350.0, 500.0, -350.0, 0, 1);
//    }
//
//    // handler functions
//    glutDisplayFunc(display);                                       // sets the display callback for the current window
//    glutReshapeFunc(handleResize);
//
//    glutKeyboardFunc(keyboardInput);
//    glutMouseFunc(mouseInput);
//	glutMotionFunc(mouseMotionInput);
//
//	// adding a timer function
//    if(solarSystemSimulation){
//
//        glutTimerFunc(25, simulationUpdate, 0);
//    }else if(orbitalGameSimulation){
//
//        glutTimerFunc(1, gameUpdate, 0);
//    }

    // -------------------------------------------------------------------------------------------------------------------

    // only solar system simulation
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
//  glutMouseFunc(mouseInput);
//	glutMotionFunc(mouseMotionInput);

	// adding a timer function
	glutTimerFunc(25, simulationUpdate, 0);

    // -------------------------------------------------------------------------------------------------------------------

    // only game simulation
//    createPlanetoid();
//
//    glutInit(&argc, argv);                                          // initializes the GLUT library
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
//    glutInitWindowSize(width, height);                              // defines window size
//    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
//                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
//    glutCreateWindow("Orbit");                                      // creates the window
//
//    glClearColor(0, 0, 0, 1);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-(float)(width/2), (float)(height/2),
//            (float)(width/2), -(float)(height/2), 0, 1);

//    glutDisplayFunc(display);
//    glutMouseFunc(mouseInput);
//	  glutMotionFunc(mouseMotionInput);
//    glutKeyboardFunc(keyboardInput);
//
//    // adding a timer function
//    glutTimerFunc(1, gameUpdate, 0);

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
        drawString(GLUT_BITMAP_HELVETICA_18, "Press L or l for Planet Labels"); // drawing instructions strings
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-5.85, -9.2, 0.0);                                         // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Press S or s for Orbital Simulation Screen"); // drawing instructions strings
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-5.69, -9.7, 0.0);                                        // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Press ESC to terminate");         // drawing instructions strings
        glPopMatrix();
    }else if(orbitalGameSimulation){

        glPushMatrix();
        glRasterPos3f(-360.0, 325.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Press G or g to set speed with specific direction and then drag it");
        glPopMatrix();

        glPushMatrix();
        glRasterPos3f(-360.0, 350.0, 0.0);                                      // setting string rendering position
        drawString(GLUT_BITMAP_HELVETICA_18, "Press ESC to terminate");         // drawing instructions strings
        glPopMatrix();
    }
}
