#include <GL/glut.h>
#include <stdlib.h>
#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
    private :
        float mat[4][4];
        float point[4];
    public:
        Matrix();
        ~Matrix();
        void clean();
        void printMat();
        void setPoint(float a, float b, float c);
        void Multiply();
        void RotateX(float D);
        void RotateY(float D);
        void RotateZ(float D);
        float newPointX();
        float newPointY();
        float newPointZ();

};
#endif
