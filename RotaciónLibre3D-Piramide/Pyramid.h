#include <GL/glut.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Operations.h"
#ifndef PYRAMID_H
#define PYRAMID_H
class Pyramid{
    private :
        float point;
        float h;
        float vertex[5][3];
        Operations op;
        Matrix mat;
    public:
        Pyramid();
        ~Pyramid();
        void printvertex();
        void draw();
        void Rotate(float d);
};
#endif
