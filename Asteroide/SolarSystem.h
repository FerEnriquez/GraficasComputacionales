#include <GL/glut.h>
#include <GL/glext.h>
#include <stdlib.h>
#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
class SolarSystem{
    private :
    public:
        SolarSystem();
        ~SolarSystem();
        void drawAsteriods(float d, float x, float y, float z);
        void drawPlanets(float d, float x, float y, float z);
};
#endif
