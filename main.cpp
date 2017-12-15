#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

#define RADIAN 180.0/3.141592

// header files
#include "initialization.h"
#include "display.h"
#include "materials.h"
#include "planet.h"
#include "stars.h"

using namespace std;

// global scope


// function prototypes
void update(int value);
void handleResize(int width, int height);

// main function
int main(int argc, char** argv){

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
    glutTimerFunc(25, update, 0);                                   // adding a timer

    glutMainLoop();
	return 0;
}

/*
This function updates the camera angles
*/
void update(int value){

    glutPostRedisplay();                // display has changed

    glutTimerFunc(25, update, 0);       // calling update() again and again in every 25 milliseconds
}

/*
This function deals with window resize
*/
void handleResize(int width, int height){

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
}
