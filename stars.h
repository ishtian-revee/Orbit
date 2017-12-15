#ifndef STARS_H_INCLUDED
#define STARS_H_INCLUDED

// global scope variables

int width = 1000;
int height = 700;
int numOfStars = 500;
int starXPos[500];
int starYPos[500];
float starZPos = 0.0f;

/*
This function will generate random position of x and y co-ordinate for stars
*/
void generateRandomPosition(){

    for(int i=0; i<numOfStars; i++){

        starXPos[i] = (float)((rand() % width)/ 120.0) * 30.0;      // generating random x co-ordinate of the stars
        starYPos[i] = (float)((rand() % height)/ 45.0) * 20.0;      // generating random y co-ordinate of the stars
    }
}

/*
This function draws all the stars randomly over the screen
*/
void renderStars(){

    glPushMatrix();
    glPointSize(2.5);

    glBegin(GL_POINTS);
	//changeColor(1.0, 1.0, 1.0, 1.0);                              // setting stars color

    for(int i=0; i<numOfStars; i++){

        glVertex3f(starXPos[i], starYPos[i], starZPos);             // rendering stars on the screen
    }

    glEnd();
    glPopMatrix();
}

#endif // STARS_H_INCLUDED
