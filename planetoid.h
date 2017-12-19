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

// planetoid object
struct PLANETOID ptoid;
// line object
struct LINE line;

std::vector<PLANETOID> planetoids;

/*
This function creates planetoids and initializes it's values
*/
void createPlanetoid(){

    ptoid.xPos = 0.0;
    ptoid.yPos = 0.0;
    ptoid.vectorX = 0.0;
    ptoid.vectorY = 0.0;
    ptoid.mass = 10000;
    ptoid.radius = 0.4;
    ptoid.color[0] = 0.91;
    ptoid.color[1] = 0.11;
    ptoid.color[2] = 0.39;
    planetoids.push_back(ptoid);
}

/*
This function will
*/
void addPlanetoid(float mass, float radius, bool randomColor, float vX, float vY){

    PLANETOID ptoid;

    ptoid.xPos = mX;
    ptoid.yPos = mY;
    ptoid.vectorX = vX / 30;    // to slow down the speed initially
    ptoid.vectorY = vY / 30;    // to slow down the speed initially
    ptoid.mass = mass;
    ptoid.radius = radius;

    if(randomColor){

        ptoid.color[0] = rand()%200 / 200.0;
		ptoid.color[1] = rand()%200 / 200.0;
		ptoid.color[2] = rand()%200 / 200.0;
    }else{

        // if planetoid is a larger one
        ptoid.color[0] = 0.40;
        ptoid.color[0] = 0.23;
        ptoid.color[0] = 0.72;
    }

    planetoids.push_back(ptoid);

    if(line.x1 != 0){

        line.x1 = line.x2 = line.y1 = line.y2 = 0;
    }
}

/*
This function will remove all the planetoids from the screen
*/
void removePlanetoids(){

    for(int i=0; i<planetoids.size(); i++){

        planetoids.pop_back();
    }
}

#endif // PLANETOID_H_INCLUDED
