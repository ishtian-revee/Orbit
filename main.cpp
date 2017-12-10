#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

#define RADIAN 180.0/3.141592

using namespace std;

// global scope

int width = 1000;
int height = 700;
int numOfStars = 500;
int starXPos[500];
int starYPos[500];
float starZPos = 0.0f;
//float cameraAngle = 0.0f;

// all planets structure
struct PLANET{

	float radius;
	float speed;
	float xPos;
	float yPos;
	float zPos;
	float orbitRadius;
	float orbitPos;
	float color[3];
};

// planet objects
struct PLANET mercury, venus, earth, mars, jupiter, saturn, urenus, neptune, pluto;

// materials and light components
GLfloat material_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_shininess[] = {50.0};
GLfloat light_position[] = {1.0, 1.0, -0.8, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};


// function prototypes
void init(void);
void display();
void createPlanets();
void setupMaterials();
void initRendering();
void generateRandomPosition();
void renderStars();
void renderPlanet(struct PLANET &planet);
void changeColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
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
This function initializes basic setups
*/
void init(void){

    glClearColor(0.0, 0.0, 0.0, 1.0);   // clears the color buffers
    setupMaterials();

    glEnable(GL_LIGHTING);              // enables lighting calculation
    glEnable(GL_LIGHT0);                // enables light source 0
    glEnable(GL_DEPTH_TEST);            // enables depth comparisons and update the depth buffer
    glEnable(GL_CULL_FACE);             // enables cull polygons based on their winding in window coordinates
    glFrontFace(GL_CCW);                // selects counterclockwise polygons as front-facing
    glShadeModel(GL_SMOOTH);            // causes the computed colors of vertices to be interpolated as the primitive is rasterized
}


/*
This function draws every 3D scenes to the display window
*/
void display(){

    // sets the bit plane area of the window to values previously selected by glClearColor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);             // switch to the drawing perspective
	glLoadIdentity();                       // reset the drawing perspective
	glRotatef(10.0, 1.0f, 0.0f, 0.0f);      // rotate the camera

	// produces a translation of camera by x y z co-ordinate by multiplying between this matrix and current matrix
	glTranslatef(0.0f, -2.0f, -17.0f);

	glPushMatrix();                         // save the transformations performed thus far
	glRotatef(-60.0, 1.0f, 0.0f,0.0f);

	// rendering stars
	glPushMatrix();
	glTranslatef(-95.0f, -140.0f, -50.0f);  // saving the transformations of the stars projection
	renderStars();
	glPopMatrix();

	// rendering the sun
	glPushMatrix();
	changeColor(0.99, 0.84, 0.20, 1.0);        // setting sun color
	glBegin(GL_LINES);
	glutSolidSphere(0.5f, 45, 45);
	glEnd();
	glPopMatrix();

	// rendering all the planets
	renderPlanet(mercury);
	renderPlanet(venus);
	renderPlanet(earth);
	renderPlanet(mars);
	renderPlanet(jupiter);
	renderPlanet(saturn);
	renderPlanet(urenus);
	renderPlanet(neptune);
	renderPlanet(pluto);

    glPopMatrix();
	glutSwapBuffers();
}

