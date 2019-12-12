#include <GL/glut.h>
#include <GL/glext.h>
#include <stdlib.h>
#include "SolarSystem.h"
#include "Asteroid.h"
#include "Planet.h"

SolarSystem::SolarSystem(){

}
SolarSystem::~SolarSystem(){

}
void SolarSystem:: drawPlanets(float d, float x, float y, float z){
    Planet p(1.0,0,0);
    p.Move(3,0,x,0);
}
void SolarSystem:: drawAsteriods(float d, float x, float y, float z){
    Asteroid a;
    a.RotateAxis(2,x,x,0,0);
    a.Move(1,x,x,0.0);

    Asteroid a1;
    a1.Move(1,x,x,0.0);
}
