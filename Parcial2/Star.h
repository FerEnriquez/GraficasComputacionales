#include <GL/glut.h>
#include <stdlib.h>
#include "Cube.h"
#include "Pyramid.h"
#ifndef STAR_H
#define STAR_H
class Star{
    private :
        Cube c;
        Pyramid p1;
        Pyramid p2;
        Pyramid p3;
        Pyramid p4;

    public:
        Star();
        ~Star();
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