/*
This function creates all the planets and initializes it's values
*/
void createPlanets(){

    // planet mercury
	mercury.radius = 0.11;
	mercury.speed = 0.00028;
	mercury.xPos = 0.0;
	mercury.yPos = 0.0;
	mercury.zPos = 0.0;
	mercury.orbitRadius = 1.08;
	mercury.orbitPos = 180.0;
	mercury.color[0] = 0.75;
	mercury.color[1] = 0.30;
	mercury.color[2] = 0.16;

	// planet venus
	venus.radius = 0.15;
	venus.speed = 0.00022;
	venus.xPos = 0.0;
	venus.yPos = 0.0;
	venus.zPos = 0.0;
	venus.orbitRadius = 1.30;
	venus.orbitPos = 15.0;
	venus.color[0] = 0.55;
	venus.color[1] = 0.29;
	venus.color[2] = 0.21;

	// planet earth
	earth.radius = 0.16;
	earth.speed = 0.00020;
	earth.xPos = 0.0;
	earth.yPos = 0.0;
	earth.zPos = 0.0;
	earth.orbitRadius = 1.52;
	earth.orbitPos = 90.0;
	earth.color[0] = 0.0;
	earth.color[1] = 0.73;
	earth.color[2] = 0.83;

	// planet mars
	mars.radius = 0.12;
	mars.speed = 0.00017;
	mars.xPos = 0.0;
	mars.yPos = 0.0;
	mars.zPos = 0.0;
	mars.orbitRadius = 1.74;
	mars.orbitPos = 120.0;
	mars.color[0] = 0.93;
	mars.color[1] = 0.32;
	mars.color[2] = 0.31;

	// planet jupiter
	jupiter.radius = 0.29;
	jupiter.speed = 0.00012;
	jupiter.xPos = 0.0;
	jupiter.yPos = 0.0;
	jupiter.zPos = 0.0;
	jupiter.orbitRadius = 1.96;
	jupiter.orbitPos = 290.0;
	jupiter.color[0] = 1.0;
	jupiter.color[1] = 0.65;
	jupiter.color[2] = 0.14;

	// planet saturn
	saturn.radius = 0.28;
	saturn.speed = 0.00009;
	saturn.xPos = 0.0;
	saturn.yPos = 0.0;
	saturn.zPos = 0.0;
	saturn.orbitRadius = 2.18;
	saturn.orbitPos = 60.0;
	saturn.color[0] = 0.84;
	saturn.color[1] = 0.76;
	saturn.color[2] = 0.20;

	// planet uranus
	urenus.radius = 0.22;
	urenus.speed = 0.00007;
	urenus.xPos = 0.0;
	urenus.yPos = 0.0;
	urenus.zPos = 0.0;
	urenus.orbitRadius = 2.40;
	urenus.orbitPos = 15.0;
	urenus.color[0] = 0.39;
	urenus.color[1] = 0.70;
	urenus.color[2] = 0.96;

	//planet neptune
	neptune.radius = 0.21;
	neptune.speed = 0.00005;
	neptune.xPos = 0.0;
	neptune.yPos = 0.0;
	neptune.zPos = 0.0;
	neptune.orbitRadius = 2.62;
	neptune.orbitPos = 350.0;
	neptune.color[0] = 0.24;
	neptune.color[1] = 0.31;
	neptune.color[2] = 0.70;

	// planet pluto
	pluto.radius = 0.09;
	pluto.speed = 0.00002;
	pluto.xPos = 0.0;
	pluto.yPos = 0.0;
	pluto.zPos = 0.0;
	pluto.orbitRadius = 2.84;
	pluto.orbitPos = 200.0;
	pluto.color[0] = 0.93;
	pluto.color[1] = 0.60;
	pluto.color[2] = 0.60;
}

/*
This function handles material characteristics, lights position and intensity
*/
void setupMaterials(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);       // specifies the ambient RGBA reflectance of the material
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);     // specifies the specular RGBA reflectance of the material
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);   // specifies the RGBA specular exponent of the material
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);          // specifies the position of the light in homogeneous object coordinates
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);      // specifies the ambient RGBA intensity of the entire scene
}

/*
This function initializes 3D rendering
*/
void initRendering(){

    glEnable(GL_DEPTH_TEST);    // enables depth comparisons and update the depth buffer
}

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

/*
This function draws all the planets according to their given inputs
*/
void renderPlanet(struct PLANET &planet){

    // setting planet's position along with orbit radius
    planet.xPos = planet.orbitRadius * planet.orbitRadius * cos(planet.orbitPos * RADIAN);
    planet.yPos = planet.orbitRadius * planet.orbitRadius * sin(planet.orbitPos * RADIAN);

    glPushMatrix();         // pushes the current matrix stack down by one, duplicating the current matrix
    changeColor(planet.color[0], planet.color[1], planet.color[2], 1.0);

    // produces a translation of planets by x y z co-ordinate by multiplying between this matrix and current matrix
    glTranslatef(planet.xPos, planet.yPos, planet.zPos);
    glBegin(GL_LINES);
    glutSolidSphere(planet.radius, 30, 30);     // renders a sphere centered at the modeling coordinates origin of the specified radius
    glEnd();

    glPopMatrix();          // pops the current matrix stack, replacing the current matrix with the one below it on the stack

    planet.orbitPos += planet.speed;            // planet's position changing along with it's speed
    // if the planet's position reaches to 360 it will start from 0 again
    if(planet.orbitPos >= 360.0){

        planet.orbitPos = 0.0;
    }
}

/*
This function changes the color of the objects
*/
void changeColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a){

    model_ambient[0] = r;
	model_ambient[1] = g;
	model_ambient[2] = b;
	model_ambient[3] = a;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);      // specifies the ambient RGBA intensity of the entire scene
}

/*
This function updates the camera angles
*/
void update(int value){

//    cameraAngle += 2.0;
//
//    if(cameraAngle >= 360.0){
//
//        cameraAngle = 0.0;
//    }

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
