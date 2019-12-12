#include <GL/glut.h>
#include <stdlib.h>
#include "Operation.h"
#ifndef PYRAMID_H
#define PYRAMID_H
class Pyramid{
    private :
        float edge;
        float h;
        float points[5][3];
        Operation op;

    public:
        Pyramid();
        ~Pyramid();
        void draw(float a, float b, float c);
        void printPoints();
        void setPoint(float p);
        void save();
        void undo();
        void Move(float a, float b, float c);
        void Scale(float a, float b, float c);
        void RotateAxis(float a, float b, float c);
        void RotateFree(float d);
        void setPoints(float x1, float y1, float z1, float x2, float y2, float z2);
};
#endif
