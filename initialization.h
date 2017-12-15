#ifndef INITIALIZATION_H_INCLUDED
#define INITIALIZATION_H_INCLUDED

// header files
#include "materials.h"

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
This function initializes 3D rendering
*/
void initRendering(){

    glEnable(GL_DEPTH_TEST);            // enables depth comparisons and update the depth buffer
}

#endif // INITIALIZATION_H_INCLUDED
