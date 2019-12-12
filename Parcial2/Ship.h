#include <GL/glut.h>
#include <stdlib.h>
#include "Cube.h"
#include "Pyramid.h"
#ifndef SHIP_H
#define SHIP_H
class Ship{
    private :
        Pyramid py;
        Pyramid p1;
        Pyramid p2;
        Cube c;

    public:
        Ship();
        ~Ship();
        void draw();
        void save();
        void undo();
        void Move(float x, float y, float z);
        void Scale(float x, float y, float z);
        void RotateAxis(float x, float y, float z);
        void RotateFree(float d);
        void setAxis(float x1, float y1, float z1, float x2, float y2, float z2);
};
#endif
