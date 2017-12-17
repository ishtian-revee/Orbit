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
#include "display.h"
#include "materials.h"
#include "io_handler.h"
#include "planet.h"
#include "stars.h"
#include "planetoid.h"

using namespace std;

// global scope


// function prototypes
//void intructions(void);
void update(int value);
void handleResize(int width, int height);

// main function
int main(int argc, char** argv){

//    intructions();
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
    glutKeyboardFunc(keyboardInput);

    glutMainLoop();
	return 0;
}

//void intructions(void){
//
//	cout << "SPACE to play/pause the simulation." << endl;
//	cout << "ESC to exit the simulation." << endl;
//	cout << "O to show/hide Big Orbital Trails." << endl;
//	cout << "o to show/hide Small Orbital Trails." << endl;
//	cout << "M/m to show/hide Moons." << endl;
//	cout << "L/l to show/hide labels" << endl;
//	cout << "1, 2 and 3 to change camera angles." << endl;
//	cout << "Scroll to change camera movement" << endl;
//}

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
