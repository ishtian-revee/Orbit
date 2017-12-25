#ifndef PLANETOID_H_INCLUDED
#define PLANETOID_H_INCLUDED

// global scope variables
int mX, mY;

// planetoid structure
struct PLANETOID{

    float xPos;
    float yPos;
    float radius;
    float vectorX;
    float vectorY;
    float mass;
    float color[3];
};

// planetoid dragging line structure
struct LINE{

    float x1;
    float x2;
    float y1;
    float y2;
};

// line object
struct LINE line;

std::vector<PLANETOID> planetoids;

/*
This function creates first stable planetoid and initializes it's values
*/
void createPlanetoid(){

    // planetoid object
    struct PLANETOID ptoid;

    ptoid.xPos = 0.0;
    ptoid.yPos = 0.0;
    ptoid.vectorX = 0.0;
    ptoid.vectorY = 0.0;
    ptoid.mass = 10000;
    ptoid.radius = 15;
    ptoid.color[0] = 0.91;
    ptoid.color[1] = 0.11;
    ptoid.color[2] = 0.39;
    planetoids.push_back(ptoid);    // add a planetoid object at the end of the vector
}

/*
This function will add planetoids when a mouse event occurs
*/
void addPlanetoid(float mass, float radius, bool randomColor, float vX, float vY){

    PLANETOID ptoid;

    ptoid.xPos = mX;
    ptoid.yPos = mY;
    ptoid.vectorX = vX / 30;    // to slow down the speed initially
    ptoid.vectorY = vY / 30;    // to slow down the speed initially
    ptoid.mass = mass;
    ptoid.radius = radius;

    // if planetoid is said to have random colors
    if(randomColor){

        planetoidCount++;   // planetoids counter increasing

        ptoid.color[0] = rand()%200 / 200.0;
		ptoid.color[1] = rand()%200 / 200.0;
		ptoid.color[2] = rand()%200 / 200.0;
    }else{

        // if planetoid is a larger one then set it's default color
        ptoid.color[0] = 0.91;
        ptoid.color[1] = 0.11;
        ptoid.color[2] = 0.39;
    }

    planetoids.push_back(ptoid);    // add planetoid objects at the end of the vector

    if(line.x1 != 0){

        line.x1 = line.x2 = line.y1 = line.y2 = 0;
    }
}

/*
This function will remove all the planetoids from the screen
*/
void removePlanetoids(){

    for(int i=0; i<planetoids.size(); i++){

        planetoids.pop_back();      // removes last planetoid object from the vector
    }
}

#endif // PLANETOID_H_INCLUDED
