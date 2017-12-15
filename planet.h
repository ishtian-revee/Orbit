#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

// header files
#include "materials.h"

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

#endif // PLANET_H_INCLUDED
