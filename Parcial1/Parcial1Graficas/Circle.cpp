#include "Circle.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

Circle::Circle(){
    rat = 100;
    xc = 0;
    yc = 0;
}
Circle::~Circle(){
    rat = 0;
}
void Circle::setRadio(float r){
    rat = r;
}
void Circle::setCenter(float x, float y){
    xc = x;
    yc = y;
}
void Circle:: draw(){
    float angulo;
    int x = 0;
    int y = 0;
    for(angulo = 1; angulo <= 360; angulo ++){
        x = rat * sin(angulo);
        y = rat * cos(angulo);
        x += xc;
        y += yc;
        p.setValues(x,y);
        p.draw();
    }
}
int Circle::getPivotX(){
    return xc;
}
int Circle::getPivotY(){
    return yc;
}
void Circle::opTras(float x, float y){
    mat.clean();
    mat.Pivote(xc,yc);
    mat.Move(x,y);
    mat.BackPivote(xc,yc);
    xc += mat.newPointX(x,y);
    yc += mat.newPointY();
}
void Circle::opEsc(float x, float y){
    mat.clean();
    mat.Pivote(xc,yc);
    mat.Scale(x,y);
    mat.BackPivote(xc,yc);
    rat = mat.newPointX(x,y);
    mat.clean();
}
