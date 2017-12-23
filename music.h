#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED

#include <stdio.h>
#include <IrrKlang/irrKlang.h>

// include console I/O methods (conio.h for windows)
#if defined(WIN32)
    #include <conio.h>
#else
    #include "../common/conio.h"
#endif

using namespace irrklang;

int playMusic(){

//    // start the sound engine with default parameters
//    ISoundEngine* engine = createIrrKlangDevice();
//
//    if (!engine)
//        printf("Could not startup engine\n");
//        return 0; // error starting up the engine
//
//    // play some sound stream, looped
//    engine->play2D("/music/space.mp3", true);
}

#endif // MUSIC_H_INCLUDED
