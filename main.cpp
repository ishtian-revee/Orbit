#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<cmath>

#define RADIAN 180.0/3.141592

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


// function prototypes

// main function
int main(int argc, char** argv){

    if(solarSystemSimulation){

        createPlanets();
        generateRandomPosition();

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
    }else if(orbitalGameSimulation){

        createPlanetoid();

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    // determines the OpenGL display mode
    }

    glutInit(&argc, argv);                                          // initializes the GLUT library
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
    glutInitWindowSize(width, height);                              // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-width)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-height)/2); // setting the window at the middle of the screen
    glutCreateWindow("Orbit");                                      // creates the window

    if(solarSystemSimulation){

        init();
        initRendering();
    }else if(orbitalGameSimulation){

        glClearColor(0, 0, 0, 1);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-500.0, 350.0, 500.0, -350.0, 0, 1);
    }

    // handler functions
    glutDisplayFunc(display);                                       // sets the display callback for the current window
    glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouseInput);
	glutMotionFunc(mouseMotionInput);

	// adding a timer function
    if(solarSystemSimulation){

        glutTimerFunc(25, simulationUpdate, 0);
    }else if(orbitalGameSimulation){

        glutTimerFunc(1, gameUpdate, 0);
    }

    glutMainLoop();
	return 0;
}
