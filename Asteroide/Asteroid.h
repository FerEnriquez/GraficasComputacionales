#include <GL/glut.h>
#include <stdlib.h>
#ifndef ASTERIOD_H
#define ASTERIOD_H
class Asteroid{
    private :
        float p;
    public:
        Asteroid();
        ~Asteroid();
        void draw(int cond);
        void drawTexture();
        void drawInterpolated();
        void drawSolid();
        void setHeight(float h);
        void Move(int type, float x, float y, float z);
        void Scale(int type, float x, float y, float z);
        void RotateAxis(int type,float d, float x, float y, float z);
};
#endif
