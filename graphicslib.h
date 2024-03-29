#ifndef CSCIx229
#define CSCIx229

//  Include standard headers
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
// Include headers for my libraries
//#include "vector.h"

//  Include GLEW if you need access to advanced features
#ifdef USEGLEW
#include <GL/glew.h>
#endif
//  Include GLUT and GL
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//  Handy macros for cos and sin in degrees
#define PI 3.1415926
#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))

//  Functions provided by the library
void Print(const char* format , ...);
void Fatal(const char* format , ...);
void ErrCheck(const char* where);

#endif

