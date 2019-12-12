#include <GL/glut.h>
#include <stdlib.h>
#ifndef OPERATIONS_H
#define OPERATIONS_H
class Operations{
    private :
        float a,b,c,d;
        float grados;
        float pA[3];
        float pB[3];
    public:
        Operations();
        ~Operations();
        void setGrados(float g);
        void setPoints(float x1, float y1, float z1, float x2, float y2, float z2);
        void setAxis();
        float A();
        float B();
        float C();
        float D();
};
#endif
