#include <GL/glut.h>
#include <stdlib.h>
#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
    private :
        float mat[4][4];
    public:
        Matrix();
        ~Matrix();
        void clean();
        void printMat();
        void Multiply(float mt[4][4]);
        void t(float a, float b, float c);
        void invT(float a, float b, float c);
        void RX(float b, float c, float d);
        void InvRX(float b, float c, float d);
        void RY(float a, float d);
        void InvRY(float a, float d);
        void RZ(float d);
        void getPoints(float a, float b, float c);
        float newX();
        float newY();
        float newZ();

};
#endif
