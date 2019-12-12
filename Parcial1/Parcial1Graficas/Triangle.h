#include <GL/glut.h>
#include <stdlib.h>
#include "Line.h"
#include "Matrix.h"
#include "Point.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle{
    private:
        float vertex[3][2];
        Point pA;
        Point pB;
        Point pC;
        Matrix mat;

    public:
        Triangle();
        ~Triangle();
        void setVertex(float a, float b, float c, float d, float e, float f);
        void draw();
        void updatePoints();
        void printPoints();
        void opTras(float x, float y);
        void opEsc(float a, float b);
        void opRot(float d, float x, float y);
};
#endif
