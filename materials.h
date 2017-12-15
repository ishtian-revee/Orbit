#ifndef MATERIALS_H_INCLUDED
#define MATERIALS_H_INCLUDED

// global scope variables

// materials and light components
GLfloat material_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_shininess[] = {50.0};
GLfloat light_position[] = {1.0, 1.0, -0.8, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};

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
This function changes the color of the objects
*/
void changeColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a){

    model_ambient[0] = r;
	model_ambient[1] = g;
	model_ambient[2] = b;
	model_ambient[3] = a;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);      // specifies the ambient RGBA intensity of the entire scene
}

#endif // MATERIALS_H_INCLUDED
