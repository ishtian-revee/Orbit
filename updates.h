#ifndef UPDATES_H_INCLUDED
#define UPDATES_H_INCLUDED

// header files
#include "display.h"
#include "io_handler.h"
#include "planetoid.h"

/*
This function deals with solar system simulation timer function
*/
void simulationUpdate(int value){

    glutPostRedisplay();                        // display has changed

    glutTimerFunc(25, simulationUpdate, 0);     // calling update() again and again in every 25 milliseconds
}

/*
This function deals with orbital game simulation timer function
*/
void gameUpdate(int){

    display();

    if(PRESSED_LEFT && !SPEED_UP){

        addPlanetoid(10, 6, 1, NULL, NULL);         // small planetoids
        PRESSED_LEFT = false;
    }

    if(PRESSED_MIDDLE){

        removePlanetoids();                         // remove all planetoids
    }

    if(PRESSED_RIGHT){

        addPlanetoid(10000, 15, 0, NULL, NULL);     // adding huge planetoids
        PRESSED_RIGHT = false;
    }

    for(int i=0; i<planetoids.size(); i++){

        PLANETOID &ptoid1 = planetoids[i];

        bool noCollision = true;

        for(int j=0; j<planetoids.size(); j++){

            // considering 10000 as highest mass of a planetoid so that planetoid won't move
            if(j == i || ptoid1.mass >= 10000){

                continue;
            }

            const PLANETOID &ptoid2 = planetoids[j];
            float distance = sqrt((ptoid2.xPos - ptoid1.xPos) * (ptoid2.xPos - ptoid1.xPos) +
                                  (ptoid2.yPos - ptoid1.yPos) * (ptoid2.yPos - ptoid1.yPos));

            if(distance > ptoid2.radius){

                // force = mass * acceleration
                // => acceleration = force/mass
                ptoid1.vectorX += 0.03 * ptoid2.mass / (distance*distance) *
                (ptoid2.xPos - ptoid1.xPos) / distance;

                ptoid1.vectorY += 0.03 * ptoid2.mass / (distance*distance) *
                (ptoid2.yPos - ptoid1.yPos) / distance;
            }else{

                noCollision = false;
            }
        }

        if(noCollision){

            ptoid1.xPos += ptoid1.vectorX;
            ptoid1.yPos += ptoid1.vectorY;
        }else{

            planetoids.erase(planetoids.begin() + i);
        }
    }

    glutTimerFunc(1, gameUpdate, 0);
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

#endif // UPDATES_H_INCLUDED
