#include <GL/glut.h>
#include <stdio.h>
#include "Planet.h"

Planet::Planet(float a, float b, float c){
    rad  = 0.5;
    r = a;
    g = b;
    b = c;
}
Planet::~Planet(){
}
void Planet::setRadius(float r1){
    rad = r1;
}
void Planet::drawTexture(){
}
void Planet::drawSolid(){
    glColor3f(r,g,b);
    glutSolidSphere(r,10,10);
    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
void Planet::draw(int cond){
    if(cond == 1){
        drawTexture();
    //} else if(cond == 2){
    //    drawInterpolated();
    } else if(cond == 3){
        drawSolid();
    }
}
void Planet::Move(int type, float x, float y, float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    draw(type);
    glPopMatrix();
}
void Planet::Scale(int type, float x, float y, float z){
    glPushMatrix();
    glScalef(x,y,z);
    draw(type);
    glPopMatrix();
}
void Planet::RotateAxis(int type, float d, float x, float y, float z){
    glPushMatrix();
    glRotatef(d,x,y,z);
    draw(type);
    glPopMatrix();
}





