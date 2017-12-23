#ifndef STARS_H_INCLUDED
#define STARS_H_INCLUDED

// global scope variables
int numOfStars = 600;
int starXPos[600];
int starYPos[600];
int star2DxPos[130];
int star2DyPos[130];
float starZPos = 0.0f;

/*
This function will generate random position of x and y co-ordinate for stars
*/
void generateRandomPosition(){

    for(int i=0; i<numOfStars; i++){

        starXPos[i] = (float)((rand() % width)/ 120.0) * 30.0;      // generating random x co-ordinate of the stars
        starYPos[i] = (float)((rand() % height)/ 45.0) * 20.0;      // generating random y co-ordinate of the stars
    }

    // setting stars co ordinates randomly for  2D screen
    for(int i=0; i<130; i++){

        star2DxPos[i] = (rand()%width) - (width/2);                 // generating random x co-ordinate of the stars
        star2DyPos[i] = (rand()%height) - (height/2);               // generating random y co-ordinate of the stars
    }
}

/*
This function draws all the stars randomly over the screen
*/
void renderStars(){

    glPushMatrix();
    glPointSize(2.0);

    glBegin(GL_POINTS);

    for(int i=0; i<numOfStars; i++){

        glVertex3f(starXPos[i], starYPos[i], starZPos);             // rendering stars on the screen
    }

    glEnd();
    glPopMatrix();
}

/*
This function will render stars for 2D simulation screen
*/
void render2DStars(){

    int xPos, yPos;

    glColor3ub(245, 245, 245);
    glPointSize(2.4);

    for(int i=0; i<130; i++){

        glBegin(GL_POINTS);
        glVertex2f(star2DxPos[i], star2DyPos[i]);                 // rendering stars on the screen
        glEnd();
    }
}

#endif // STARS_H_INCLUDED
