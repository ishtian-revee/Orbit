#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

#define RADIAN 180.0/3.141592

using namespace std;

// global scope

int width = 1024;
int height = 768;
float cameraAngle = 0.0f;

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
GLfloat light_position[] = {1.0, 1.0, -1.0, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};


// function prototypes
void init(void);
void display();
void createPlanets();
void setupMaterials();
void initRendering();
void renderPlanet(struct PLANET &planet);
void changeColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void update(int value);
void handleResize(int width, int height);

// main function
int main(int argc, char** argv){

    createPlanets();

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

	// produces a translation by x y z co-ordinate by multiplying between this matrix and current matrix
	glTranslatef(0.0f, -1.0f, -14.0f);

	glPushMatrix();                         // save the transformations performed thus far
	glRotatef(-60.0, 1.0f, 0.0f,0.0f);

	// rendering the sun
	glPushMatrix();
	changeColor(0.9, 0.4, 0.2, 1.0);        // setting sun color
	glBegin(GL_LINES);
	glutSolidSphere(0.4f, 30, 30);
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
	mercury.radius = 0.1;
	mercury.speed = 0.00025;
	mercury.xPos = 0.0;
	mercury.yPos = 0.0;
	mercury.zPos = 0.0;
	mercury.orbitRadius = 0.8;
	mercury.orbitPos = 0;
	mercury.color[0] = 0.8;
	mercury.color[1] = 0.4;
	mercury.color[2] = 0.2;

	// planet venus
	venus.radius = 0.12;
	venus.speed = 0.00023;
	venus.xPos = 0.0;
	venus.yPos = 0.0;
	venus.zPos = 0.0;
	venus.orbitRadius = 1.0;
	venus.orbitPos = 180.0;
	venus.color[0] = 0.8;
	venus.color[1] = 0.8;
	venus.color[2] = 0.8;

	// planet earth
	earth.radius = 0.14;
	earth.speed = 0.00019;
	earth.xPos = 0.0;
	earth.yPos = 0.0;
	earth.zPos = 0.0;
	earth.orbitRadius = 1.2;
	earth.orbitPos = 90.0;
	earth.color[0] = 0.4;
	earth.color[1] = 0.6;
	earth.color[2] = 0.8;

	// planet mars
	mars.radius = 0.13;
	mars.speed = 0.00017;
	mars.xPos = 0.0;
	mars.yPos = 0.0;
	mars.zPos = 0.0;
	mars.orbitRadius = 1.4;
	mars.orbitPos = 270.0;
	mars.color[0] = 0.8;
	mars.color[1] = 0.2;
	mars.color[2] = 0.2;

	// planet jupiter
	jupiter.radius = 0.3;
	jupiter.speed = 0.00012;
	jupiter.xPos = 0.0;
	jupiter.yPos = 0.0;
	jupiter.zPos = 0.0;
	jupiter.orbitRadius = 1.7;
	jupiter.orbitPos = 45.0;
	jupiter.color[0] = 0.8;
	jupiter.color[1] = 0.4;
	jupiter.color[2] = 0.3;

	// planet saturn
	saturn.radius = 0.26;
	saturn.speed = 0.00009;
	saturn.xPos = 0.0;
	saturn.yPos = 0.0;
	saturn.zPos = 0.0;
	saturn.orbitRadius = 2.0;
	saturn.orbitPos = 135.0;
	saturn.color[0] = 0.8;
	saturn.color[1] = 0.4;
	saturn.color[2] = 0.8;

	// planet urenus
	urenus.radius = 0.12;
	urenus.speed = 0.00007;
	urenus.xPos = 0.0;
	urenus.yPos = 0.0;
	urenus.zPos = 0.0;
	urenus.orbitRadius = 2.2;
	urenus.orbitPos = 315.0;
	urenus.color[0] = 0.8;
	urenus.color[1] = 0.2;
	urenus.color[2] = 0.4;

	//planet neptune
	neptune.radius = 0.12;
	neptune.speed = 0.00005;
	neptune.xPos = 0.0;
	neptune.yPos = 0.0;
	neptune.zPos = 0.0;
	neptune.orbitRadius = 2.4;
	neptune.orbitPos = 225.0;
	neptune.color[0] = 0.8;
	neptune.color[1] = 0.4;
	neptune.color[2] = 0.2;

	// planet pluto
	pluto.radius = 0.1;
	pluto.speed = 0.00002;
	pluto.xPos = 0.0;
	pluto.yPos = 0.0;
	pluto.zPos = 0.0;
	pluto.orbitRadius = 2.6;
	pluto.orbitPos = 0.0;
	pluto.color[0] = 0.2;
	pluto.color[1] = 0.2;
	pluto.color[2] = 0.2;
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
This function draws all the planets according to their given inputs
*/
void renderPlanet(struct PLANET &planet){

    // setting planet's position along with orbit radius
    planet.xPos = planet.orbitRadius * planet.orbitRadius * cos(planet.orbitPos * RADIAN);
    planet.yPos = planet.orbitRadius * planet.orbitRadius * sin(planet.orbitPos * RADIAN);

    glPushMatrix();         // pushes the current matrix stack down by one, duplicating the current matrix
    changeColor(planet.color[0], planet.color[1], planet.color[2], 1.0);

    // produces a translation by x y z co-ordinate by multiplying between this matrix and current matrix
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

    cameraAngle += 2.0;

    if(cameraAngle >= 360.0){

        cameraAngle = 0.0;
    }

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
