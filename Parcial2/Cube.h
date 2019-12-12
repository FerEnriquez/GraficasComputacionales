#include <GL/glut.h>
#include <stdlib.h>
#include "Operation.h"
#ifndef CUBE_H
#define CUBE_H
class Cube{
    private :
        float edge;
        float h;
        float points[8][3];
        Operation op;

    public:
        Cube();
        ~Cube();
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
