#include <GL/glut.h>
#include <stdlib.h>
#include <stack>
#include "Matrix.h"
using namespace std;
#ifndef OPERATION_H
#define OPERATION_H
class Operation{
    private :
        Matrix mat;
        Matrix aux;
        float point[4];
        float axis[6];

    public:
        Operation();
        ~Operation();
        void undo();
        void save();
        void setPoint(float a, float b, float c);
        void Move(float x, float y, float z);
        void Scale(float x, float y, float z);
        void RotateAxis(float x, float y, float z);
        //Free rotation
        void setPoints(float x1, float y1, float z1, float x2, float y2, float z2);
        void RotateFree(float dg);
        float newPointX();
        float newPointY();
        float newPointZ();
};
#endif
