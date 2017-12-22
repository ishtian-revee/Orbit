#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<cmath>

#define RADIAN 180.0/3.141592

// function prototypes
void temp();

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

// global scope


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

    init();
    initRendering();

    // handler functions
    glutDisplayFunc(display);                                       // sets the display callback for the current window
    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboardInput);
//    glutMouseFunc(mouseInput);
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

    glutMainLoop();
	return 0;
}

void temp(){

    createPlanetoid();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//  glutInit(&argc, argv);                                          // initializes the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);       // determines the OpenGL display mode
    glutInitWindowSize(width, height);                              // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                                   (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
    glutCreateWindow("Orbit");                                      // creates the window

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(float)(width/2), (float)(height/2),
            (float)(width/2), -(float)(height/2), 0, 1);

    glutDisplayFunc(display);
//    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouseInput);
	glutMotionFunc(mouseMotionInput);

    // adding a timer function
    glutTimerFunc(1, gameUpdate, 0);
}
