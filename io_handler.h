#ifndef IO_HANDLER_H_INCLUDED
#define IO_HANDLER_H_INCLUDED

// header files
#include "planetoid.h"

// global scope variables
bool PRESSED_LEFT = false;
bool PRESSED_MIDDLE = false;
bool PRESSED_RIGHT = false;
bool SPEED_UP = false;

bool labelsActive = true;
bool solarSystemSimulation = true;
bool orbitalGameSimulation = false;

/*
This function handles all keyboard inputs
*/
void keyboardInput(unsigned char key, int x, int y){

    // this will display the orbital game simulation
    if(key == 's' || key == 'S'){

        if(solarSystemSimulation){

            solarSystemSimulation = false;
            orbitalGameSimulation = true;
            gameSimulationWindowHandler();
        }else{

//            solarSystemSimulation = true;
//            orbitalGameSimulation = false;
        }

        glutPostRedisplay();
    }

    // this will activate all the planet name labels to the screen
    if(key == 'l' || key == 'L'){

        if(labelsActive){

            labelsActive = false;
        }else{

            labelsActive = true;
        }

        glutPostRedisplay();
    }

    // this will activate planetoid dragging option
    if(key == 'g' || key == 'G'){

        if(orbitalGameSimulation){

            SPEED_UP = !SPEED_UP;
        }
    }

    // this will close the application
    if(key == 27){

        exit(0);
    }
}

/*
This function handles all mouse inputs
*/
void mouseInput(int button, int state, int x, int y){

    // setting co-ordinates
    mX = x - (width/2);
    mY = y - (height/2);

    // adding speed to the planetoids by line dragging
    if(SPEED_UP){

        // checking line dragging co-ordinate and left mouse button press
        if(line.x2 != 0 && line.y2 != 0 && state == GLUT_UP && PRESSED_LEFT){

            // adding a planetoid with motion speed
            addPlanetoid(100, 9, 1, line.x1-line.x2, line.y1-line.y2);
        }else{

            // setting line co ordinates for rendering
            line.x1 = line.x2 = mX;
			line.y1 = line.y2 = mY;
        }
    }

    // checking which button is being pressed
    if(button == GLUT_LEFT_BUTTON)

		PRESSED_LEFT = state == GLUT_DOWN;
	else if(button == GLUT_RIGHT_BUTTON)

		PRESSED_RIGHT = state == GLUT_DOWN;
	else if(button == GLUT_MIDDLE_BUTTON)

		PRESSED_MIDDLE = state == GLUT_DOWN;

    // if left button is clicked then small planetoids will generate
    if(PRESSED_LEFT && !SPEED_UP){

        addPlanetoid(10, 6, 1, NULL, NULL);         // small planetoids
        PRESSED_LEFT = false;
    }

    // if middle button is clicked then all planetoid objects will be removed
    if(PRESSED_MIDDLE){

        removePlanetoids();                         // remove all planetoids
    }

    // if right button is clicked then larger planetoids will generate
    if(PRESSED_RIGHT){

        addPlanetoid(10000, 15, 0, NULL, NULL);     // adding huge planetoids
        PRESSED_RIGHT = false;
    }
}

/*
This function handles all mouse motion inputs
*/
void mouseMotionInput(int x, int y){

    // setting co-ordinates
    mX = x - (width/2);
    mY = y - (height/2);

    // end of line with dragging
    if(SPEED_UP && PRESSED_LEFT){

        // setting line co ordinates for rendering
        line.x2 = mX;
        line.y2 = mY;
    }
}

#endif // IO_HANDLER_H_INCLUDED
