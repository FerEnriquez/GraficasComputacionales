#include <GL/glut.h>
#include <stdlib.h>
#include "Line.h"
#include "Matrix.h"
#include "Point.h"
#ifndef SQUARE_H
#define SQUARE_H
class Square{
    private:
        float vertex[4][2];
        Point pA;
        Point pB;
        Point pC;
        Point pD;
        Matrix mat;

    public:
        Square();
        ~Square();
        void setVertex(float a, float b, float c, float d, float e, float f, float g, float h);
        void draw();
        void updatePoints();
        void printPoints();
        void opTras(float x, float y);
        void opEsc(float a, float b);
        void opRot(float d, float x, float y);
};
#endif
