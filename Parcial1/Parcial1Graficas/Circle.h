#include <GL/glut.h>
#include <stdlib.h>
#include "Point.h"
#include "Matrix.h"
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{
    private:
        Point p;
        float rat;
        float xc;
        float yc;
        Matrix mat;
    public:
        Circle();
        ~Circle();
        void setRadio(float r);
        void setCenter(float x, float  y);
        int getPivotX();
        int getPivotY();
        void draw();
        void opTras(float x, float y);
        void opEsc(float a, float b);
        //void opRot(float d, float x, float y);
};
#endif
