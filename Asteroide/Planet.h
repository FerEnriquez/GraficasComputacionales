#include <GL/glut.h>
#include <stdlib.h>
#ifndef PLANET_H
#define PLANET_H
class Planet{
    private :
        float rad;
        float r;
        float g;
        float b;
    public:
        Planet(float a, float b, float c);
        ~Planet();
        void draw(int cond);
        void drawTexture();
        void drawSolid();
        void setRadius(float r1);
        void Move(int type, float x, float y, float z);
        void Scale(int type, float x, float y, float z);
        void RotateAxis(int type, float d, float x, float y, float z);
};
#endif
