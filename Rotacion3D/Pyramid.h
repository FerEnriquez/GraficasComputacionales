#include <GL/glut.h>
#include <stdlib.h>
#include "Matrix.h"
#ifndef PYRAMID_H
#define PYRAMID_H
class Pyramid{
    private :
        float point;
        float h;
        float points[5][3];
        Matrix mat;

    public:
        Pyramid();
        ~Pyramid();
        void setPoint(float x);
        void setAltura(float x);
        void printPoints();
        void draw();
        void Rotate(float d, int axis);
};
#endif
