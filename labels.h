#ifndef LABELS_H_INCLUDED
#define LABELS_H_INCLUDED

/*
This function draw the strings/labels of all planets and sun into the display screen
*/
void drawString(void *font, char *string){

    char *c;

    for(c=string; *c != '\0'; c++){

        glutBitmapCharacter(font, *c);      // setting the font and string to the bitmap character
    }
}

#endif // LABELS_H_INCLUDED
